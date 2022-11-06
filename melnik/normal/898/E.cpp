#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
vector <int> b;
vector <int> c;

inline bool sq(int x) {
	int y = sqrt(x);
	for (int i = max(0, y - 5); i <= y + 5; ++i)
		if (i * i == x)
			return true;
	return false;
}

inline int calc1(int x) {
	int ans = inf;
	for (int i = max(0, x - 2); i <= x + 2; ++i)
		if (!sq(i))
			ans = min(ans, abs(i - x));
	if (ans == inf)
		exit(228);
	return ans;
}

inline bool cmp1(int x, int y) {
	return calc1(x) < calc1(y);
}

inline int calc2(int x) {
	int y = sqrt(x);
	int ans = inf;
	for (int i = max(0, y - 5); i <= y + 5; ++i)
		ans = min(ans, abs(x - i * i));
	return ans;
}

inline bool cmp2(int x, int y) {
	return calc2(x) < calc2(y);
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    	scanf ("%d", &a[i]);
    for (int i = 0; i < n; ++i) 
    	if (sq(a[i]))
    		b.pb(a[i]);
    	else
    		c.pb(a[i]);

    sort(b.begin(), b.end(), cmp1);
    sort(c.begin(), c.end(), cmp2);

    ll ans = 0LL;
    if (b.size() > c.size()) {
    	int diff = (b.size() - c.size()) / 2;
    	for (int i = 0; i < diff; ++i)
    		ans += 1LL * calc1(b[i]);
    }

    if (b.size() < c.size()) {
    	int diff = (c.size() - b.size()) / 2;
    	for (int i = 0; i < diff; ++i)
    		ans += 1LL * calc2(c[i]);
    }

    cout << ans << endl;
    return 0;
}