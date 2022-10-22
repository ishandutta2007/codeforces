#include <bits/stdc++.h>
using namespace std;

const int Maxm = 15000005;

vector <int> primes;
int mn[Maxm];
int cnt[Maxm];
int n;
int res = Maxm;

int main()
{
    for (int i = 2; i < Maxm; i++) {
        if (mn[i] == 0) {
            primes.push_back(i);
            mn[i] = i;
        }
        for (int j = 0; j < primes.size() && primes[j] * i < Maxm; j++) {
            mn[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        while (a > 1) {
            int cur = mn[a];
            int got = 1;
            while (mn[a] == cur) {
                a /= cur;
                got *= cur;
                cnt[got]++;
            }
        }
    }
    for (int i = 2; i < Maxm; i++) if (cnt[i] < n)
        res = min(res, n - cnt[i]);
    if (res >= n) res = -1;
    printf("%d\n", res);
    return 0;
}