#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

int sz[5100];
vector<int> eds[5100];
vector<int> vv;
int dp[10000];
int n;
int a, b, c, d;

int dfs1(int v) {
    sz[v] = 0;
    if (eds[v].empty())
        sz[v] = 1;
    int ans = 0;
    if (v == a)
        ans = 1;
    if (v == b)
        ans = 2;
    if (v == c)
        ans = 3;
    if (v == d)
        ans = 4;
    for (int u: eds[v]) {
        int k = dfs1(u);
        ans = max(ans, k);
        sz[v] += sz[u];
    }
    return ans;
}

int sza, szb, szc, szd;

int main() {
    scanf("%d", &n);
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        eds[p].push_back(i);
    }
    for (int u: eds[0]) {
        int x = dfs1(u);
        sz[0] += sz[u];
        if (x == 0)
            vv.push_back(sz[u]);
        else if (x == 1)
            sza = sz[u];
        else if (x == 2)
            szb = sz[u];
        else if (x == 3)
            szc = sz[u];
        else if (x == 4)
            szd = sz[u];
    }
    if (sz[0] % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    int sum = 0;
    for (int i: vv)
        sum += i;
    dp[0] = 1;
    for (int i: vv) {
        for (int j = n - i; j >= 0; --j)
            dp[j + i] |= dp[j];
    }
    int fl1 = 0, fl2 = 0;
    for (int i = 0; i <= n; ++i) {
        if (!dp[i])
            continue;
        int x = (i + szc) - ((sum - i) + szd);
        int gg = sza - 1 + szb - 1;
        if (abs(x) <= gg)
            fl1 = 1;
    }
    for (int i = 0; i <= n; ++i) {
        if (!dp[i])
            continue;
        int x = (i + sza) - ((sum - i) + szb);
        int gg = szc - 1 + szd - 1;
        if (abs(x) <= gg)
            fl2 = 1;
    }
    if (fl1 && fl2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
	return 0;
}