/**
 *  created: 12/04/2021, 11:08:47
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 1111, inf = 1000111222;

int d, n, a[max_n], p[max_n], nxt[max_n], used[max_n];
bool is_start[max_n];
vector<int> g[max_n];

bool cmp_by_ones(int x, int y) {
    return __builtin_popcount(x) < __builtin_popcount(y);
}

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = 1;
    for (int to : g[v]) {
        if (p[to] == -1) {
            p[to] = v;
            nxt[v] = to;
            return true;
        }
    }
    for (int to : g[v]) {
        if (dfs(p[to])) {
            p[to] = v;
            nxt[v] = to;
            return true;
        }
    }
    return false;
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        d = 10;
        n = (1 << d) - 1;
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    } else {
        cin >> d >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < d; ++j) {
                if (s[j] == '1') {
                    a[i] += 1 << j;
                }
            }
        }
    }
    sort(a, a + n, cmp_by_ones);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((a[i] & a[j]) == a[i] && __builtin_popcount(a[i]) < __builtin_popcount(a[j])) {
                g[i].push_back(j);
            }
        }
    }
    memset(p, -1, sizeof(p));
    memset(nxt, -1, sizeof(nxt));
    for (int i = n - 1; i >= 0; --i) {
        memset(used, 0, sizeof(used));
        dfs(i);
        is_start[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (nxt[i] != -1) {
            is_start[nxt[i]] = 0;
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (is_start[i]) {
            int last = 0;
            int cur = i;
            while (cur != -1) {
                for (int j = 0; j < d; ++j) {
                    if (!get_bit(last, j) && get_bit(a[cur], j)) {
                        ans.push_back(j);
                    }
                }
                last = a[cur];
                cur = nxt[cur];
            }
            ans.push_back(-1);
        }
    }
    ans.pop_back();
    printf("%d\n", ans.size());
    for (int x : ans) {
        if (x == -1) {
            printf("R ");
        } else {
            printf("%d ", x);
        }
    }
    puts("");
    return 0;
}