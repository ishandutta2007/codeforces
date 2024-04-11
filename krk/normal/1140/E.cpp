#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;

int n, k;
vector <int> A, B;

int getWays(const vector <int> &V, int l, int r)
{
    int me = 1, oth = 0;
    for (int i = l + 1; i < r; i++) {
        int nme = ll(k - 1) * oth % mod;
        int noth = (ll(me) + ll(k - 2) * oth) % mod;
        me = nme; oth = noth;
    }
    if (V[r] == V[l]) return ll(oth) * (k - 1) % mod;
    return (ll(me) + ll(oth) * (k - 2)) % mod;
}

int Solve(const vector <int> &V)
{
    int lef = 0;
    while (lef < V.size() && V[lef] == -1) lef++;
    if (lef == V.size()) {
        int res = k;
        for (int i = 1; i < V.size(); i++)
            res = ll(res) * (k - 1) % mod;
        return res;
    }
    int res = 1;
    for (int i = 0; i < lef; i++)
        res = ll(res) * (k - 1) % mod;
    int rig = int(V.size()) - 1;
    while (V[rig] == -1) rig--;
    for (int i = rig + 1; i < V.size(); i++)
        res = ll(res) * (k - 1) % mod;
    int lst = lef;
    for (int i = lef + 1; i <= rig; i++)
        if (V[i] != -1) {
            res = ll(res) * getWays(V, lst, i) % mod;
            lst = i;
        }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        if (i % 2 == 0) A.push_back(a);
        else B.push_back(a);
    }
    int res = ll(Solve(A)) * Solve(B) % mod;
    printf("%d\n", res);
    return 0;
}