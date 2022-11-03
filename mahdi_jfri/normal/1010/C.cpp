#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int a[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , k;
	cin >> n >> k;

	int g = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] %= k;

		g = __gcd(__gcd(a[i] , k) , g);
	}

	if(!g)
		return cout << 1 << endl << 0 << endl , 0;

	vector<int> ans;
	for(int i = 0; i < k; i++)
		if(i % g == 0)
			ans.pb(i);

	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x << " ";
	cout << endl;

}