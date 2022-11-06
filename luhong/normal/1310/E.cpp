#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define mod 998244353
#define MN 2022

int f[MN][MN];
int g[MN][MN];
int n;

int k_1()
{
	int sum = 0; 
	for(int j = 1; j <= n; j++) g[0][j] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j >= 1; j--)
		{
			g[i][j] = g[i - j][j];
			g[i][j] = (g[i][j] + g[i][j + 1]) % mod;
		}
		sum = (sum + g[i][1]) % mod;
	}
	return sum;
	//g(i,j)=g(i-j,j')
}

int k_2()
{
	int sum = 0; 
	for(int j = 1; j <= n; j++) f[j][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int k = n; k >= i * (i + 1) / 2; k--)
		{
			f[2 * k / i / (i + 1) + 1][k] = 0;
			for(int j = 2 * k / i / (i + 1); j >= 1; j--)
			{
				f[j][k] = f[j][k - i * j];
				f[j][k] = (f[j][k] + f[j + 1][k]) % mod;
 			}
 			sum = (sum + f[1][k]) % mod;
		}
	return sum;
	//f(i,j,k)=f(i-1,j',k-ij)
	//\sum_i i*b_i = k, b_i = j
}

bool check(std::vector<int> v)
{
	int sum = 0;
	for(int i = 0; i < v.size(); i++)
	{
		sum += v[i] * (i + 1); 
		if(sum > n) return 0;
	}
	return 1;
}

std::vector<int> finv(std::vector<int> v)
{
	std::vector<int> u;
	for(int i = 0; i < v.size(); i++)
		for(int j = 1; j <= v[i]; j++)
			u.push_back(i + 1); 
	std::reverse(u.begin(), u.end());
	return u;
}

bool solve(std::vector<int> v, int k)
{
	for(int i = k; i > 2; i--)
	{
		v = finv(v);
		if(!check(v)) return 0;
	}
	return 1;
}

std::vector<int> v;
int ans = 0;

void dfs(int n, int now, int k)
{
	for(int i = 1; i <= std::min(n, now); i++)
	{
		v.push_back(i);
		if(!solve(v, k))
		{
			v.pop_back();
			return; 
		}
		else ans++;
		dfs(n - i, i, k);
		v.pop_back();
	}
}

int k_3(int k)
{
	int w = (int)(sqrt(2 * n) + 1e-8);
	dfs(w, w, k);
	return ans;
}

int main()
{
	int k; scanf("%d%d", &n, &k);
	if(k == 1) printf("%d\n", k_1());
	else if(k == 2) printf("%d\n", k_2());
	else printf("%d\n", k_3(k));
}