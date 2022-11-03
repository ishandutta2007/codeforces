#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ld long double

const int maxn = 1e4 + 20;

ll a[maxn] , t[maxn] , sum[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			t[abs(a[i] - a[j])]++;
	for(int i = 1; i < maxn; i++)
		sum[i] = sum[i - 1] + t[i];
	ld res = 0;
	for(int i = 1; i < maxn; i++)
		for(int j = 1; i + j < maxn; j++)
			res += 1LL * t[i] * t[j] * (sum[maxn - 1] - sum[i + j]);
	res /= (ld)(1LL * n * (n - 1)) / 2.0;
	res /= (ld)(1LL * n * (n - 1)) / 2.0;
	res /= (ld)(1LL * n * (n - 1)) / 2.0;
	cout << fixed << setprecision(10) << res << endl;
}