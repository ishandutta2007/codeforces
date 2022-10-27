#include <bits/stdc++.h>
                  
using namespace std;
vector <double> p, ff;
int n, k;
vector <double> dp;
void funct(double f, int ind)
{
	if(f < 1e-9)
	{
		cout << fixed << setprecision(10) << 0 << " ";
		return;
	}
	dp[0] = f;
	for(int i = 0; i <= n; i++)
	{
		ff[i] = 0;
	}
	ff[0] = f;
	for(int mask = 1; mask < (1 << n); mask++)	
	{
		if(__builtin_popcount(mask) >= k)
		{
			continue;
		}
		if(((mask) & (1 << ind)) == 0)
		{
			dp[mask] = 0;
			double pr = 1;
			for(int j = 0; j < n; j++)
			{
				if(((mask) & (1 << j)) != 0)
				{
					pr -= p[j];
					dp[mask] += dp[mask - (1 << j)] * p[j];
				}
			}
			dp[mask] /= pr;
			ff[__builtin_popcount(mask)] += dp[mask];
		}
	}
	double v = 0;
	for(int i = 0; i < k; i++){
		v += ff[i];
	}
	cout << fixed << setprecision(10) << v << " ";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	p.resize(n + 1);
	ff.resize(n + 1);
	dp.resize((1 << n) + 10);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for(int i = 0; i < n; i++)
	{
		funct(p[i], i);
	}
	return 0;
}