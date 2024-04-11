#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int m;
int n, T, a, b;
ii seq[Maxn];
int has[2], rem[2];

int main()
{
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d %d", &n, &T, &a, &b);
        has[0] = has[1] = rem[0] = rem[1] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &seq[i].second);
            rem[seq[i].second]++;
        }
        for (int i = 0; i < n; i++)
            scanf("%d", &seq[i].first);
        seq[n] = ii(T + 1, 0);
        sort(seq, seq + n + 1);
        int res = 0;
        for (int i = 0; i <= n; i++) {
            int tim = seq[i].first - 1;
            ll mytim = ll(a) * has[0] + ll(b) * has[1];
            int cand = has[0] + has[1];
            if (mytim <= tim) {
                int tk = min(rem[0], (tim - int(mytim)) / a);
                mytim += ll(tk) * a;
                cand += tk;
                tk = min(rem[1], (tim - int(mytim)) / b);
                mytim += ll(tk) * b;
                cand += tk;
                res = max(res, cand);
            }
            rem[seq[i].second]--;
            has[seq[i].second]++;
        }
        printf("%d\n", res);
    }
    return 0;
}