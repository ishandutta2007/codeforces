#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define double long double
double solve(vector <int> x,vector <int> y, int n)
{
	int area = 0;
	for(int i = 0; i < n; i++)
	{
		int ax = x[i], bx = x[(i + 1) % n];
		int ay = y[i], by = y[(i + 1) % n];
		area += ax * by  - ay * bx;
	}
	if(area > 0)
	{
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());
	}
	vector <double> count(2e6 + 10, 0);
	int maxx = -1e9;
	for(int i = 0; i < n; i++)
	{
		int ax = x[i], bx = x[(i + 1) % n];
		int ay = y[i], by = y[(i + 1) % n];
		for(int j = ax; j < bx; j++)
		{
			count[j] += (ay * (bx - ax) + (by - ay) * (j - ax)) / (bx - ax);
		}
		for(int j = bx; j < ax; j++)
		{
			count[j] -= (by * (ax - bx) + (ay - by) * (j - bx) - 1) / (ax - bx);
		}
		if(ax == bx && by < ay)
		{
			count[ax] += ay - by;
		}
		maxx = max(maxx, ax);
	}
	count[maxx]++;
	double sum = 0, sum2 = 0, tot = 0;
	for(int i = 0; i < count.size(); i++)
	{
		tot += count[i];
		sum += count[i] * i;
	}
	assert(tot > 1);
	sum /= tot;
	for(int i = 0; i < count.size(); i++)
	{
		sum2 += count[i] * (i - sum) * (i - sum);
	}
	return 2 * sum2 / (tot - 1);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> x(n), y(n);
    for(int i =0; i < n; i++)
    {
    	cin >> x[i] >> y[i];
    	x[i] += 1e6 + 1;
    	y[i] += 1e6 + 1;
	}
	double ans = 0;
	ans += solve(x, y, n);
	ans += solve(y, x, n);
	cout << fixed << setprecision(10) << ans / 2;
    return 0;
}