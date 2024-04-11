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

int n,m;
ll a[200005],r;
vector<pair<int,ll> > g[200005];
set<pair<ll,int> > w;
priority_queue<pair<ll,int> > q;
bool v[200005];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%lld",a+i),w.insert(mp(a[i],i));
	fore(_,0,m){
		int x,y;ll c;
		scanf("%d%d%lld",&x,&y,&c);x--;y--;
		g[x].pb(mp(y,c));
		g[y].pb(mp(x,c));
	}
	q.push(mp(0,0));
	ll mn=(1LL<<60);
	fore(_,0,n){
		while(!q.empty()&&v[q.top().snd])q.pop();
		int x;
		if(q.empty()||-q.top().fst>mn+w.begin()->fst){
			r+=mn+w.begin()->fst;
			x=w.begin()->snd;
		}
		else {
			auto p=q.top();q.pop();
			r+=-p.fst;
			x=p.snd;
		}
		v[x]=true;
		w.erase(mp(a[x],x));
		mn=min(mn,a[x]);
		for(auto p:g[x])if(!v[p.fst])q.push(mp(-p.snd,p.fst));
	}
	printf("%lld\n",r);
	return 0;
}