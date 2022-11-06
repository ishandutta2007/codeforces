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

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define oper max
#define NEUT -1e18
struct STree{
	vector<ll> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, ll value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){ // [l, r)
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

const int MAXN=500005;

vector<ll> sump;

vector<pair<ll,ll>> sumps,sumpr;

STree sts(MAXN),str(MAXN);

vector<ll> maxi;

vector<ll> comp(vector<ll> a){
	auto v=a;
	sort(ALL(v));
	v.erase(unique(ALL(v)), v.end());
	fore(i,0,SZ(a))a[i]=lower_bound(ALL(v),a[i])-v.begin();
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		sump.clear();
		sump.pb(0);
		for(auto i:a)sump.pb(sump.back()+i);
		auto sc=comp(sump);
		fore(i,0,n+1){
			sts.upd(i,NEUT);
			str.upd(i,NEUT);
		}
		
		sumps.clear();
		fore(i,0,SZ(sump))sumps.pb({sump[i],-i});
		sort(ALL(sumps));
		vector<ll> us(SZ(sumps));
		fore(i,0,SZ(sumps))us[abs(sumps[i].snd)]=i;
		//for(auto i:sumps)cout<<i.fst<<" "<<i.snd<<"\n";
		
		sumpr.clear();
		fore(i,0,SZ(sump))sumpr.pb({sump[i],i});
		sort(ALL(sumpr));
		vector<ll> ur(SZ(sumpr));
		fore(i,0,SZ(sumpr))ur[abs(sumpr[i].snd)]=i;
		//for(auto i:sumpr)cout<<i.fst<<" "<<i.snd<<"\n";
		
		maxi.clear();
		maxi.resize(SZ(sc),NEUT);
		for(ll i=n;i>=0;i--){
			ll res=NEUT;
			if(i<n){
				res=maxi[sc[i]];
				res=max(res,sts.query(us[i],n+1)-i);
				res=max(res,str.query(0,ur[i])+i);
			}else{
				res=0;
			}
			//cout<<i<<" "<<res<<"\n";
			maxi[sc[i]]=max(maxi[sc[i]],res);
			sts.upd(us[i],res+i);
			str.upd(ur[i],res-i);
		}
		cout<<sts.query(us[0],us[0]+1)<<"\n";
	}
	
	return 0;
}