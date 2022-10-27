#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a, r, m;
vector <int> h;
int funct(int s)
{
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(h[i] < s)
		{
			sum1 += s - h[i];
		}
		else
		{
			sum2 += h[i] - s;
		}
	}
	int ans = 0;
	if(m < a + r)
	{
		ans += min(sum1, sum2) * m;
		int t = min(sum1, sum2);
		sum1 -= t;
		sum2 -= t;
	}
	ans += sum1 * a;
	ans += sum2 * r;
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a >> r >> m;
	h.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >>h[i];
	}
	sort(h.begin(), h.end());
	int l = 0, r = 1e9;
	while(r - l > 2)
	{
		int l1 = l + (r - l) / 3;
		int r1 = r - (r - l) / 3;
		if(funct(l1) < funct(r1)){
			r = r1;
		}
		else
		{
			l = l1;
		}
	}
	cout << min(funct(l), min(funct(r), funct((r + l) / 2)));
    return 0;
}