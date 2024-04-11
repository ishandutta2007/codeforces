#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int n;
int v[N],t[N];
int ans[N],cnt[N];

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie();
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> v[i];
	for(int i = 1;i <= n;++i) {
		cin >> t[i];
		t[i] += t[i - 1];
	}
	
	for(int i = 1;i <= n;++i) {
		int l = i,r = n + 1;
		while(l < r) {
			int mid = l + r >> 1;
			if(t[mid] - t[i - 1] > v[i]) r = mid;
			else l = mid + 1;
			}
			ans[l] += v[i] - t[l - 1] + t[i - 1];
			cnt[l]++;
		}
		
		for(int i = 1;i <= n;++i) {
			cnt[i] += cnt[i - 1];
			ans[i] += (i - cnt[i]) * (t[i] - t[i - 1]);
			cout << ans[i] << ' ';
		}
}