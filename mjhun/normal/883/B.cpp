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

void perdi(){puts("-1");exit(0);}

vector<int> g[200005],gi[200005];
int r[200005];
int dp0[200005];
int dp1[200005];
int n,m,k;
priority_queue<pair<int,int> > q;
vector<int> w[200005];

int f0(int x){
	if(dp0[x]>=0)return dp0[x];
	if(dp0[x]==-2)perdi();
	if(r[x]>=0)return dp0[x]=r[x];
	dp0[x]=-2;
	int rr=0;
	for(int y:g[x])rr=max(rr,f0(y)+1);
	if(rr>=k)perdi();
	return dp0[x]=rr;
}

int f1(int x){
	if(dp1[x]>=0)return dp1[x];
	if(r[x]>=0)return dp1[x]=r[x];
	int rr=k-1;
	for(int y:gi[x])rr=min(rr,f1(y)-1);
	if(rr<0)perdi();
	return dp1[x]=rr;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n)scanf("%d",r+i),r[i]--;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);gi[y].pb(x);
	}
	memset(dp0,-1,sizeof(dp0));memset(dp1,-1,sizeof(dp1));
	fore(i,0,n)w[f0(i)].pb(i);
	fore(i,0,n)deb("%d %d %d\n",i+1,f0(i)+1,f1(i)+1);
	fore(i,0,k){
		for(int x:w[i])q.push(mp(-f1(x),x));
		while(!q.empty()&&-q.top().fst<i)q.pop();
		if(q.empty())deb("asd %d\n",i+1	),perdi();
		r[q.top().snd]=i;q.pop();
	}
	fore(i,0,n)if(r[i]<0)r[i]=f1(i);
	fore(x,0,n)for(int y:g[x])if(r[x]<=r[y])perdi();
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r[i]+1);
	}
	puts("");
	return 0;
}