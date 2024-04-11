#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5+  10;

int n;
long long k;

int main () {
    int T;
    scanf("%d", &T);
    for (; T --; ) {
        scanf("%d %lld", &n, &k);
        long long ret = 1LL * (n) * (n - 1) / 2LL;

        k = ret - k + 1;

        long long now = 0;
        long long pos1 = -1, pos2 = -1;

        for (int j = 2 ; j <= n;  ++ j) {
            now += (n - j + 1);
            if (now >= k) {
                now -= (n - j + 1);
                pos2 = j + k - now - 1;
                pos1 = j - 1;
                break;
            }
        }

        assert(1 <= pos1 && pos1 <= n);
        assert(1 <= pos2 && pos2 <= n);

        for (int i = 1 ; i <= n; ++ i) {
            if (i == pos1 || i == pos2)
                putchar('b');
            else putchar('a');
        }
        puts("");
    }
}