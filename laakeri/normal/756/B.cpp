#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll> t(n);
	for (int i=0;i<n;i++) cin>>t[i];
	for (int i=0;i<n;i++){
		if (i==0){
			cout<<20<<'\n';
			dp[i]=20;
			continue;
		}
		dp[i]=dp[i-1]+20;
		auto it=lower_bound(t.begin(), t.end(), t[i]-89);
		if (it==t.begin()){
			dp[i]=min(dp[i], 50ll);
		}
		else{
			dp[i]=min(dp[i], dp[(it-t.begin())-1]+50ll);
		}
		
		it=lower_bound(t.begin(), t.end(), t[i]-1439);
		if (it==t.begin()){
			dp[i]=min(dp[i], 120ll);
		}
		else{
			dp[i]=min(dp[i], dp[(it-t.begin())-1]+120ll);
		}
		cout<<dp[i]-dp[i-1]<<'\n';
	}
}