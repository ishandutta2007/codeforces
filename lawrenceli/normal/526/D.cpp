#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000100;

int n, k, z[MAXN], a[MAXN];
char s[MAXN];

void init() {
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i+z[i-l]>=r) {
            l = i;
            r = max(r, i);
            while (r<n && s[r] == s[r-l]) r++;
            z[i] = r-l;
        } else z[i] = z[i-l];
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    scanf("%d %d\n%s", &n, &k, s);
    init();

    for (int i=1; k*i<=n; i++) {
        bool b = 1;
        for (int j=1; j<k; j++)
            if (z[i*j] < i) b = 0;
        if (!b) continue;
        a[i*k-1]++;
        a[i*k+min(z[i*k], i)]--;
    }

    for (int i=0, j=0; i<n; i++) {
        j += a[i];
        printf("%d", bool(j));
    }
}