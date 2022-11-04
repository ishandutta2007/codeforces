#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a[5050], s[5050];

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	for(int i=1;i<=n;i++) s[i] = 0;
	ll ans = 0;

	for(int i=1;i<=n;i++){
		for(int j=min(n,i+a[i]);j>i+1;j--) s[j]++;

		a[i] -= s[i];
		if(a[i] <= 1){
			s[i+1] += 1 - a[i];
			continue;
		}

		ans += a[i] - 1;
	}

	cout << ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}