#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 2000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
int pref[maxn];
multiset <int> cur;

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n, m, k;
    scanf ("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
    	// scanf ("%d", &a[i]);
    	int x;
    	scanf ("%d", &x);
    	++pref[x];
    }
    // sort(a, a + n);
    int l, r;
    l = r = 0;
    int ans = 0;
    while (l < maxn / 2) {
    	while (r - l < m) {
    		while (pref[r]--)
    			cur.insert(r);
    		++r;
    	}

    	if (cur.size() > k - 1) {
    		ans += cur.size() - (k - 1);
    		while (cur.size() > k - 1) {
    			auto it = cur.end();
    			--it;
    			cur.erase(it);
    		}
    	}

    	cur.erase(l);
    	++l;
    }
    printf ("%d\n", ans);
    return 0;
}