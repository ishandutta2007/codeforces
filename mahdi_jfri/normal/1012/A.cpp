#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

int a[maxn];

int get(multiset<int> &x)
{
	auto it = x.end();
	it--;

	return *it;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < 2 * n; i++)
		cin >> a[i];

	sort(a , a + 2 * n);

	multiset<int> x , y;

	for(int i = 0; i < n; i++)
		x.insert(a[i]);
	for(int i = n; i < 2 * n; i++)
		y.insert(a[i]);

	ll res = 4e18;

	for(int i = 0; i < n; i++)
	{
		res = min(res , 1LL * (get(x) - *x.begin()) * (get(y) - *y.begin()));
		
		x.erase(x.find(a[i]));
		y.insert(a[i]);

		y.erase(y.find(a[i + n]));
		x.insert(a[i + n]);
	}

	cout << res << endl;
}