#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxn = 1000100;

int n, ans[maxn], cnt;
vector<pii> pnts[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        pnts[y/1000].push_back(pii(x, i));
    }

    for (int i=0; i<=1000; i++) {
        if (i%2 == 0) sort(pnts[i].begin(), pnts[i].end());
        else sort(pnts[i].begin(), pnts[i].end(), greater<pii>());

        for (pii p : pnts[i]) ans[cnt++] = p.se;
    }

    for (int i=0; i<cnt; i++) cout << ans[i]+1 << ' ';
    cout << '\n';
}