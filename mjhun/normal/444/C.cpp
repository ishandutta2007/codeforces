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


ll st[1<<19],lazy[1<<19];
void st_push(int k, int s, int e){
	if(!lazy[k])return;
	st[k]+=(e-s)*lazy[k];
	if(e-s>1){
		lazy[2*k]+=lazy[k];
		lazy[2*k+1]+=lazy[k];
	}
	lazy[k]=0;
}
void st_upd(int k, int s, int e, int a, int b, int v){
	st_push(k,s,e);
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b){
		lazy[k]+=v;
		st_push(k,s,e);
		return;
	}
	int m=(s+e)/2;
	st_upd(2*k,s,m,a,b,v);st_upd(2*k+1,m,e,a,b,v);
	st[k]=st[2*k]+st[2*k+1];
}
ll st_query(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return 0;
	st_push(k,s,e);
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	return st_query(2*k,s,m,a,b)+st_query(2*k+1,m,e,a,b);
}

set<pair<pair<int,int>,int> > w;
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)w.insert(mp(mp(i,i+1),i));
	while(m--){
		int t,s,e;
		scanf("%d%d%d",&t,&s,&e);s--;
		if(t==1){
			int x;
			scanf("%d",&x);x--;
			auto it=w.lower_bound(mp(mp(s+1,-1),-1));--it;
			assert(it->fst.fst<=s&&it->fst.snd>s);
			vector<pair<pair<int,int>,int> > a={{{s,e},x}},d;
			if(s>it->fst.fst)a.pb(mp(mp(it->fst.fst,s),it->snd));
			while(it!=w.end()&&it->fst.fst<e){
				st_upd(1,0,n,max(s,it->fst.fst),min(e,it->fst.snd),abs(it->snd-x));
				d.pb(*it);
				++it;
			}
			--it;
			if(it->fst.snd>e)a.pb(mp(mp(e,it->fst.snd),it->snd));
			for(auto p:d)w.erase(p);
			for(auto p:a)w.insert(p);
		}
		else printf("%lld\n",st_query(1,0,n,s,e));
	}
	return 0;
}