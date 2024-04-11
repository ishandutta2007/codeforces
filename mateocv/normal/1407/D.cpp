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
typedef int ll;

const int MAXN=300005;

ll a[MAXN],n;
ll dp[MAXN];
vector<pair<ll,ll>> v;
vector<ll> g[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res>=0)return res;
	if(x==n-1){
		return res=0;
	}
	res=f(x+1)+1;
	for(auto i:g[x]){
		res=min(res,f(i)+1);
	}
	//cout<<x<<" "<<res<<endl;
	return res;
}

#define oper(a,b) a+b
#define NEUT 0
struct STree{
	vector<int> t; int n;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, int value){
		for(t[p += n]=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

STree st(MAXN);
vector<ll> u;

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)v.pb({a[i],i});
	sort(ALL(v));
	fore(i,0,n){
		st.upd(v[i].snd,1);
		u.pb(v[i].snd);
		if(i==n-1||v[i].fst!=v[i+1].fst){
			while(SZ(u)){
				ll b=u.back();
				if(st.query(b+1,n)>0){
					ll l=b+1,r=n;
					while(l<=r){
						ll m=(l+r)/2;
						if(st.query(b+1,m)>0)r=m-1;
						else l=m+1;
					}
					if(r<n)g[b].pb(r);
				}
				if(st.query(0,b)>0){
					ll l=0,r=b;
					while(l<=r){
						ll m=(l+r)/2;
						if(st.query(m,b)>0)l=m+1;
						else r=m-1;
					}
					if(r<b)g[r].pb(b);
				}
				u.pop_back();
			}
		}
	}
	//cout<<"HOLA"<<endl;
	reverse(ALL(v));
	fore(i,0,n)st.upd(i,0);
	fore(i,0,n){
		st.upd(v[i].snd,1);
		u.pb(v[i].snd);
		if(i==n-1||v[i].fst!=v[i+1].fst){
			while(SZ(u)){
				ll b=u.back();
				if(st.query(b+1,n)>0){
					ll l=b+1,r=n;
					while(l<=r){
						ll m=(l+r)/2;
						if(st.query(b+1,m)>0)r=m-1;
						else l=m+1;
					}
					if(r<n)g[b].pb(r);
				}
				if(st.query(0,b)>0){
					ll l=0,r=b;
					while(l<=r){
						ll m=(l+r)/2;
						if(st.query(m,b)>0)l=m+1;
						else r=m-1;
					}
					if(r<b)g[r].pb(b);
				}
				u.pop_back();
			}
		}
	}
	//cout<<"HOLA"<<endl;
/*	fore(i,0,n){
		cout<<i<<": ";
		for(auto j:g[i])cout<<j<<" "; cout<<endl;
	}*/
	mset(dp,-1);
	cout<<f(0)<<"\n";
	
	return 0;
}