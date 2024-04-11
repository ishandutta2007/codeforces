#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int tab[N];
long long pref[N];
long long moment[N], poz[N];
int size;
int n;

long long sufit(long long a, long long b) {
    return (a + b - 1) / b;
}

long long find(int x) {
    int poc = 1;
    int kon = size;
    int ret = -1;
    while (poc <= kon) {
        int sr = (poc + kon) / 2;
        if (moment[sr] <= x) {
            ret = sr;
            poc = sr + 1;
        } else {
            kon = sr - 1;
        }
    }
    return (long long)x * poz[ret] - pref[poz[ret]];
}

int main() {

    scanf("%d", &n);
    long long v = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
        v += (long long)i * tab[i];
        pref[i] = pref[i - 1] + tab[i];
    }

    for (int i = 0; i <= n; i++) {
        while (size > 0 && (long long)i * moment[size] - pref[i] >= (long long)poz[size] * moment[size] - pref[poz[size]]) size--;
        if (size == 0) {
            moment[++size] = -1000000004LL;
            poz[size] = i;
        } else {
            moment[size + 1] = sufit(pref[i] - pref[poz[size]], i - poz[size]);
            poz[++size] = i;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long elo = find(tab[i]);
        ans = max(ans, elo + pref[i] - (long long)i * tab[i]);
    }
    printf("%I64d\n", ans + v);
    return 0;
}