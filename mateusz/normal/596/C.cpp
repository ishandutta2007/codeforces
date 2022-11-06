#include <bits/stdc++.h>

using namespace std;

const int N = 100005, BASE = 2 * 131072, C = 100000;

int n;
int tree[2 * BASE + 5];
pair<int, int> tab[N];
vector<int> V[2 * C + 5];
pair<int, int> ans[N];
int w[N];

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    if (posa > posb) {
        return 0;
    }
    int ret = max(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = max(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = max(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

void insert(int pos, int w) {
    pos += BASE;
    while (pos) {
        tree[pos] = max(tree[pos], w);
        pos /= 2;
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &tab[i].first, &tab[i].second);
    }
    sort(tab + 1, tab + 1 + n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        V[w[i] + C].push_back(i);
    }

    for (int i = 0; i <= 2 * C; i++) {
        sort(V[i].begin(), V[i].end());
        reverse(V[i].begin(), V[i].end());
    }

    for (int i = 1; i <= n; i++) {
        int v = tab[i].second - tab[i].first;
        if (V[v + C].empty()) {
            printf("NO\n");
            return 0;
        }
        int in = V[v + C].back();
        V[v + C].pop_back();
        ans[in] = make_pair(tab[i].first, tab[i].second);
        if (query(0, tab[i].second) > in) {
            printf("NO\n");
            return 0;
        }
        insert(tab[i].second, in);
    }

    printf("YES\n");

    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}