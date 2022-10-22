#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 2e5 + 5;

int n, T;
int a[N];
int t[N];
int perm_t[N];
int pos_t[N];

int perm_a[N];
int sm[4 * N];
int cn[4 * N];

void add(int v, int tl, int tr, int pos) {
    if(tl == tr) {
        sm[v] += t[perm_t[pos]];
        cn[v] = 1;
    }else {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) {
            add(v << 1, tl, tm, pos);
        }else {
            add(v << 1 | 1, tm + 1, tr, pos);
        }
        sm[v] = sm[v << 1] + sm[v << 1 | 1];
        cn[v] = cn[v << 1] + cn[v << 1 | 1];
    }
}

int get(int v, int tl, int tr, int S) {
    if(tl > tr) return 0;
    if(!cn[v]) return 0;
    if(tl == tr) {
        if(sm[v] <= S) {
            return 1;
        }else {
            return 0;
        }
    }else {
        int tm = (tl + tr) >> 1;
        if(sm[v << 1] <= S) {
            return cn[v << 1] + get(v << 1 | 1, tm + 1, tr, S - sm[v << 1]);
        }else {
            return get(v << 1, tl, tm, S);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &T);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &a[i], &t[i]);
    }

    for(int i = 1;i <= n;i++) {
        perm_t[i] = i;
    }

    sort(perm_t + 1, perm_t + n + 1, [&](int i, int j) {
        return t[i] < t[j];
    });

    for(int i = 1;i <= n;i++) {
        pos_t[perm_t[i]] = i;
    }

    for(int i = 1;i <= n;i++) {
        perm_a[i] = i;
    }

    sort(perm_a + 1, perm_a + n + 1, [&](int i, int j) {
        return a[i] > a[j];
    });

    int best_k = 0;
    int best_res = 0;

    for(int i = 0, k = n;k >= 1;k--) {
        while(i < n && a[perm_a[i + 1]] >= k) {
            add(1, 1, n, pos_t[perm_a[i + 1]]);
            i++;
        }
        if(!i) continue;
        // 1 .. i: a_j >= k
        int tmp_res = get(1, 1, n, T);
        if(tmp_res < k) continue;
        tmp_res = k;
        if(best_res <= tmp_res) {
            best_res = tmp_res;
            best_k = k;
        }
    }

    printf("%d\n", best_res);
    printf("%d\n", best_k);

    int j = 0;

    vec< char > used(n + 1);

    for(int i = 1;i <= n && j < best_k;i++) {
        if(a[perm_t[i]] >= best_k) {
            printf("%d ", perm_t[i]);
            used[perm_t[i]] = 1;
            j++;
        }
    }

    for(int i = 1;i <= n && j < best_k;i++) {
        if(used[perm_t[i]]) continue;
        printf("%d ", perm_t[i]);
        j++;
    }

    printf("\n");

    return 0;
}