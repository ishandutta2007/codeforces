#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxa = 4;
const int Maxb = 3;
const int my[Maxa][Maxb] = {{0, 0, 0}, {1, 2, 3}, {2, 3, 1}, {3, 1, 2}};

int t;
ll n;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d", &n); n--;
        int b = n % Maxb; n /= Maxb;
        int cnt = 0;
        ll cur = 1;
        while (cur <= n) {
            n -= cur;
            cur *= Maxa;
            cnt++;
        }
        ll sh = 0;
        ll res = 0;
        while (cnt--) {
            res |= ll(my[n % Maxa][b]) << ll(sh);
            n /= Maxa;
            sh += 2;
        }
        res |= ll(my[1][b]) << ll(sh);
        printf("%I64d\n", res);
    }
    return 0;
}