#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=100100;
typedef vector<int> VI;
VI es[N];
#define F(x) for(VI::iterator it=es[x].begin();it!=es[x].end();it++)

int f[N];
int d[N];
int lim;
int sd[N];
int sdc[N];
bool ban[N]={false};
void dfs1(int x,int fa=-1,int dep=0){
	f[x]=fa;
	d[x]=dep;
	sd[x]=0;
	sdc[x]=0;
	F(x)if(*it!=fa&&!ban[*it]){
		dfs1(*it,x,dep+1);
		sd[x]=max(sd[x],sd[*it]);
		if(sd[*it]>=lim){
			sdc[x]++;
		}
	}
	sd[x]++;
}

int n,a,b;
bool solve(){
	lim=INT_MAX;
	dfs1(a);
	int w;
	int len=0;
	for(int i=b;i!=a;i=f[i]){
		len++;
		if(f[i]==a){
			w=i;
		}
	}
	for(int i=1;i<=n;i++){
		d[i]=-1;
	}
	ban[w]=true;
	dfs1(a);
	ban[w]=false;
	int mx=a;
	for(int i=1;i<=n;i++){
		if(d[i]>d[mx])mx=i;
	}
	int md=d[mx];
	a=mx;
	dfs1(a);
	while(md--){
		b=f[b];
	}
	int dr=f[b];
	// cerr<<a<<" "<<b<<" "<<dr<<endl;
	for(int i=1;i<=n;i++){
		sdc[i]=-1;
	}
	ban[dr]=true;
	lim=len;
	dfs1(b);
	ban[dr]=false;
	for(int i=1;i<=n;i++){
		// if(sdc[i]!=-1)cerr<<i<<" "<<sd[i]<<" "<<sdc[i]<<endl;
		if(sdc[i]>=2){
			return true;
		}
	}
	return false;
}

void work(){
	cin>>n>>a>>b;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		es[u].push_back(v);
		es[v].push_back(u);
	}
	bool ans=solve();
	for(int i=0;i<5;i++){
		swap(a,b);
		ans|=solve();
	}
	puts(ans?"YES":"NO");
	for(int i=1;i<=n;i++)es[i].clear();
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)work();
	return 0;
}

/*
16 15 12
1 2
2 3
1 4
4 5
5 6
6 7
4 8
8 9
8 10
10 11
11 12
11 13
13 14
10 15
15 16

(1
	(2
		(3)
	(4
		(5
			(6
				(7)
	(8
		(9)
		(10
			(11
				(12*)
				(13
					(14)
			(15*
				(16)
*/