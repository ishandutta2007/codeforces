#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 62;
const int Maxn = 500005;

int n;
ll a[Maxn], b[Maxn];
ll cur;
ll my[Maxb];
int zers;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &a[i], &b[i]);
        cur ^= a[i];
        b[i] ^= a[i];
        for (int j = Maxb - 1; j >= 0; j--)
            if (b[i] & 1ll << ll(j))
                if (my[j]) b[i] ^= my[j];
                else {
                    my[j] = b[i];
                    break;
                }
        if (b[i] == 0) zers++;
    }
    for (int j = Maxb - 1; j >= 0; j--)
        if (cur & 1ll << ll(j))
            if (my[j]) cur ^= my[j];
            else {
                printf("1/1\n");
                return 0;
            }
    cout << ((1ll << ll(n - zers)) - 1ll) << "/" << (1ll << ll(n - zers)) << endl;
    return 0;
}