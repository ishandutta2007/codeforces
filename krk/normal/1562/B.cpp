#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
const int Maxd = 10;

bool prime[Maxn];
int T;
int k;
string s;
int cnt[Maxd];

int main()
{
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i])
        for (int j = i + i; j < Maxn; j += i)
            prime[j] = false;
    cin >> T;
    while (T--) {
        cin >> k;
        cin >> s;
        bool found = false;
        for (int i = 0; i < k && !found; i++)
            if (!prime[s[i] - '0']) {
                found = true;
                printf("1\n%c\n", s[i]);
            }
        if (found) continue;
        fill(cnt, cnt + Maxd, 0);
        for (int i = 0; i < k; i++)
            cnt[s[i] - '0']++;
        for (int i = 0; i < Maxd && !found; i++)
            if (cnt[i] > 1) {
                found = true;
                printf("2\n%d%d\n", i, i);
            }
        if (found) continue;
        int mn = Maxn, wth;
        for (int i = 1; i < 1 << k; i++) if (__builtin_popcount(i) < mn) {
            int cur = 0;
            for (int j = 0; j < k; j++) if (i & 1 << j)
                cur = 10 * cur + int(s[j] - '0');
            if (!prime[cur]) {
                mn = __builtin_popcount(i);
                wth = i;
            }
        }
        printf("%d\n", mn);
        for (int i = 0; i < k; i++) if (wth & 1 << i)
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}