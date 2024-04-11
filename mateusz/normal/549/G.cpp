#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
int n;
int tab[N], t[N];

bool cmp(int a, int b) {
    return tab[a] - (n - a) < tab[b] - (n - b);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    for(int i = 1; i <= n; i++) {
        t[i] = i;
    }
    sort(t + 1, t + 1 + n, cmp);
    for(int i = 2; i <= n; i++) {
        if(tab[t[i]] - (n - t[i]) == tab[t[i - 1]] - (n - t[i - 1])) {
            printf(":(\n");
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        printf("%d ", tab[t[i]] - (i - t[i]));
    }
    return 0;
}