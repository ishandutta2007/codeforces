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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<pair<int,ll> > g[200005];
ll d[200005];
int n,m;
priority_queue<pair<ll,int> > q;

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;ll c;
		scanf("%d%d%lld",&x,&y,&c);
		g[x].pb(mp(y,2*c));g[y].pb(mp(x,2*c));
	}
	fore(i,1,n+1){
		ll a;
		scanf("%lld",&a);
		g[0].pb(mp(i,a));
	}
	memset(d,-1,sizeof(d));d[0]=0;
	q.push(mp(0LL,0));
	while(!q.empty()){
		auto p=q.top();q.pop();
		int x=p.snd;
		if(d[x]!=-p.fst)continue;
		for(auto p:g[x]){
			int y=p.fst;ll c=p.snd;
			if(d[y]<0||d[x]+c<d[y]){
				d[y]=d[x]+c;
				q.push(mp(-d[y],y));
			}
		}
	}
	fore(i,1,n+1)printf("%lld%c",d[i]," \n"[i==n]);
	return 0;
}