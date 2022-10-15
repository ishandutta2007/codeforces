#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
void solve(){
	//fuck
	ll N,K;
	cin>>N>>K;
	vector<ll> v;
	v.resize(N);
	for(ll i=0;i<N;i++)cin>>v[i];
	sort(v.begin(),v.end());
	for(ll i=N-1;i>=1;i--)v[i]-=v[i-1];
	v.push_back(0);
	ll pos=0;
	for(ll i=0;i<K;i++){
		cout<<v[pos]<<"\n";
		pos+=(pos<N);
		while(pos<N and v[pos]==0)pos++;
	}
}
	
int main(){
	ll T=1;
	//cin>>T;
	while(T--)solve();
}