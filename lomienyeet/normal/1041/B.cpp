#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
void solve(){
	//fuck
	unsigned ll a,b,x,y;
	cin>>a>>b>>x>>y;
	unsigned ll diu=__gcd(x,y);
	x/=diu;
	y/=diu;
	cout<<min(a/x,b/y)<<"\n";
}
	
int main(){
	ll T=1;
	//cin>>T;
	while(T--)solve();
}