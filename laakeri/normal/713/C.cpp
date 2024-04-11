#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<ll, ll> > dp[3030];

ll a[3030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0].push_back({-1e9, 0});
	for (int i=1;i<=n;i++){
		vector<ll> vals;
		for (int j=1;j<=n;j++){
			vals.push_back(a[j]+(ll)(i-j));
		}
		sort(vals.begin(), vals.end());
		vals.erase(unique(vals.begin(), vals.end()), vals.end());
		int i2=0;
		ll mi=1e18;
		for (int j=0;j<(int)vals.size();j++){
			while (i2<(int)dp[i-1].size()&&dp[i-1][i2].F<vals[j]){
				mi=min(mi, dp[i-1][i2].S);
				i2++;
			}
			dp[i].push_back({vals[j], mi+llabs(a[i]-vals[j])});
		}
	}
	ll v=1e18;
	for (auto t:dp[n]){
		v=min(v, t.S);
	}
	cout<<v<<endl;
}