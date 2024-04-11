#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int sum[maxn] , a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 1; i < n; i++)
		cin >> a[i] , sum[i] = sum[i - 1] + a[i];

	int res = 2e9;
	for(int i = m; i < n; i++)
		res = min(res , sum[i] - sum[i - m]);

	cout << res << endl;

}