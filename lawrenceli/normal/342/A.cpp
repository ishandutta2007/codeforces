#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n, a[MAXN], freq[10];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i=0; i<n; i++) {
        if (a[i] == 5 || a[i] == 7) {
            printf("-1\n"); return 0;
        }
    }
    for (int i=0; i<n; i++) {
        freq[a[i]]++;
    }
    if (freq[1] != n/3) {
        printf("-1\n"); return 0;
    }
    if (freq[2] < freq[4]) {
        printf("-1\n"); return 0;
    }
    int sze = freq[4];
    freq[2] -= freq[4];
    if (freq[6] != freq[2] + freq[3]) {
        printf("-1\n"); return 0;
    }
    for (int i=0; i<sze; i++) printf("1 2 4\n");
    for (int i=0; i<freq[2]; i++) printf("1 2 6\n");
    for (int i=0; i<freq[3]; i++) printf("1 3 6\n");
}