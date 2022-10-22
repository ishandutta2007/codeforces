#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int mx[Maxn];
int n, k;
int cnt[Maxn];
ll res;

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
        for (int j = i; j < Maxn; j += i) mx[j] = i;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        ll b = 1;
        int num = a; a = 1;
        while (num > 1) {
            int cur = mx[num];
            int my = 0;
            while (mx[num] == cur) { my++; num /= cur; }
            my %= k;
            for (int i = 0; i < my; i++)
                a *= cur;
            my = (k - my) % k;
            for (int i = 0; i < my && b < Maxn; i++)
                b *= cur;
        }
        if (b < Maxn) res += cnt[b];
        cnt[a]++;
    }
    cout << res << endl;
    return 0;
}