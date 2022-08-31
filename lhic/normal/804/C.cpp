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

const int MAXN = 510000;

vector<int> cl[MAXN];
int was[MAXN];
int us[MAXN];
int ans[MAXN];
vector<int> eds[MAXN];
int n, m;

void dfs1(int v) {
    was[v] = 1;
    memset(us, 0, sizeof(us[0]) * (cl[v].size() + 1));
    for (int i: cl[v]) {
        if (ans[i] != -1) {
            if (ans[i] <= cl[v].size())
                us[ans[i]] = 1;
        }
    }
    int now = 0;
    for (int i: cl[v]) {
        if (ans[i] == -1) {
            while (us[now])
                ++now;
            ans[i] = now;
            us[now] = 1;
        }
    }
    for (int u: eds[v]) {
        if (!was[u])
            dfs1(u);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int aa = 1;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int x;
            scanf("%d", &x);
            --x;
            cl[i].push_back(x);
        }
        aa = max(aa, k);
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        eds[a].push_back(b);
        eds[b].push_back(a);
    }
    for (int i = 0; i < m; ++i)
        ans[i] = -1;
    dfs1(0);
    printf("%d\n", aa);
    for (int i = 0; i < m; ++i)
        printf("%d ", max(1, ans[i] + 1));
    printf("\n");
    return 0;
}