#include <bits/stdc++.h>

using namespace std;

const int N = 100005, BASE = 131072;

int tree[2 * BASE + 5];
int tab[N];
int n;
long long ans[N];

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = w;
    pos /= 2;
    while (pos >= 1) {
        if (tab[tree[2 * pos]] > tab[tree[2 * pos + 1]]) {
            tree[pos] = tree[2 * pos];
        } else {
            tree[pos] = tree[2 * pos + 1];
        }
        pos /= 2;
    }
}

int query(int posa, int posb) {
    posa += BASE;
    posb += BASE;
    int ret;
    if (tab[tree[posa]] > tab[tree[posb]]) {
        ret = tree[posa];
    } else {
        ret = tree[posb];
    }
    while (posa / 2 != posb / 2) {
        if (posa % 2 == 0) {
            if (tab[ret] < tab[tree[posa + 1]]) {
                ret = tree[posa + 1];
            }
        }
        if (posb % 2 == 1) {
            if (tab[ret] < tab[tree[posb - 1]]) {
                ret = tree[posb - 1];
            }
        }
        posa /= 2;
        posb /= 2;
    }
    return ret;
}


int main() {

    scanf("%d", &n);
    tab[0] = -1;

    for (int i = 1; i < n; i++) {
        scanf("%d", &tab[i]);
        insert(i, i);
    }
    insert(n, n);

    for (int i = n - 1; i >= 1; i--) {
        int best = query(i + 1, tab[i]);
        ans[i] = ans[best] + n - i - (tab[i] - best);
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += ans[i];
    }

    printf("%I64d\n", sum);

    return 0;
}