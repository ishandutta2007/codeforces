#include <bits/stdc++.h>

using namespace std;

const int N = 100005, BASE = 131072, INF = 1e9;

int tree[2 * BASE + 5];
int tab[N];
int n;
pair<int, int> t[N];
int low[N], high[N], par[N];
int value[N];

void renumber() {
    for (int i = 1; i <= n; i++) {
        t[i].first = tab[i];
        t[i].second = i;
    }
    sort(t + 1, t + 1 + n);
    int in = 0;
    for (int i = 1; i <= n; i++) {
        if (t[i].first != t[i - 1].first) {
            in++;
        }
        value[in] = t[i].first;
        tab[t[i].second] = in;
    }
}

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
        pos /= 2;
    }
}

int query(int posa, int posb) {
    if (posa > posb) {
        return INF;
    }
    posa += BASE;
    posb += BASE;
    int ret = min(tree[posa], tree[posb]);
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = min(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = min(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i < 2 * BASE; i++) {
        tree[i] = INF;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    renumber();

    for (int i = n; i >= 1; i--) {
        insert(tab[i], i);
    }

    low[1] = 0;
    high[1] = n + 1;
    for (int i = 1; i <= n; i++) {
        insert(tab[i], INF);
        int leftSon = query(low[i], tab[i] - 1);
        int rightSon = query(tab[i] + 1, high[i]);
        if (leftSon != INF) {
            par[leftSon] = value[tab[i]];
            low[leftSon] = low[i];
            high[leftSon] = tab[i];
        }
        if (rightSon != INF) {
            par[rightSon] = value[tab[i]];
            low[rightSon] = tab[i];
            high[rightSon] = high[i];
        }
    }

    for (int i = 2; i <= n; i++) {
        printf("%d ", par[i]);
    }

    return 0;
}