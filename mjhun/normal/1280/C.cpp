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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;
ll r0,r1;
vector<pair<int,ll> > g[200005];
ll q[200005],a[200005];

void dfs(int x, int f){
	q[x]=1;
	for(auto p:g[x])if(p.fst!=f){
		int y=p.fst;ll c=p.snd;
		a[y]=c;
		dfs(y,x);
		q[x]+=q[y];
	}
}

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d",&n);n*=2;
		fore(i,0,n)g[i].clear();
		r0=r1=0;
		fore(_,0,n-1){
			int x,y;ll c;
			scanf("%d%d%lld",&x,&y,&c);x--;y--;
			g[x].pb(mp(y,c));g[y].pb(mp(x,c));
		}
		dfs(0,-1);
		fore(i,0,n){
			if(q[i]%2)r0+=a[i];
			r1+=a[i]*min(q[i],n-q[i]);
		}
		printf("%lld %lld\n",r0,r1);
	}
	return 0;
}