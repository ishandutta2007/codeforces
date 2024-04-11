#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;

int n, x;
pii seg[N];
int cost[N];
vec< int > arr[N];
vec< int > pref[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &x);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d", &seg[i].first, &seg[i].second, &cost[i]);
        arr[seg[i].second - seg[i].first + 1].push_back(i);
    }

    for(int l = 0;l < N;l++) {
        sort(ALL(arr[l]), [&](int i, int j) {
            return seg[i].second < seg[j].second;
        });
        int cur = inf + 10;
        for(int id, j = 0;j < (int)arr[l].size();j++) {
            id = arr[l][j];
            cur = min(cur, cost[id]);
            pref[l].push_back(cur);
        }
        for(int j = 0;j < (int)arr[l].size();j++) {
            arr[l][j] = seg[arr[l][j]].second;
        }
    }

    int res = 2 * inf + 10;

    for(int i = 1;i <= n;i++) {
        int len = seg[i].second - seg[i].first + 1;
        if(len > x) continue;
        len = x - len;
        int j = lower_bound(ALL(arr[len]), seg[i].first) - arr[len].begin() - 1;
        if(j >= 0 && j < (int)arr[len].size()) {
            res = min(res, cost[i] + pref[len][j]);
        }
    }

    if(res == 2 * inf + 10) {
        printf("-1\n");
    }else {
        printf("%d\n", res);
    }

    return 0;
}