#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 200005;
const ll Inf = 2000000000000000000ll;

int T;
int n, c, q;
char str[Maxn];
vector <llll> lr;
vector <ll> seq;

ll Add(ll a, ll b) { return min(Inf, a + b); }

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &c, &q);
        scanf("%s", str);
        lr.clear(); seq.clear();
        lr.push_back(llll(0, n - 1));
        seq.push_back(n);
        for (int i = 0; i < c; i++) {
            ll l, r; scanf("%I64d %I64d", &l, &r);
            l--; r--;
            lr.push_back(llll(l, r));
            seq.push_back(Add(seq.back(), r - l + 1));
        }
        while (q--) {
            ll ind; scanf("%I64d", &ind);
            ind--;
            int pnt = int(seq.size()) - 1;
            while (pnt > 0) {
                while (pnt > 0 && ind < seq[pnt - 1])
                    pnt--;
                if (pnt == 0) break;
                ind = lr[pnt].first + (ind - seq[pnt - 1]);
            }
            printf("%c\n", str[ind]);
        }
    }
    return 0;
}