#include<bits/stdc++.h>
 
using namespace std;
#define int int64_t
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
pair <pair <int, int>, int> can(int l1, int r1, int l2, int r2, int l3, int r3, int l4, int r4)
{
	for(int i = 0; i <= 1; i++){
		int a = l2;
		if(abs(l2) % 2 != i)
		{
			a++;
		}
		int b = l3;
		if(abs(l3) % 2 != i)
		{
			b++;
		}
		int c = l4;
		if(abs(l4) % 2 != i)
		{
			c++;
		}
		int d = l1;
		if(abs(l1) % 2 != i)
		{
			d++;
		}
		if(a > r2 || b > r3 || c > r4 || d > r1)
		{
			continue;
		}
		int k = min(max(0, d - (a + b + c)), ((r4 - c) / 2) * 2);
		c += k;
		k = min(max(0, d - (a + b + c)), ((r3 - b) / 2) * 2);
		b += k;
		k = min(max(0, d - (a + b + c)), ((r2 - a) / 2) * 2);
		a += k;
		if(a + b + c > r1 || a + b + c < d)
		{
			continue;
		}
		return {{a, b}, c};
	}
	return {{INT64_MIN, INT64_MIN}, INT64_MIN};
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> x(n), y(n), z(n);
		for(int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i] >> z[i];
		}
		int l = -1, r = 3e18 + 10;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			int l1 = INT64_MIN, r1 = INT64_MAX;
			int l2 = INT64_MIN, r2 = INT64_MAX;
			int l3 = INT64_MIN, r3 = INT64_MAX;
			int l4 = INT64_MIN, r4 = INT64_MAX;
			for(int i = 0; i < n; i++)
			{
				l1 = max(l1, x[i] + y[i] + z[i] - midd);
				r1 = min(r1, x[i] + y[i] + z[i] + midd);
				l2 = max(l2, -x[i] + y[i] + z[i] - midd);
				r2 = min(r2, -x[i] + y[i] + z[i] + midd);
				l3 = max(l3, x[i] - y[i] + z[i] - midd);
				r3 = min(r3, x[i] - y[i] + z[i] + midd);
				l4 = max(l4, x[i] + y[i] - z[i] - midd);
				r4 = min(r4, x[i] + y[i] - z[i] + midd);
			}
			pair <pair <int, int>, int> ans = can(l1, r1, l2, r2, l3, r3, l4, r4);
			if(ans.first.first == INT64_MIN)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		int l1 = INT64_MIN, r1 = INT64_MAX;
		int l2 = INT64_MIN, r2 = INT64_MAX;
		int l3 = INT64_MIN, r3 = INT64_MAX;
		int l4 = INT64_MIN, r4 = INT64_MAX;
		for(int i = 0; i < n; i++)
		{
			l1 = max(l1, x[i] + y[i] + z[i] - r);
			r1 = min(r1, x[i] + y[i] + z[i] + r);
			l2 = max(l2, -x[i] + y[i] + z[i] - r);
			r2 = min(r2, -x[i] + y[i] + z[i] + r);
			l3 = max(l3, x[i] - y[i] + z[i] - r);
			r3 = min(r3, x[i] - y[i] + z[i] + r);
			l4 = max(l4, x[i] + y[i] - z[i] - r);
			r4 = min(r4, x[i] + y[i] - z[i] + r);
		}
		pair <pair <int, int>, int> ans = can(l1, r1, l2, r2, l3, r3, l4, r4);
		int xans = (ans.first.second + ans.second) / 2;
		int yans = (ans.first.first + ans.second) / 2;
		int zans = (ans.first.first + ans.first.second) / 2;
		cout << xans << " " << yans << " " << zans << "\n";
	}
	return 0;
}