#include <bits/stdc++.h>

using namespace std;

const int N = 300005, BASE = 131072 * 4;
const long long INF = 1e18 + 1;

int n;
int tab[N], tab2[N], where[N];
long long balloons[N], weight[N];

pair<long long, int> tree[2 * BASE + 1];

pair<long long, int> sum (pair<long long, int> A, pair<long long, int> B) {
    return {min(INF, A.first + B.first), A.second + B.second};
}

void insert(int pos, pair<long long, int> w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos) {
        tree[pos] = sum(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

int query(int pos, long long toGive) {
    if (pos >= BASE) {
        return toGive >= tree[pos].first ? tree[pos].second : 0;
    }
    if (toGive <= tree[2 * pos].first) {
        return query(pos * 2, toGive);
    } else {
        return tree[2 * pos].second + query(pos * 2 + 1, toGive - tree[2 * pos].first);
    }
}

bool cmp(int a, int b) {
    if (balloons[a] == balloons[b]) {
        return a > b;
    }
    return balloons[a] < balloons[b];
}

bool cmp2(int a, int b) {
    return weight[a] - balloons[a] + 1 < weight[b] - balloons[b] + 1;
}
int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &balloons[i], &weight[i]);
        tab[i] = i;
        tab2[i] = i;
    }

    sort(tab + 1, tab + 1 + n, cmp);
    sort(tab2 + 1, tab2 + 1 + n, cmp2);
    for (int i = 1; i <= n; i++) {
        if (tab2[i] != 1) {
            insert(i, {weight[tab2[i]] - balloons[tab2[i]] + 1, 1});
            where[tab2[i]] = i;
        }
    }

    int ans = 1e9;
    if (balloons[tab[1]] != 0) {
        ans = min(ans, n - query(1, balloons[1]));
    }

    for (int i = 1; i <= n; i++) {
        int w = tab[i];
        insert(where[w], {0, 0});
        if (i == n || balloons[tab[i + 1]] != balloons[w]) {
            ans = min(ans, n - query(1, balloons[1] - balloons[w]) - i + (w == 1));
        }
        if (w == 1) {
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}