#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo n,c;
llo dp[100001];
llo it[100001];
llo pre[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>c;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		pre[i+1]=pre[i]+it[i];
	}
	multiset<llo> ss;
	for(llo i=1;i<=n;i++){
		dp[i]=dp[i-1]+it[i-1];
		ss.insert(it[i-1]);
		if(i>c){
			auto j=ss.find(it[i-c-1]);
			ss.erase(j);
		}
		if(i>=c){
			dp[i]=min(dp[i],dp[i-c]+pre[i]-pre[i-c]-(*ss.begin()));
		}
	}
		cout<<dp[n]<<endl;
	







	return 0;
}