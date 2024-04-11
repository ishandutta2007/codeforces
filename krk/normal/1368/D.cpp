#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 20;

int n;
int cnt[Maxb];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        for (int j = 0; j < Maxb; j++)
            if (a & 1 << j) cnt[j]++;
    }
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < Maxb; j++)
            if (cnt[j] > 0) { cnt[j]--; mask |= 1 << j; }
        res += ll(mask) * mask;
    }
    cout << res << endl;
    return 0;
}