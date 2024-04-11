#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000001;

bool prime[Maxn];
int n;
int res[Maxn];

int main()
{
    fill(prime + 2, prime + Maxn, true);
    for (int i = 2; i < Maxn; i++) if (prime[i])
        for (int j = i + i; j < Maxn; j += i)
            prime[j] = false;
    deque <int> D;
    for (int i = 1; i < Maxn; i++) {
        if (prime[i]) D.push_back(i);
        else if (!D.empty() && ll(D.front()) * D.front() == i) D.pop_front();
        res[i] = 1 + int(D.size());
    }
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        printf("%d\n", res[n]);
    }
    return 0;
}