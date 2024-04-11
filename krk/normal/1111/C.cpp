#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxk = 100005;

int n, k, A, B;
int p[Maxk];

ll Solve(int a, int b)
{
    int cnt = upper_bound(p, p + k, b) - lower_bound(p, p + k, a);
    if (cnt == 0) return A;
    ll res = ll(B) * ll(cnt) * ll(b - a + 1);
    if (a < b) {
        int m = a + b >> 1;
        res = min(res, Solve(a, m) + Solve(m + 1, b));
    }
    return res;
}

int main()
{
    scanf("%d %d %d %d", &n, &k, &A, &B);
    for (int i = 0; i < k; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    sort(p, p + k);
    cout << Solve(0, (1 << n) - 1) << endl;
    return 0;
}