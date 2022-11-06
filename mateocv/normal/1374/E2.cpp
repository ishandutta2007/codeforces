#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*----------------CLASSIC SEGMENT TREE----------------*/
#define oper(a,b) a+b
const ll NEUT=0;
struct STree { // [cerrado-abierto)
    vector<ll> st;int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void upd(int k, int s, int e, int p, ll v){
        if(s+1==e){st[k]=v;return;}
        int m=(s+e)/2;
        if(p<m)upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k]=oper(st[2*k],st[2*k+1]);
    }
    ll query(int k, int s, int e, int a, int b){
        if(s>=b||e<=a)return NEUT;
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void upd(int p, ll v){upd(1,0,n,p,v);}
    ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree st(n);st.upd(i,v);st.query(s,e);

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	set<ll> st[2];
	ll c[n];
	fore(i,0,n){
		cin>>c[i];
		ll a,b; cin>>a>>b;
		if(a)st[0].insert(i);
		if(b)st[1].insert(i);
	}
	vector<pair<ll,ll>> aa,ab,bb,v;
	fore(i,0,n){
		if(st[0].count(i)&&st[1].count(i)){
			ab.pb({c[i],i});
		}else if(st[0].count(i)){
			aa.pb({c[i],i});
		}else if(st[1].count(i)){
			bb.pb({c[i],i});
		}
		v.pb({c[i],i});
	}
	sort(ALL(v));
	ll u[n];
	fore(i,0,n)u[v[i].snd]=i;
	STree cant(n),sum(n);
	fore(i,0,n){
		if(!st[0].count(v[i].snd)&&!st[1].count(v[i].snd)){
			sum.upd(i,v[i].fst);
			cant.upd(i,1);
		}
	}
	sort(ALL(aa));
	sort(ALL(ab));
	sort(ALL(bb));
	fore(i,k,SZ(aa)){
		sum.upd(u[aa[i].snd],aa[i].fst);
		cant.upd(u[aa[i].snd],1);
	}
	fore(i,k,SZ(bb)){
		sum.upd(u[bb[i].snd],bb[i].fst);
		cant.upd(u[bb[i].snd],1);
	}
	ll res=(1ll<<62);
	pair<ll,ll> val={-1,-1};
	ll sump[SZ(ab)+1];
	sump[0]=0;
	fore(i,0,SZ(ab)){
		sump[i+1]=sump[i]+ab[i].fst;
	}
	ll van=0;
	fore(i,0,k){
		if(i<SZ(aa))van+=aa[i].fst;
		if(i<SZ(bb))van+=bb[i].fst;
	}
	fore(i,0,min(m,SZ(ab))+1){
		ll y=max((k-i),0ll);
		if(i+2*y<=m&&min(SZ(aa),SZ(bb))>=y){
			ll f=m-i-2*y;
			ll l=0,r=n;
			while(l<=r){
				ll mid=(l+r)/2;
				if(cant.query(0,mid)>=f)r=mid-1;
				else l=mid+1;
			}
			//cout<<l<<" ";
			if(cant.query(0,l)==f){
				ll nres=sump[i]+van+sum.query(0,l);
				if(nres<res){
					res=nres;
					val={i,y};
				}
			}
		}
		if(y){
			if(y-1<SZ(aa)){
				van-=aa[y-1].fst;
				sum.upd(u[aa[y-1].snd],aa[y-1].fst);
				cant.upd(u[aa[y-1].snd],1);
			}
			if(y-1<SZ(bb)){
				van-=bb[y-1].fst;
				sum.upd(u[bb[y-1].snd],bb[y-1].fst);
				cant.upd(u[bb[y-1].snd],1);
			}
		}
		//cout<<res<<"\n";
	}
	if(res==(1ll<<62)){
		cout<<-1;
	}else{
		cout<<res<<"\n";
		ll disp[n];
		fore(i,0,n){
			if(!st[0].count(i)&&!st[1].count(i)){
				disp[u[i]]=1;
			}else disp[u[i]]=0;
		}
		vector<ll> rec;
		fore(i,0,val.fst)rec.pb(ab[i].snd);
		fore(i,0,SZ(aa)){
			if(i<val.snd)rec.pb(aa[i].snd);
			else disp[u[aa[i].snd]]=1;
		}
		fore(i,0,SZ(bb)){
			if(i<val.snd)rec.pb(bb[i].snd);
			else disp[u[bb[i].snd]]=1;
		}
		fore(i,0,n){
			if(SZ(rec)==m)break;
			if(disp[i])rec.pb(v[i].snd);
		}
		for(auto i:rec)cout<<i+1<<" ";
	}
	
	return 0;
}