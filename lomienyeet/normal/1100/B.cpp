#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	ll N,M;
	cin>>N>>M;
	set<ll>st;
	map<int,int> mp;
	for(ll i=0;i<M;i++){
		ll temp;
		cin>>temp;
		st.insert(temp);
		mp[temp]++;
		if(st.size()==N){
			cout<<'1';
			st.clear();
			for(ll j=1;j<=N;j++){
				mp[j]--;
				if(mp[j])st.insert(j);
			}
		}
		else cout<<'0';
	}
}
int main(){
	//multitest
	solve();
}