#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 1000005;

bool prime[Maxm];
int T;
int n, e;
int a[Maxm];

int main()
{
    fill(prime + 2, prime + Maxm, true);
    for (int i = 2; i < Maxm; i++) if (prime[i])
        for (int j = i + i; j < Maxm; j += i)
            prime[j] = false;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &e);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ll res = 0;
        for (int i = 1; i <= e && i <= n; i++) {
            vector <int> seq;
            if (a[i] > 1) seq.push_back(i);
            for (int j = i + e; j <= n; j += e) {
                if (a[j] > 1) seq.push_back(j);
                if (!seq.empty() && prime[a[seq.back()]])
                    if (seq.size() >= 2) res += (min(j - e, seq.back()) - seq[int(seq.size()) - 2]) / e;
                    else res += min((seq.back() - 1) / e + 1, (j - 1) / e);
            }
        }
        printf("%I64d\n", res);
    }
    return 0;
}