#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, q;
ll ev, evcnt;
ll odd, oddcnt;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        ev = evcnt = 0;
        odd = oddcnt = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a % 2) { odd += a; oddcnt++; }
            else { ev += a; evcnt++; }
        }
        while (q--) {
            int typ, x; scanf("%d %d", &typ, &x);
            if (typ == 0) {
                if (evcnt) {
                    ev += evcnt * x;
                    if (x % 2) {
                        odd += ev;
                        oddcnt += evcnt;
                        ev = evcnt = 0;
                    }
                }
            } else {
                if (oddcnt) {
                    odd += oddcnt * x;
                    if (x % 2) {
                        ev += odd;
                        evcnt += oddcnt;
                        odd = oddcnt = 0;
                    }
                }
            }
            printf("%I64d\n", ev + odd);
        }
    }
    return 0;
}