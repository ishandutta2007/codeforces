#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int T;
int n, x, y;
char A[Maxn];
char B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &x, &y);
        scanf("%s", A);
        scanf("%s", B);
        vector <int> seq;
        for (int i = 0; i < n; i++)
            if (A[i] != B[i])
                seq.push_back(i);
        if (seq.size() % 2) { printf("-1\n"); continue; }
        if (seq.empty() || seq.size() > 2 || seq[1] - seq[0] > 1) { printf("%I64d\n", ll(y) * ll(seq.size() / 2)); continue; }
        ll res;
        if (seq[0] >= 2 || seq[1] + 2 < n) res = min(ll(x), 2ll * y);
        else if (seq[0] >= 1 && seq[1] + 1 < n) res = min(ll(x), 3ll * y);
        else res = x;
        printf("%I64d\n", res);
    }
    return 0;
}