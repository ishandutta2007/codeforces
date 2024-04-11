#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Inf = 1000000000;

int seq[3];
int T;
int sz;
ll has[Maxn];

int main()
{
    sz = 1;
    while (true) {
        seq[0]++;
        has[sz] = 2 * (ll(seq[0]) * seq[1] + ll(seq[0]) * seq[2] + ll(seq[1]) * seq[2]);
        sz++;
        if (has[sz - 1] >= Inf) break;
        sort(seq, seq + 3);
    }
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        int ind = lower_bound(has, has + sz, ll(n)) - has;
        printf("%d\n", ind);
    }
    return 0;
}