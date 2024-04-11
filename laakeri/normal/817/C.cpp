#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n,s;
	cin>>n>>s;
	ll la=n;
	ll v=0;
	for (ll i=s;i<=n&&i<=s+100000;i++){
		ll t=i;
		ll ds=0;
		while (t){
			ds+=t%10;
			t/=10;
		}
		if (i-ds>=s) v++;
		la=i;
	}
	v+=n-la;
	cout<<v<<endl;
}