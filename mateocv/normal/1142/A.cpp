#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,k,a,b; cin>>n>>k>>a>>b;
	ll res0=n*k+3,res1=-1;
	fore(i,0,n){
		ll l=(i+2)*k+a+b; l%=n*k;
		res0=min(res0,n*k/(__gcd(n*k,l)));
		res1=max(res1,n*k/(__gcd(n*k,l)));
		l=(i+2)*k+a-b; l%=n*k;
		res0=min(res0,n*k/(__gcd(n*k,l)));
		res1=max(res1,n*k/(__gcd(n*k,l)));
		l=(i+2)*k-a+b; l%=n*k;
		res0=min(res0,n*k/(__gcd(n*k,l)));
		res1=max(res1,n*k/(__gcd(n*k,l)));
		l=(i+2)*k-a-b; l%=n*k;
		res0=min(res0,n*k/(__gcd(n*k,l)));
		res1=max(res1,n*k/(__gcd(n*k,l)));
	}
	cout<<res0<<" "<<res1;
	
	return 0;
}