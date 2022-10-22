#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 998244353;
const int Maxn = 200005;

int T;
int n, m, k, q;
set <int> R, C;
ii quer[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &k, &q);
        R.clear(); C.clear();
        for (int i = 0; i < q; i++)
            scanf("%d %d", &quer[i].first, &quer[i].second);
        int res = 1;
        for (int i = q - 1; i >= 0; i--) {
            if ((R.find(quer[i].first) == R.end() && C.size() < m) ||
                (C.find(quer[i].second) == C.end() && R.size() < n))
                res = ll(res) * k % mod;
            R.insert(quer[i].first);
            C.insert(quer[i].second);
        }
        printf("%d\n", res);
    }
    return 0;
}