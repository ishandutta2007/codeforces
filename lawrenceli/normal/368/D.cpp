#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 200100;

typedef long long ll;

ll n, m, p, a[MAXN], b[MAXN], cnt, ans[MAXN], size;
map<int, int> bfreq, freq;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &n, &m, &p);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<m; i++) {
        scanf("%d", &b[i]);
        bfreq[b[i]] ++;
    }
    for (int q=0; q<p; q++) {
        freq.clear(); cnt = 0;
        if (q + (m-1) * p >= n) break;
        for (int i=q; i<q + m*p; i += p) {
            freq[a[i]] ++;
            if (freq[a[i]] <= bfreq[a[i]]) cnt++;
        }
        if (cnt == m) ans[size++] = q;
        for (int i=q; i + m * p < n; i += p) {
            freq[a[i]] --;
            if (freq[a[i]] < bfreq[a[i]]) cnt--;
            freq[a[i + m * p]] ++;
            if (freq[a[i + m * p]] <= bfreq[a[i + m * p]]) cnt++;
            if (cnt ==  m) ans[size++] = i + p;
        }
    }
    sort(ans, ans + size);
    printf("%d\n", size);
    for (int i=0; i<size; i++) {
        printf("%d", ans[i]+1);
        if (i < size - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}