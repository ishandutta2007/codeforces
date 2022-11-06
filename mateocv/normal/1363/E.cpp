#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MAXN=200005;

vector<ll> g[MAXN];

ll vis[MAXN],p[MAXN];

void bfs() {
	queue<ll>q;
	vis[0]=1;
	q.push(0);
	p[0]=-1;
	while(q.size()) {
		int t=q.front(); q.pop();
		for(auto i:g[t]) {
			if(!vis[i]) {
				vis[i]=1;
				q.push(i);
				p[i]=t;
			}
		}
	}
}

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper min
const pair<ll,ll> NEUT={9e18,9e18};
struct STree { // [cerrado-abierto)
    vector<pair<ll,ll>> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, pair<ll,ll> v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    pair<ll,ll> query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, pair<ll,ll> v){upd(1,0,n,p,v);}
    pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

int main(){FIN;
	ll n; cin>>n;
	ll a[n],b[n],c[n];
	fore(i,0,n)cin>>a[i]>>b[i]>>c[i];
	ll tot=0;
	fore(i,0,n)tot+=b[i]-c[i];
	if(tot!=0){
		cout<<-1;
		return 0;
	}
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	mset(vis,0);
	STree st(n);
	fore(i,0,n)st.upd(i,{a[i],i});
	ll res=0;
	pair<ll,ll> pr[n];
	fore(i,0,n){
		if(b[i]!=c[i])pr[i]={b[i],c[i]};
		else pr[i]={0,0};
	}
	while(1){
		auto q=st.query(0,n);
		if(q==NEUT)break;
		vector<ll> v,s;
		v.pb(q.snd);
		s.pb(q.snd);
		vis[q.snd]=1;
		pair<ll,ll> tot={0,0};
		//res+=(b[q.snd]!=c[q.snd])*q.fst;
		tot.fst+=pr[q.snd].fst;
		tot.snd+=pr[q.snd].snd;
		while(SZ(s)){
			ll bb=s.back();
			s.pop_back();
			for(auto i:g[bb]){
				if(i!=p[bb]&&!vis[i]){
					vis[i]=1;
					v.pb(i);
					s.pb(i);
					//res+=(b[i]!=c[i])*q.fst;
					tot.fst+=pr[i].fst;
					tot.snd+=pr[i].snd;
				}
			}
		}
		ll mini=min(tot.fst,tot.snd);
		res+=mini*q.fst;
		if(tot.fst>mini){
			assert(p[q.snd]!=-1);
			pr[p[q.snd]].fst+=tot.fst-mini;
		}
		if(tot.snd>mini){
			assert(p[q.snd]!=-1);
			pr[p[q.snd]].snd+=tot.snd-mini;
		}
		for(auto i:v)st.upd(i,NEUT);
	}
	cout<<2ll*res;
	
	return 0;
}