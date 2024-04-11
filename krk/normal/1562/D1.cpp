#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int T;
int n, q;
char str[Maxn];
vector <int> pos, neg;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        scanf("%s", str + 1);
        pos.clear(); neg.clear();
        for (int i = 1; i <= n; i++)
            if ((str[i] == '+') ^ (i % 2 != 0))
                pos.push_back(i);
            else neg.push_back(i);
        for (int i = 0; i < q; i++) {
            int l, r; scanf("%d %d", &l, &r);
            int P = upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
            int N = upper_bound(neg.begin(), neg.end(), r) - lower_bound(neg.begin(), neg.end(), l);
            int res;
            if (P == N) res = 0;
            else if (abs(P - N) % 2) res = 1;
            else res = 2;
            printf("%d\n", res);
        }
    }
    return 0;
}