#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, cnt[111];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> tc;
	while(tc--){
		for(int i=0;i<=100;i++) cnt[i] = 0;
		cin >> n;
		for(int i=1;i<=n;i++){
			int a; cin >> a;
			cnt[a]++;
		}
		int ans = 0;

		for(int j=0;j<=101;j++){
			if(!cnt[j]){
				ans += j;
				break;
			}
			cnt[j]--;
		}
		for(int j=0;j<=101;j++){
			if(!cnt[j]){
				ans += j;
				break;
			}
			cnt[j]--;
		}

		cout << ans << "\n";
	}
}