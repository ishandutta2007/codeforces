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

vector<ll> v;

void calcu(ll n){
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			v.pb(i); v.pb(n/i);
		}
	}
}

int main(){FIN;
	ll a,b; cin>>a>>b;
	if(b==a){
		cout<<0; return 0;
	}
	if(b<a)swap(a,b);
	ll d=b-a;
	calcu(d);
	sort(ALL(v));
	ll da=1ll*2e18,res=0;
//	cout<<SZ(v)<<" ";
	for(auto i:v){
		ll k=(((-a)%i)+i)%i;
		ll va=(a+k)*(b+k)/__gcd(1*a+k,1*b+k);
		if(va<da){
			da=va; res=k;
		}
	}
	cout<<res;
	
	return 0;
}