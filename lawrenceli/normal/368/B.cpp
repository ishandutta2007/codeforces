#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

int n, m, a[MAXN], freq[MAXN], num[MAXN], cnt;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=n-1; i>=0; i--) {
        if (num[a[i]] == 0) cnt++;
        num[a[i]]++;
        freq[i] = cnt;
    }
    for (int i=0; i<m; i++) {
        int l; scanf("%d", &l);
        printf("%d\n", freq[l-1]);
    }
    return 0;
}