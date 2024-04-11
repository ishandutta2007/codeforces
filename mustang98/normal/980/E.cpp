#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, max_log = 21, inf = 1000111222;

int n, k;
vector<int> v[max_n];
int pp[max_n][max_log];
bool taken[max_n];
bool removed[max_n];
int d[max_n];

void dfs(int cur, int pr) {
    if (pr == -1) {
        d[cur] = 0;
    } else {
        d[cur] = d[pr] + 1;
    }
    pp[cur][0] = pr;
    int l = 0;
    while (pp[cur][l] != -1 && pp[pp[cur][l]][l] != -1) {
        pp[cur][l + 1] = pp[pp[cur][l]][l];
        ++l;
    }
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;
        dfs(to, cur);
    }
}

int need_add(int cur) {
    int a = cur;
    for (int l = max_log - 1; l >= 0; --l) {
        if (pp[a][l] != -1 && taken[pp[a][l]] == false) {
            a = pp[a][l];
        }
    }
    return d[cur] - d[a] + 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < max_log; ++j) {
            pp[i][j] = -1;
        }
    }
    dfs(n - 1, -1);
    int lft = n - k;
    taken[n - 1] = 1;
    lft--;
    for (int cur = n - 2; cur >= 0; --cur) {
        if (taken[cur]) continue;
        int need_a = need_add(cur);
        if (need_a <= lft) {
            lft -= need_a;
            int c = cur;
            while (!taken[c]) {
                taken[c] = 1;
                c = pp[c][0];
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (!taken[i]) {
            ans.PB(i);
        }
    }
    //cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < k; ++i) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}