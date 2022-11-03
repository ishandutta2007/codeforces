#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int mod = 1e9 + 7;

int a[maxn] , t[maxn];

vector<int> d[maxn];

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int pw(int a , int b)
{
	if(!b)
		return 1;
	int x = pw(a , b / 2);
	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;
	return x;
}

int main()
{
	for(int i = 1; i < maxn; i++)
		for(int j = i; j < maxn; j += i)
			d[j].pb(i);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i] , t[a[i] + 1]++;
	for(int i = 1; i < maxn; i++)
		t[i] += t[i - 1];
	int res = 0;
	for(int i = 1; i < maxn; i++)
	{
		int ans = 1 , k = d[i].size();
		for(int j = 0; j + 1 < k; j++)
			ans = 1LL * ans * pw(j + 1 , t[d[i][j + 1]] - t[d[i][j]]) % mod;
		ans = 1LL * ans * (pw(k , n - t[i]) - pw(k - 1 , n - t[i]) + mod) % mod;
		ok(res += ans);
	}
	cout << res << endl;
}