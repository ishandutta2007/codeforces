#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 205;

int T;
int n;
char str[Maxn];
int perm[Maxn];
bool tk[Maxn];

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

bool Check(const vector <char> &V, int hm)
{
    if (hm == V.size()) return true;
    for (int i = 0; i < V.size(); i++)
        if (V[i] != V[(i + hm) % int(V.size())])
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str + 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &perm[i]);
            tk[i] = false;
        }
        ll L = 1;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            int num = i;
            vector <char> V;
            while (!tk[num]) {
                tk[num] = true;
                V.push_back(str[num]);
                num = perm[num];
            }
            int res = V.size();
            for (int j = 1; j < V.size(); j++) if (V.size() % j == 0)
                if (Check(V, j)) { res = j; break; }
            L = lcm(L, res);
        }
        printf("%I64d\n", L);
    }
    return 0;
}