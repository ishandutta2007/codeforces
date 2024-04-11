#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	ll N,M,K;
	cin>>N>>M>>K;
	vector<ll> vec(N);
	for(ll i=0;i<N;i++)cin>>vec[i];
	ll ans=N;
	priority_queue<ll> pq;
	for(ll i=1;i<N;i++){
		ll diff=vec[i]-vec[i-1]+1;
		pq.push(-diff);
	}
	ll use=N;
	while(use>K){
		ll dif=-pq.top();
		pq.pop();
		ans=ans-2+dif;
		use--;
	}
	cout<<ans<<"\n";
}
int main(){
	//multitest
	solve();
}