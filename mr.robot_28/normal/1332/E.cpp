#include <bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
pair <int, int> power(int a, int n, int cnt1, int cnt2)
{
	if(n == 1)
	{
		return {cnt1, cnt2};
	}
	else if(n % 2 == 1)
	{
		pair <int, int> v = power(a, n - 1, cnt1, cnt2);
		int sum1 = v.first * cnt1 + v.second * cnt2;
		sum1 %= const1;
		int sum2 = v.first * cnt2 + v.second * cnt1;
		sum2 %= const1;
		return {sum1, sum2};
	}
	else
	{
		pair <int, int> v = power(a, n / 2, cnt1, cnt2);
		int sum1 = v.first * v.first + v.second * v.second;
		int sum2 = v.first * v.second * 2;
		return {sum1 % const1, sum2 % const1};
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, L, R;
	cin >> n >> m >> L >> R;
		int cnt1 = 0, cnt2 = 0;
		if(L % 2 == 0)
		{
			cnt1 = 1 + (R - L) / 2;
		}
		else
		{
			cnt1 = (R - L + 1) / 2; 
		}
		cnt2 = R - L + 1 - cnt1;
	pair <int, int> t = power(R - L + 1, m * n, cnt1, cnt2);
	if(n * m % 2 == 0)
	{
		cout <<  t.first;
	}
	else
	{
		cout << (t.first + t.second) % const1;
	}
    return 0;
}