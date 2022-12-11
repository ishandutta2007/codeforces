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
#define MAXN 1013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, K;
int arr[MAXN];
int color[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	FOR(i, 0, N)
	{
		cin >> arr[i];
		color[i] = -1;
	}
	sort(arr, arr + N);
	FOR(i, 0, N)
	{
		if (color[i] == -1)
		{
			FOR(j, i, N)
			{
				if (arr[j] % arr[i] == 0)
				{
					color[j] = K;
				}
			}
			K++;
		}
	}
	cout << K << '\n';
	return 0;
}