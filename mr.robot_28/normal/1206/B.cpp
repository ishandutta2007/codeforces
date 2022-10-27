# include <bits/stdc++.h>
using namespace std;

signed main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(A[i] <= -1)
		{
			ans += -1 - A[i];
			cnt1++;
		}
		else if(A[i] == 0){
			cnt2++;
		}
		else
		{
			cnt3++;
			ans += A[i] - 1;
		}
	}
	if(cnt1 % 2 == 1)
	{
		if(cnt2 > 0)
		{
			cnt2--;
			ans++;
		}
		else
		{
			ans += 2;
		}
	}
	ans += cnt2;
	cout << ans;
	return 0;
}