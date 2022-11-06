#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
int a[N];
int n;
int main() {
    scanf("%d", &n);
    int czapa = (1 << n);
    int m = (1 << (n + 1)) - 1;
    for(int i = 2; i <= m; i++) {
        scanf("%d", &a[i]);
    }
    long long wynik = 0;
    for(int i = czapa - 1; i >= 1; i--) {
        wynik += max(a[2 * i], a[2 * i + 1]) - min(a[2 * i], a[2 * i + 1]);
        a[i] += max(a[2 * i], a[2 * i + 1]);
    }
    printf("%I64d\n", wynik);
    return 0;
}