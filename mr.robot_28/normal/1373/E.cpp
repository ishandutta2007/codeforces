#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int maxd = -1;
		int si = -1;
		for(int i = 0; i < 100 - k; i++)
		{
			int sum = 0;
			for(int j = 0; j <= k; j++)
			{
				sum += (i + j) % 10;
				sum += (i + j) / 10;
			}
			if(sum > maxd && sum <= n && (k == 0 || (n - sum) % (k + 1) == 0))
			{
				maxd = sum;
				si = i;
			}
		}
		if(maxd == -1){
			cout << -1 << "\n";
			continue;
		}
		n -= maxd;
			n /= (k + 1);
		string res = "";
		if(si == 0)
		{
			res += "0";
		}
		while(si > 0)
		{
			char t = '0' + si % 10;
			res += t;
			si = si / 10;
		}
		while(n > 0)
		{
			if(n < 9)
			{
				char t = '0' + n;
				res += t;
				n = 0;
			}
			else
			{
				res += "9";
				n -= 9;
			}
		}
		reverse(res.begin(), res.end());
		cout << res << "\n";
	}
    return 0;
}