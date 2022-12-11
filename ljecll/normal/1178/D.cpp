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
#define INF 1000000007
#define LLINF 2696969696969696969ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
int P;
int twos, threes;
vi vert[4];
vpi ans;

bool isprime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (P = N; ; P++)
	{
		if (isprime(P)) break;
	}
	//find any prime between N and 3N/2
	//some 2's and 3's add up to 2P
	//2x+3y = 2P, x+y = N => 2x+2y=2N => y = 2P-2N, x=3N-2P
	// cerr << "P = " << P << endl;
	twos = 3 * N - 2 * P;
	threes = 2 * P - 2 * N;
	// cerr << "TWOS = " << twos << " THREES = " << threes << endl;
	FOR(i, 0, twos)
	{
		vert[2].PB(i);
	}
	FOR(i, twos, N)
	{
		vert[3].PB(i);
	}
	while(true)
	{
		if (vert[1].empty() && vert[2].empty() && vert[3].empty())
		{
			break;
		}
		int x, u;
		if (!vert[3].empty())
		{
			x = 3; u = vert[3].back(); vert[3].pop_back();
		}
		else if (!vert[2].empty())
		{
			x = 2; u = vert[2].back(); vert[2].pop_back();
		}
		else if (!vert[1].empty())
		{
			x = 1; u = vert[1].back(); vert[1].pop_back();
		}
		// cerr << "u = " << u << endl;
		//ok just like feed!
		vpi ok;
		FOR(i, 0, x)
		{
			int v, n;
			FORD(j, 4, 1)
			{
				if (!vert[j].empty())
				{
					v = vert[j].back(); vert[j].pop_back();
					n = j - 1;
					break;
				}
			}
			ans.PB({u, v});
			ok.PB({v, n});
		}
		for (pii p : ok)
		{
			if (p.se != 0)
			vert[p.se].PB(p.fi);
		}
	}
	cout << SZ(ans) << '\n';
	for (pii p : ans)
	{
		cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
	}
	return 0;
}