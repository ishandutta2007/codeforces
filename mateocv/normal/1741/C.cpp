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

vector<ll> a;

ll solve(ll x){
	ll s=x,va=0,res=0;
	fore(i,0,SZ(a)){
		s-=a[i];
		va++;
		if(s<0)return SZ(a);
		if(s==0){
			res=max(res,va);
			va=0;
			s=x;
		}
	}
	if(s!=x)return SZ(a);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.clear();
		a.resize(n);
		fore(i,0,n)cin>>a[i];
		ll s=0,res=n;
		fore(i,0,n){
			s+=a[i];
			res=min(res,solve(s));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}