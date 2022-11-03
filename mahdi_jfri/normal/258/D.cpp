#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ld long double
const int maxn = 1e3 + 20;
const ll mod = 1e9 + 7;
ld dp[maxn][maxn] , pd[maxn][maxn];
ll a[maxn];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			dp[i][j] = (a[i] > a[j]);
	while(m--)
	{
		int a , b;
		cin >> a >> b;
		a--;
		b--;
		if(a > b)
			swap(a , b);
		for(int i = 0; i < n; i++)
		{
			pd[a][i] = dp[a][i];
			pd[i][a] = dp[i][a];
		}
		for(int i = 0; i < n; i++)
		{
			pd[b][i] = dp[b][i];
			pd[i][b] = dp[i][b];
		}
		for(int i = a + 1; i < b; i++)
		{
			dp[a][i] = pd[a][i] * 0.5 + (1.0 - pd[i][b]) * 0.5;
			dp[i][b] = pd[i][b] * 0.5 + (1.0 - pd[a][i]) * 0.5;
		}
		for(int i = 0; i < a; i++)
		{
			dp[i][a] = pd[i][a] * 0.5 + pd[i][b] * 0.5;
			dp[i][b] = pd[i][b] * 0.5 + pd[i][a] * 0.5;
		}
		for(int i = b + 1; i < n; i++)
		{
			dp[a][i] = pd[a][i] * 0.5 + pd[b][i] * 0.5;
			dp[b][i] = pd[a][i] * 0.5 + pd[b][i] * 0.5;
		}
		dp[a][b] = 0.5;
	}
	ld e = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			e += dp[i][j];
	cout << fixed << setprecision(10) << e << endl;
}