#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

vector<int> g[200005];
int ex[200005],ey[200005];
int n,m,k;
int d[200005];
queue<int> q;
vector<int> w[200005];
vector<vector<int> > ans;
vector<int> t;

void go(int x){
	if(SZ(ans)==k)return;
	if(x==n){
		ans.pb(t);
		return;
	}
	for(int i:w[x]){
		t[i]=1;
		go(x+1);
		t[i]=0;
		if(SZ(ans)==k)return;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,m){
		scanf("%d%d",ex+i,ey+i);
		ex[i]--;ey[i]--;
		g[ex[i]].pb(i);
		g[ey[i]].pb(i);
	}
	memset(d,-1,sizeof(d));
	d[0]=0;q.push(0);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i:g[x]){
			int y=ex[i]^ey[i]^x;
			if(d[y]<0){
				d[y]=d[x]+1;
				q.push(y);
			}
		}
	}
	fore(i,0,m){
		if(d[ey[i]]==d[ex[i]]+1)w[ey[i]].pb(i);
		if(d[ex[i]]==d[ey[i]]+1)w[ex[i]].pb(i);
	}
	t=vector<int>(m);
	go(1);
	printf("%d\n",SZ(ans));
	for(auto v:ans){
		fore(i,0,m)printf("%d",v[i]);
		puts("");
	}
	return 0;
}