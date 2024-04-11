#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
typedef vector <int> vi;
const ll mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;

int t;
#define maxn 500100
char s[maxn];
int n;
bool block[maxn];
vi V, K;
const int MAX = 3e8;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		scanf("%s", s + 1);
		V.clear(); K.clear();
		FOR(i, 1, n)
		{
			block[i] = 0;
			if (s[i] == 'V') V.pb(i);
			if (s[i] == 'K') K.pb(i);
		}
		ll vsz = (int)V.size(), ksz = (int)K.size();
		if (vsz * ksz <= 200 * n)
		{
			for (auto v : V)
				for (auto k : K) block[abs(v - k)] = 1;
		}
		else
		{
			int C = min(200, (int)ksz);
			for (auto v : V)
			{
				vi :: iterator it = K.begin();
				for (int help = 1; help <= C; ++help)
				{
					block[abs(v - *it)] = 1;
					++it;
				}
				it = K.end(); --it;
				for (int help = 1; help <= C; ++help)
				{
					block[abs(v - *it)] = 1;
					--it;
				}
			}
			random_shuffle(K.begin(), K.end());
			for (auto v : V)
			{
				vi :: iterator it = K.begin();
				for (int help = 1; help <= C; ++help)
				{
					block[abs(v - *it)] = 1;
					++it;
				}
				it = K.end(); --it;
				for (int help = 1; help <= C; ++help)
				{
					block[abs(v - *it)] = 1;
					--it;
				}
			}
			//lol;
		}
		int bs = 0;
		for (int i=n; i>0; --i)
		{
			if (!block[i])
			{
				for (int j = i + i; j <= n; j += i) block[i] |= block[j];
			}
			if (!block[i]) ++bs;
		}
		
		cout << bs << "\n";
		FOR(i, 1, n) if (!block[i]) cout << i << ' ';
		cout << "\n";
	}
}