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
#define MAXN 200013
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, Q;
int arr[MAXN];
int acc[MAXN];
int pay[MAXN], suf[MAXN];


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i];
		acc[i] = -1;
	}
	cin >> Q;
	//store a set of (largest payout since time t)
	//for each guy you just need a last accessed
	FOR(i, 0, Q)
	{
		int qid, v; cin >> qid;
		if (qid == 1)
		{
			int idx; cin >> idx >> v; idx--;
			acc[idx] = i;
			arr[idx] = v;
		}
		if (qid == 2)
		{
			cin >> v;
			pay[i] = v;
		}
	}
	FORD(i, Q, 0)
	{
		suf[i] = max(suf[i + 1], pay[i]);
	}
	FOR(i, 0, N)
	{
		ckmax(arr[i], suf[acc[i] + 1]);
	}
	FOR(i, 0, N)
	{
		if (i) cout << ' ';
		cout << arr[i];
	}
	cout << '\n';
	return 0;
}