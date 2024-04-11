#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MAXN=300005;

#define oper(a,b) a+b
#define NEUT 0
struct STree{
	vector<ll> t; int n;
	STree(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, ll value){
		for(t[p += n]+=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
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

STree sts(MAXN),stc(MAXN);

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> res(n);
	ll s=0;
	fore(i,0,n){
		if(i)res[i]=res[i-1];
		res[i]+=s+i*a[i];
		for(ll j=a[i];j<MAXN;j+=a[i]){
			res[i]-=stc.query(j,min(j+a[i],MAXN))*j;
		}
		res[i]-=sts.query(0,a[i]+1);
		s+=a[i];
		stc.upd(a[i],1);
		for(ll j=a[i];j<MAXN;j+=a[i]){
			sts.upd(j,a[i]);
		}
	}
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
	return 0;
}