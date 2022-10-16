#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1e5 + 5;

int n, K, a[N], pr[N], tot, B = 233;

LL ans;

bool st[N];

map<ULL, int> m[N];

int main() {
    for (int i = 2; i <= 318; i++) {
        if (!st[i]) pr[++tot] = i;
        for (int j = i + i; j <= 318; j += i)
            st[j] = 1;
    }
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        ULL s1 = 0, s2 = 0;
        for (int j = 1; j <= tot; j++) {
            int k = pr[j];
            int c = 0;
            if (a[i] % k == 0) {
                while (a[i] % k == 0) c++, a[i] /= k;
                c %= K;
            }
            s1 = (s1 * B + c);
            s2 = (s2 * B + ((K - c) % K));
        }   
        if (a[i] == 1) {
            ans += m[a[i]][s1];
            m[a[i]][s2]++;
        } else {
            if (K == 2) {
                ans += m[a[i]][s1];
                m[a[i]][s2]++;
            } else {
                
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}