#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[111], dp[100010];

void solve(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	int s = 0;
	for(int i=1;i<=n;i++) s += a[i];

	if(s % 2){
		cout << 0;
		return;
	}

	s /= 2;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=s;j>=a[i];j--){
			dp[j] |= dp[j-a[i]];
		}
	}

	if(!dp[s]){
		cout << 0;
		return;
	}

	for(int i=1;i<=n;i++) if(a[i] % 2){
		cout << "1\n" << i;
		return;
	}

	cout << "1\n";
	for(int k=1;k<=n;k++){
		s -= a[k]/2;
		for(int i=1;i<=n;i++) if(i != k) for(int j=s;j>=a[i];j--) dp[j] |= dp[j-a[i]];
		if(!dp[s]){
			cout << k;
			return;
		}
		s += a[k]/2;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1;// cin >> tc;
	while(tc--) solve(), cout << "\n";
}