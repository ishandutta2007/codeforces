#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
	if (a > b) a = b;
}
template<class T, class U>
void ckmax(T &a, U b)
{
	if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) ((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, K, A;
ll arr[MAXN];
ll cost[MAXN];
priority_queue<ll, vector<ll>, greater<ll> > pq;
ll ans;
int taken;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	FOR(i, 0, N)
	{
		cin >> arr[i];
	}
	cin >> A;
	FOR(i, 0, N)
	{
		cin >> cost[i];
	}
	FOR(i, 0, N)
	{
		arr[i] = (arr[i] - K + A - 1) / A;
		// cerr << arr[i] << ' ';
	}
	// cerr << endl;
	FOR(i, 0, N)
	{
		pq.push(cost[i]);
		while(taken < arr[i])
		{
			if (pq.empty())
			{
				cout << "-1\n";
				return 0;
			}
			taken++;
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << '\n';
	return 0;
}