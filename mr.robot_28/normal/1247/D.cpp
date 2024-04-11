#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	map <int, int> W;
	int ans =0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		int t = A[i], k1 = 1, k2 = 1;
		for(int j = 2; j <= sqrt(A[i]); j++)
		{
			if(t % j == 0)
			{
				int cnt = 0;
				while(t % j == 0)
				{
					cnt++;
					t = t / j;
				}
				cnt = cnt % k;
				k2 *= pow(j, cnt);
				if(cnt != 0)
				{
					cnt = k - cnt;
				}
				k1 *= pow(j, cnt); 
			}
		}
		if(t != 1){
			k1 *= pow(t, k - 1);
			k2 *= t;
		}
		ans += W[k2];
		W[k1]++;
	}
	cout << ans;
	return 0;
}