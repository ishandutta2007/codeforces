#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld long double

const int maxn = 1e3 + 20;

int n , m , a[maxn] , b[maxn];

bool check(ld x)
{
	vector<int> shit;
	for(int i = 0; i < n; i++)
	{
		shit.pb(a[i]);
		shit.pb(b[(i + 1) % n]);
	}

	for(auto k : shit)
	{
		x -= (m + x) / (ld)k;
		
		if(x < 0)
			return 0;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	ld l = 0 , r = 2e9;

	if(!check(r))
		return cout << -1 << endl , 0;

	for(int i = 0; i < 1000; i++)
	{
		ld m = (l + r) / 2.0;

		if(check(m))
			r = m;
		else
			l = m;
	}

	cout << fixed << setprecision(10) << l << endl;
}