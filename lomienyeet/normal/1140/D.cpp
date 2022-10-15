#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
void solve(){
    //hewwo
	ll N;
	cin>>N;
	ll ans=0;
	for(ll i=2;i<N;i++)ans+=(ll)i*(i+1);
	cout<<ans<<"\n";
}
	
int main(){
	ll T=1;
	//cin>>T;
	while(T--)solve();
}