#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	vector <vector <int> > cnt(2, vector <int> (1 << 20));
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int p = 0;
	for(int i = 0; i < n; i++){
		cnt[i & 1][p]++;
		p = p ^ a[i];
		ans += cnt[1 - (i & 1)][p];
	}
	cout << ans;
    return 0;
}