#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 105;

int T;
int n;
ll h;
int a[Maxn];
vector <ll> seq;

ll Solve()
{
    for (int i = 0; i < seq.size(); i++) {
        ll nd = (h - 1) / ll(int(seq.size()) - i) + 1;
        if (nd <= seq[i]) return nd;
        h -= seq[i];
    }
    return -1ll;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d", &n, &h);
        seq.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i) seq.push_back(a[i] - a[i - 1]);
        }
        seq.push_back(Inf);
        sort(seq.begin(), seq.end());
        printf("%I64d\n", Solve());
    }
    return 0;
}