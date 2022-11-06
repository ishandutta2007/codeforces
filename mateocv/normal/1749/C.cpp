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

bool solve(vector<ll> a, ll m){
	sort(ALL(a));
	for(ll i=m;i>=1;i--){
		while(SZ(a)&&a.back()>i)a.pop_back();
		if(SZ(a)==0)return 0;
		a.pop_back();
		if(SZ(a)){
			a[0]+=i;
			sort(ALL(a));
		}
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		ll l=0,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(solve(a,m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	
	return 0;
}