#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll a1,a2,a3,a4,a5,a6;
	cin>>a1>>a2>>a3>>a4>>a5>>a6;
	ll top=a1;
	ll bot=a4;
	ll v=0;
	for (ll i=top;i<top+min(a2, a6);i++){
		v+=i+i+1ll;
	}
	for (ll i=bot;i<bot+min(a3, a5);i++){
		v+=i+i+1ll;
	}
	v+=llabs(a3-a5)*(top+min(a2, a6))*2ll;
	//cout<<llabs(a3-a5)*(top+min(a2, a6))*2ll<<endl;
	cout<<v<<endl;
}