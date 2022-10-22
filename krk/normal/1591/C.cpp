#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, k;
vector <int> pos, neg;

ll Solve(vector <int> &seq)
{
    sort(seq.begin(), seq.end());
    ll res = 0;
    for (int i = int(seq.size()) - 1; i >= 0; i -= k)
        res += 2ll * seq[i];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        pos.clear(); neg.clear();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            mx = max(mx, abs(a));
            if (a >= 0) pos.push_back(a);
            else neg.push_back(-a);
        }
        printf("%I64d\n", Solve(pos) + Solve(neg) - ll(mx));
    }
    return 0;
}