#include <bits/stdc++.h>

using namespace std;

const int SQRT = 200, N = 100005, BASE = 131072, MAX_A = 2000005;

bool special[MAX_A];
int tree[2 * BASE];
int ile1[N], ile2[N], tab[N], L[N], R[N];
long long ans[N];
int n, m, k;
vector<int> konce[N];
vector<int> pos[MAX_A];

void solveSpecial(int w) {
    if (w == 0) {
        ile1[0] = 1;
    } else {
        ile1[0] = 0;
    }
    if ((w ^ k) == 0) {
        ile2[0] = 1;
    } else {
        ile2[0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        if (tab[i] == w) {
            ile1[i] = 1;
        } else {
            ile1[i] = 0;
        }
        ile1[i] += ile1[i - 1];

        if (tab[i] == (w ^ k)) {
            ile2[i] = 1;
        } else {
            ile2[i] = 0;
        }
        ile2[i] += ile2[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        if (L[i] == 0) {
            if (w == (w ^ k)) {
                 ans[i] += (long long)ile1[R[i]] * (ile2[R[i]] - 1) / 2;
            } else {
                 ans[i] += (long long)ile1[R[i]] * ile2[R[i]];
            }
        } else {
            if (w == (w ^ k)) {
            ans[i] += (long long)(ile1[R[i]] - ile1[L[i] - 1]) * (ile2[R[i]] - ile2[L[i] - 1] - 1) / 2;
            } else {
                ans[i] += (long long)(ile1[R[i]] - ile1[L[i] - 1]) * (ile2[R[i]] - ile2[L[i] - 1]);
            }
        }
    }
}

void insert(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    tree[posa]++;
    if (posa != posb) {
        tree[posb]++;
    }

    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            tree[posa + 1]++;
        }
        if (posb % 2 == 1) {
            tree[posb - 1]++;
        }
        posa /= 2;
        posb /= 2;
    }
}

int query(int pos) {
    pos += BASE;
    int ret = 0;
    while (pos) {
        ret += tree[pos];
        pos /= 2;
    }
    return ret;
}

int main() {

    scanf("%d %d %d", &n, &m, &k);

    int maxValue = 0;
    pos[0].push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        tab[i] ^= tab[i - 1];
        pos[tab[i]].push_back(i);
        maxValue = max(maxValue, max(tab[i], tab[i] ^ k));
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &L[i], &R[i]);
        L[i]--;
        konce[R[i]].push_back(i);
    }

    for (int i = 0; i <= maxValue; i++) {
        if (i <= (i ^ k) && pos[i].size() + pos[i ^ k].size() >= SQRT) {
            special[i] = special[i ^ k] = true;
            solveSpecial(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (special[tab[i]] != true) {
            int u = tab[i] ^ k;
            for (int j = 0; j < pos[u].size(); j++) {
                int w = pos[u][j];
                if (w >= i) {
                    break;
                }
                insert(0, w);
            }
        }

        for (int j = 0; j < konce[i].size(); j++) {
            int in = konce[i][j];
            int poc = L[in];
            ans[in] += query(poc);
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%I64d\n", ans[i]);
    }

    return 0;
}