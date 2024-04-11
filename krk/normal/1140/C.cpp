#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n, k;
ii p[Maxn];
multiset <int> S;
ll tot;
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].second, &p[i].first);
    sort(p, p + n);
    for (int i = n - 1; i >= 0; i--) {
        S.insert(p[i].second);
        tot += p[i].second;
        if (S.size() > k) {
            tot -= *S.begin();
            S.erase(S.begin());
        }
        res = max(res, tot * ll(p[i].first));
    }
    cout << res << endl;
    return 0;
}