#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;


ld dp[2][6000];

ld aa[6000];
ld p[6000];
int s[6000];

int n, t;

const ld eps = 1e-12;

int main()
{
	cin >> n >> t;
	
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x >> s[i];
		p[i] = x / 100.0;
	}
	
	
	dp[0][0] = 1;
	ld ans = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int d = (i & 1) ^ 1;
		int d2 = (i & 1);
		for (int j = 0; j <= t; ++j)
			dp[d][j] = 0;
		
		aa[0] = 0;
		for (int j = 0; j <= t; ++j)
			aa[j] = 0;
		aa[1] = p[i];
		for (int j = 2; j < s[i]; ++j)
		{
			aa[j] = (1 - p[i]) * aa[j - 1];
			//if (aa[j] < eps)
			//	aa[j] = 0;
		}
		ld sum = 1;
		for (int j = 0; j < s[i]; ++j)
			sum -= aa[j];
		aa[s[i]] = sum;
		
		
		sum = 0;
		
		for (int j = 1; j <= t; ++j)
		{
			if (j >= s[i])
			{
				sum -= dp[d2][j - s[i]] * aa[s[i] - 1];
				if (j > s[i])
					sum -= dp[d2][j - s[i] - 1] * aa[s[i]];
			}
			sum *= (1 - p[i]);
			
			
			if (s[i] != 1)
				sum += dp[d2][j - 1] * aa[1];
			
			
			if (j >= s[i])
				sum += dp[d2][j - s[i]] * aa[s[i]];
			
			//if (sum < eps)
			//	sum = 0;
			dp[d][j] = sum;
			ans += sum;
			//cout << sum << " ";
		}
		//cout << "\n";
	}
	
	cout.setf(ios::fixed);
	cout.precision(20);
	
	cout << ans;
	
	
	return 0;
}