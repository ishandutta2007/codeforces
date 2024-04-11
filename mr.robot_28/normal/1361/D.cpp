#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
int sze = 0;
vector <vector <double> > arms;
int n, k;
double solve1()
{
	double ans = 0;
	vector <double> vals;
	for(int i = 0; i < sze; i++)
	{
		for(int j = 0; j < arms[i].size(); j++)
		{
			vals.push_back(arms[i][j] * (k - 2 * (j + 1) + 1));
		}
	}
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());
	for(int i = 0; i < min(k, (int)vals.size()); i++)
	{
		ans+= vals[i];
	}
	return ans;
}
double solve2(int ind)
{
	double ans = 0;
	for(int i = 0; i < sze; i++)
	{
		if(i == ind)
		{
			continue;
		}
		for(int j = 0; j < arms[i].size(); j++)
		{
			ans += arms[i][j] * (k - 2 * (j + 1) + 1);
		}
	}
	int half = k / 2;
	int half1 = k - half - (n - arms[ind].size());
	for(int i = 0; i < half; i++)
	{
		ans += arms[ind][i] * (k - 2 * i - 1);
	}
	for(int i = 0; i < half1; i++)
	{
		double val = arms[ind][arms[ind].size() - i-  1];
		ans += val * (k - 2 * half1 - 2 * half + 2 * i + 1);
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	vector <pair <int, int> > x(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
	}
	map <pair <int, int>, int> W;
	arms.resize(n);
	for(int i = 0; i < n; i++)
	{
		if(x[i].first == 0 && x[i].second == 0)
		{
			continue;
		}
		int d = __gcd(abs(x[i].first), abs(x[i].second));
		if(!W.count({x[i].first / d, x[i].second / d}))
		{
			W[{x[i].first / d, x[i].second / d}] = sze++;
		}
		int id = W[{x[i].first / d, x[i].second / d}];
		arms[id].push_back(sqrt(x[i].first * x[i].first + x[i].second * x[i].second));
	}
	for(int i = 0; i < sze; i++)
	{
		sort(arms[i].begin(), arms[i].end());
		reverse(arms[i].begin(), arms[i].end());
	}
	double ans = solve1();
	if(k < n)
	{
		for(int i = 0; i < sze; i++)
		{
			if((2 * (n - (int)arms[i].size())) <= k)
			{
				ans = max(ans, solve2(i));
			}
		}
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}