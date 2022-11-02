#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a,b;
	cin>>a>>b;
	int v=0;
	for (ll le=1;le<63;le++){
		ll t=(1ll<<le)-1ll;
		for (ll i=0;i<le-1ll;i++){
			ll x=t-(1ll<<i);
			if (x>=a&&x<=b){
				//cout<<x<<endl;
				v++;
			}
		}
	}
	cout<<v<<endl;
}