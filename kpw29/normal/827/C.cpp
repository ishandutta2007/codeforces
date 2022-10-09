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
int m,k, c;
#define maxn 100100

ordered_set v[4][11][11];
inline int ID(char zn)
{
	if (zn == 'A') return 0;
	if (zn == 'C') return 1;
	if (zn == 'G') return 2;
	if (zn == 'T') return 3;
}


char s[maxn];
char zn;
char tmp[15];

int main()
{
	scanf("%s", s + 1);
	int n = 1;
	while (s[n]) ++n; --n;
	FOR(step, 1, 10)
		FOR(i, 1, n) v[ID(s[i])][step][i % step].insert(i);
		
	int zap;
	scanf("%d", &zap);
	while (zap--)
	{
		int type, a, b;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d %c", &a, &zn);
			FOR(step, 1, 10)
				v[ID(s[a])][step][a % step].erase(a);
			
			s[a] = zn;
			FOR(step, 1, 10)
				v[ID(s[a])][step][a % step].insert(a);
		}
		else
		{
			scanf("%d%d%s", &a, &b, tmp);
			int len = strlen(tmp);
			int wyn = 0;
			for (int j = 0; j < len; ++j)
			{
				int g = ID(tmp[j]);
				wyn += v[g][len][(a + j)%len].order_of_key(b + 1) - v[g][len][(a + j)%len].order_of_key(a);
			}
			printf("%d", wyn);
			puts("");
		}
	}
}