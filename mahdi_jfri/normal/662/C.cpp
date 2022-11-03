#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxN = 20;
const int maxn = (1 << maxN) + 20;

int t[maxn] , r[maxn][maxN + 3];

string s[maxN];

void cal(int n , int k)
{
	if(!n)
		return;
	cal(n - 1 , k);
	cal(n - 1 , k + (1 << (n - 1)));
	for(int j = n; j >= 1; j--)
		for(int i = 0; i < (1 << (n - 1)); i++)
		{
			r[k + i][j] += r[k + i + (1 << (n - 1))][j - 1];
			r[k + i + (1 << (n - 1))][j] += r[k + i][j - 1];
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			t[i] = (t[i] * 2 + (s[j][i] == '1'));
		r[t[i]][0]++;
	}
	cal(n , 0);
	int ans = 1e9;
	for(int mask = 0; mask < (1 << n); mask++)
	{
		int res = 0;
		for(int j = 0; j <= n; j++)
			res += r[mask][j] * min(j , n - j);
		ans = min(ans , res);
	}
	cout << ans << endl;
}