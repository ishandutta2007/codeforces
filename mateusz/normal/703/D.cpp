#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, BASE = 1048576;

int n, m, r;
unordered_map<int, int> M;
int tab[N], pref[N], l[N], ans[N];
vector<int> en[N];
int tree[2 * BASE];

void insert(int pos, int w) {
    pos += BASE;
    while (pos) {
        tree[pos] ^= w;
        pos /= 2;
    }
}

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int ret = tree[posa];
    if (posa != posb) {
        ret ^= tree[posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret ^= tree[posa + 1];
        }
        if (posb % 2 == 1) {
            ret ^= tree[posb - 1];
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int main() {

    scanf("%d", &n);

    int total = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        if (!M.count(tab[i])) {
            total ^= tab[i];
            M[tab[i]] = 1;
        }
        pref[i] = pref[i - 1] ^ tab[i];
    }

    M.clear();

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l[i], &r);
        ans[i] = pref[r] ^ pref[l[i] - 1];
        en[r].push_back(i);
    }

    insert(0, total);

    for (int i = 1; i <= n; i++) {
        if (!M.count(tab[i])) {
            insert(0, tab[i]);
        } else {
            insert(M[tab[i]], tab[i]);
        }
        insert(i, tab[i]);
        M[tab[i]] = i;
        for (int j = 0; j < en[i].size(); j++) {
            ans[en[i][j]] ^= query(l[en[i][j]], i);
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}