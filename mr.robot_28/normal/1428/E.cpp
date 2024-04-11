#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int a, int b)
{
	if(a % b == 0)
	{
		return (a / b) * (a / b) * b;
	}
	int c = a % b;
	int d = a / b;
	return c * (d + 1) * (d + 1) + (b - c) * d * d;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	priority_queue <pair <int, pair <int, int> > > q;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i] * a[i];
		q.push({a[i] * a[i] - (a[i] / 2) * (a[i] / 2) - (a[i] - a[i] / 2) * (a[i] - a[i] / 2), {i, 2}});
	}
	k -= n;
	while(k > 0)
	{
		int i = q.top().second.first;
		int c = q.top().second.second;
		sum -= q.top().first;
		q.pop();
		q.push({f(a[i], c) - f(a[i], c + 1), {i, c + 1}});
		k--;
	}
	cout << sum;
	return 0;
}