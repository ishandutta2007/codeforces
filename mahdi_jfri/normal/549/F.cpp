#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 3e5 + 20;
const int maxm = 1e6 + 20;

int mx[maxn] , t[maxm] , a[maxn] , k , sum[maxn];

ll res;

inline void ok(int &a)
{
	a %= k;
	if(a >= k)
		a -= k;
	else if(a < 0)
		a += k;
}

void solve(int s , int e)
{
	if(e - s < 2)
		return;
	int m = (s + e) / 2;

	solve(s , m);
	solve(m , e);

	vector<pair<int , int> > v1 , v2;

	int mx = 0 , sum = 0;
	for(int i = m - 1; i >= s; i--)
	{
		ok(sum += a[i] % k);
		mx = max(mx , a[i]);

		v1.pb({sum , mx});
	}

	mx = 0 , sum = 0;
	for(int i = m; i < e; i++)
	{
		ok(sum += a[i] % k);
		mx = max(mx , a[i]);

		v2.pb({sum , mx});
	}

	int pt = 0;
	for(auto tmp : v1)
	{
		while(pt < (int)v2.size() && v2[pt].second <= tmp.second)
		{
			t[v2[pt].first]++;
			pt++;
		}
		int x = (-tmp.first + tmp.second) % k;
		ok(x);
		res += t[x];
	}
	for(auto tmp : v2)
		t[tmp.first] = 0;

	pt = 0;
	swap(v1 , v2);
	for(auto tmp : v1)
	{
		while(pt < (int)v2.size() && v2[pt].second < tmp.second)
		{
			t[v2[pt].first]++;
			pt++;
		}
		int x = (-tmp.first + tmp.second) % k;
		ok(x);
		res += t[x];
	}	
	for(auto tmp : v2)
		t[tmp.first] = 0;

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	solve(0 , n);

	cout << res << endl;
}