#include<bits/stdc++.h>
#define int long long
const int N=2050,mod=998244353;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n,m;
int w[N];
int in[N];
bool is[N][N];
int mx[N];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)hd[i]=0,in[i]=0,S=0,mx[i]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		is[i][j]=0;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		for(int j=1;j<=min(w[i],n);j++)
			is[i][j]=1;
		mx[i]=w[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		add(x,y); 
		in[y]++;
	}
	vector<int> a;
	queue<int> q; 
	for(int i=1;i<=n;i++){
		if(in[i]==0)
			q.push(i); 
	}
	while(q.size()){
		int nw=q.front();q.pop();
		a.push_back(nw);
		fore(nw){
			in[_to]--;
			if(in[_to]==0)q.push(_to);
		}
	}
	for(auto x:a){
		fore(x){
			int nw=0;
			for(int j=1;j<n;j++){
				if(!is[x][j])continue;
				nw=max(nw,j+1);
				while(nw<=n&&is[_to][nw])nw++;
				if(nw>n)mx[_to]++;
				else is[_to][nw]=1,mx[_to]=max(mx[_to],nw);
			}
			mx[_to]+=max(mx[x]-n+1,0ll);
			while(mx[_to]>=2*mod)mx[_to]-=mod;
		}
	}
	cout<<(mx[a[n-1]]%mod)<<endl;
}


main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}