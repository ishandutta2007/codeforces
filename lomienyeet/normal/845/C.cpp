#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	ll N;
	cin>>N;
	pair<ll,ll> p[N];
	for(ll i=0;i<N;i++)cin>>p[i].ff>>p[i].ss;
	sort(p,p+N);
	pair<ll,ll> one={0,0},two={0,0};
	for(int i=0;i<N;i++){
		if(one.ss<p[i].ff)one={0,0};
		if(two.ss<p[i].ff)two={0,0};
		if(one.ss==0){
			one=p[i];
			continue;
		}
		else if(two.ss==0)two=p[i];
		else{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
int main(){
	//multitest
	solve();
}