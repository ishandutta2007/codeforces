#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int cnt1 = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int t= min(a[i] / 4, cnt1 / 2);
		t *= 2;
		a[i] -= t * 2;
		ans += t;
		cnt1 -= t;
		ans += a[i] / 3;
		if(a[i] % 3 == 1)
		{
			if(a[i] == 1)
			{
				cnt1++;
			}
			else if(cnt1 >= 2)
			{
				cnt1 -= 2;
				ans++;
			}
			else
			{
				cnt1++;
			}
		}
		else if(a[i] % 3 == 2)
		{
			if(cnt1 != 0)
			{
				cnt1--;
				ans++;
			}
			else
			{
				cnt1 += 2;
			}
		}
	}
	cout << ans;
	return 0;
}