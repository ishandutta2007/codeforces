#include <bits/stdc++.h>

using namespace std;

const int A = 1000000, N = 200005, M = 1e9 + 7, BASE = 262144;

int n, m, r;
int firstDivisor[A + 5], inv[A + 5], last[A + 5];
int tree[2 * BASE + 1];
int tab[N], l[N], ans[N];
vector<int> finish[N];

int mul(int w, int u) {
    return (long long)w * u % M;
}

void insert(int pos, int w) {
    pos += BASE;
    while (pos >= 1) {
        tree[pos] = mul(tree[pos], w);
        pos /= 2;
    }
}

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int ret = tree[posa];
    if (posa != posb) {
        ret = mul(ret, tree[posb]);
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            ret = mul(ret, tree[posa + 1]);
        }
        if (posb % 2 == 1) {
            ret = mul(ret, tree[posb - 1]);
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}

int power(int w, int k) {
    if (k == 0) {
        return 1;
    }
    return mul(power(mul(w, w), k / 2), k % 2 ? w : 1);
}

int inverse(int w) {
    return power(w, M - 2);
}

int main() {

    for (int i = 1; i <= 2 * BASE; i++) {
        tree[i] = 1;
    }

    scanf("%d", &n);

    for (int i = 1; i <= A; i++) {
        inv[i] = inverse(i);
    }

    for (int i = 2; i <= A; i++) {
        if (firstDivisor[i] == 0) {
            for (int j = i; j <= A; j += i) {
                firstDivisor[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &l[i], &r);
        finish[r].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        int w = tab[i];
        while (w > 1) {
            int div = firstDivisor[w];
            insert(last[div], inv[div - 1]);
            insert(last[div], div);
            insert(i, div - 1);
            last[div] = i;
            w /= div;
        }
        for (int j = 0; j < finish[i].size(); j++) {
            int in = finish[i][j];
            ans[in] = query(l[in], i);
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}