#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")    // WINDOWS ONLY

#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100001, inf = 1000111222;

int m[max_n];
int n, q;

int upd(int* from, int* to, int x) {
    while(from < to) {
        if (*from > x) {
            *from -= x;
        }
        ++from;
    }
}

int calc(int* from, int *to, int x) {
    int ans = 0;
    while(from < to) {
        if (*from == x) {
            ++ans;
        }
        ++from;
    }
    return ans;
}



int main() {
    //freopen("input.txt", "r", stdin);
    n = 100000;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
    }
    while(q--) {
        int t, l, r, x;
        scanf("%d%d%d%d", &t, &l, &r, &x);
        --l, --r;
        if (t == 1) {
            upd(m + l, m + r + 1, x);
        } else {
            printf("%d\n", calc(m + l, m + r + 1, x));
        }
    }
    return 0;
}