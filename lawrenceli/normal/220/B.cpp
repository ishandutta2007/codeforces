#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 100100;

int n, m, d, ar[MAXN];
struct data {
    int l, r, id;
} qar[MAXN];
int freq[MAXN], ans[MAXN];

bool cmp(data d1, data d2) {
    return d1.l/d != d2.l/d ? d1.l < d2.l : d1.r < d2.r;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    d = sqrt(n);
    for (int i=0; i<n; i++) scanf("%d", &ar[i]);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &qar[i].l, &qar[i].r);
        qar[i].l--;
        qar[i].id = i;
    }
    sort(qar, qar+m, cmp);
    for (int i=0, j; i<m; i=j) {
        memset(freq, 0, sizeof(freq));
        int cur = 0, l = qar[i].l, r = qar[i].r;
        for (int k=l; k<r; k++)
            if (ar[k] <= n) {
                if (freq[ar[k]] == ar[k]) cur--;
                freq[ar[k]]++;
                if (freq[ar[k]] == ar[k]) cur++;
            }
        ans[qar[i].id] = cur;
        for (j=i+1; j<m && qar[j].l/d == qar[i].l/d; j++) {
            while (r < qar[j].r) {
                if (ar[r] <= n) {
                    if (freq[ar[r]] == ar[r]) cur--;
                    freq[ar[r]]++;
                    if (freq[ar[r]] == ar[r]) cur++;
                } r++;
            }
            while (l < qar[j].l) {
                if (ar[l] <= n) {
                    if (freq[ar[l]] == ar[l]) cur--;
                    freq[ar[l]]--;
                    if (freq[ar[l]] == ar[l]) cur++;
                } l++;
            }
            while (l > qar[j].l) {
                l--;
                if (ar[l] <= n) {
                    if (freq[ar[l]] == ar[l]) cur--;
                    freq[ar[l]]++;
                    if (freq[ar[l]] == ar[l]) cur++;
                }
            }
            ans[qar[j].id] = cur;
        }
    }
    for (int i=0; i<m; i++)
        printf("%d\n", ans[i]);
    return 0;
}