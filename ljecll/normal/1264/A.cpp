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
#define MAXN 400013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int TC, N;
int arr[MAXN];
int freq[MAXN];
vi compress;

bool cmp(int i, int j)
{
	return (arr[i] > arr[j]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(12);
	cerr << fixed << setprecision(4);
	cin >> TC;
	while(TC--)
	{
		compress.clear();
		cin >> N;
		FOR(i, 0, N)
		{
			cin >> arr[i];
			compress.PB(arr[i]);
		}
		sort(ALL(compress));
		compress.erase(unique(ALL(compress)), compress.end());
		if (SZ(compress) < 3)
		{
			cout << "0 0 0\n";
			continue;
		}
		FOR(i, 0, SZ(compress))
		{
			freq[i] = 0;
		}
		int gold = 0, silver = 0;
		FOR(i, 0, N)
		{
			arr[i] = LB(ALL(compress), arr[i]) - compress.begin();
			freq[arr[i]]++;
		}
		FOR(i, 0, N)
		{
			if (arr[i] == SZ(compress) - 1) gold++;
		}
		int sum = 0, idx = SZ(compress) - 2;
		for (;idx >= 0; idx--)
		{
			sum += freq[idx];
			if (sum > gold) break;
		}
		if (sum <= gold)
		{
			cout << "0 0 0\n";
			continue;
		}
		silver = sum; sum = 0;
		idx--;
		for (; idx >= 0; idx--)
		{
			sum += freq[idx];
			if (sum > gold) break;
		}
		if (sum <= gold)
		{
			cout << "0 0 0\n";
			continue;
		}
		if ((gold + silver + sum) * 2 > N)
		{
			cout << "0 0 0\n";
			continue;
		}
		idx--;
		while(idx >= 0)
		{
			if ((gold + silver + sum + freq[idx]) * 2 <= N)
			{
				sum += freq[idx];
				idx--;
			}
			else
			{
				break;
			}
		}
		cout << gold << ' ' << silver << ' ' << sum << '\n';
		//see if you can divide the silver and bronze...
	}
	return 0;
}