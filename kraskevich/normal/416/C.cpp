#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

struct group {
    int c, p, id;
    group() {}
    group(int cc, int pp, int i): c(cc), p(pp), id(i) {}
};

bool cmp(group a, group b) {
    return a.p > b.p || a.p == b.p && a.c < b.c;
}

group g[1111];
set<pii> f;
int n, m;
vector<pii> ans;
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> g[i].c >> g[i].p;
        g[i].id = i;
    }
    sort(g, g + n, cmp);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        f.insert(pii(x, i));
    }
    for (int i = 0; i < n; i++) {
        pii cur = pii(g[i].c, 0);
        auto it = f.lower_bound(cur);
        if (it == f.end())
            continue;
        sum += g[i].p;
        ans.push_back(pii(g[i].id, it->S));
        f.erase(it);
    }
    cout << ans.size() << " " << sum << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].F + 1 << " " << ans[i].S + 1 << "\n";


    return 0;
}