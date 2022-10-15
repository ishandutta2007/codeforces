// VasuOberoi's code from https://ide.codingblocks.com/s/579801

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lli long long int
#define MOD 1000000007
#define endl '\n'
#define inf 1e18
#define pi 3.14159265358979323846  //  cout << fixed << setprecision(10) << pi << endl;
#define ninf -1e18
#define root(n)  sqrt(n)
#define rootf(n) sqrtf(n)
#define rootl(n) sqrtl(n)
#define PQ priority_queue<int>
#define PQM priority_queue<int,vector<int>,greater<int>>
#define HashMap(x,y) unordered_map<x,y>

typedef pair<ll, ll> nodel;
const int MAX = 1e9;
const int MIN = -1e9;
//floor(x) returns largest integer <= x
// floor(2.9)=2,floor(-2.1)=-3
// ceil(x) returns smallest integer >=x
// ceil(2.3)=3,ceil(-2.4)= -2
// round(x) returns rounded value of x
// round(3.5)=4,round(-3.5)=-4,round(-3.1)=3;

const int mx = 2e5 + 11;
#define int long long

typedef pair<int, int> node;

void solve()
{	int n;
	cin >> n;

	node a[n];


	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[i] = {x, i + 1};
	}





	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i].first * a[j].first > 2 * n)
			{
				break;
			}
			if (a[i].first * a[j].first ==  a[j].second + a[i].second)
			{
				ans++;
			}
		}
	}





	cout << ans << endl;
	return;


}

void file_io()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

}


signed main()
{
	file_io();

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
// #ifndef ONLINE_JUDGE
// clock_t begin = clock();
//   clock_t end = clock();
//   cout << "Time = " << (double)end - begin / CLOCKS_PER_SEC << "ms" << endl;
// #endif
	return 0;
}