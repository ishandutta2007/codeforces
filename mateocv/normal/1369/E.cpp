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

vector<ll> g[100005];

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper min
const ll INF=9e18;
const pair<ll,ll> NEUT={INF,INF};
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

vector<pair<ll,ll>> ed;
vector<ll> ord;
ll u[100005];

bool cmp(ll i, ll j){
	return min(u[ed[i].fst],u[ed[i].snd])<min(u[ed[j].fst],u[ed[j].snd])||(min(u[ed[i].fst],u[ed[i].snd])==min(u[ed[j].fst],u[ed[j].snd])&&max(u[ed[i].fst],u[ed[i].snd])<max(u[ed[j].fst],u[ed[j].snd]));
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll w[n];
	fore(i,0,n)cin>>w[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--; v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({min(u,v),max(u,v)});
	}
	//map<pair<ll,ll>> mp;
	//fore(i,0,m)mp[ed[i]]=i;
	STree st(n);
	fore(i,0,n)st.upd(i,{SZ(g[i])-w[i],i});
	//fore(j,0,n)cout<<st.query(j,j+1).fst<<" "; cout<<"\n";
	fore(i,0,n){
		auto q=st.query(0,n);
		if(q.fst>0){
		/*	if(i==n-1){
				ord.pb(q.snd);
				break;
			}*/
			cout<<"DEAD";
			return 0;
		}
		ord.pb(q.snd);
		for(auto j:g[q.snd]){
			auto qq=st.query(j,j+1);
			if(qq.fst!=INF)st.upd(j,{qq.fst-1,qq.snd});
		}
		st.upd(q.snd,NEUT);
		//fore(j,0,n)cout<<st.query(j,j+1).fst<<" "; cout<<"\n";
	}
	//for(auto i:ord)cout<<i<<" "; cout<<"\n";
	reverse(ALL(ord));
	fore(i,0,n)u[ord[i]]=i;
	//cout<<"HOLA"<<endl;
	ll res[m];
	fore(i,0,m)res[i]=i;
	//cout<<"HOLA"<<endl;
	sort(res,res+m,cmp);
/*	fore(i,0,m){
		if(w[ed[i].fst]==0&&w[ed[i].snd]==0){
			cout<<"DEAD";
			return 0;
		}
		w[ed[i].fst]=max(w[ed[i].fst]-1,0ll);
		w[ed[i].snd]=max(w[ed[i].snd]-1,0ll);
	}*/
	cout<<"ALIVE\n";
	fore(i,0,m)cout<<res[i]+1<<" ";
	return 0;
}