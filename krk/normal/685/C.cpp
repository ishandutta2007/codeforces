#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 100005;

int T;
int n;
ll A[Maxn], B[Maxn], C[Maxn], D[Maxn];
llll x0, x1, x2, x3;
ll X, Y, Z;

void getAnswer()
{
    ll cand = x1.first + x2.first - x0.second;
    ll nd = x3.first - cand;
    ll tk = min(x1.second - x1.first, nd);
    x1.first += tk; nd -= tk;
    tk = min(x2.second - x2.first, nd);
    x2.first += tk; nd -= tk;
    tk = min(x0.second - x0.first, nd);
    x0.second -= tk; nd -= tk;
    ll v0 = x0.second, v1 = x1.first, v2 = x2.first;
    X = (v1 + v2) / 2;
    Y = (v2 - v0) / 2;
    Z = (v1 - v0) / 2;
}

llll Get(ll A[], ll x, int md)
{
    ll lef = A[n - 1] - x, rig = A[0] + x;
    while (abs(lef % 2) != md) lef++;
    while (abs(rig % 2) != md) rig--;
    return llll(lef, rig);
}

bool Check(ll x, int md)
{
    x0 = Get(A, x, md);
    if (x0.first > x0.second) return false;
    x1 = Get(B, x, md);
    if (x1.first > x1.second) return false;
    x2 = Get(C, x, md);
    if (x2.first > x2.second) return false;
    x3 = Get(D, x, md);
    llll oth = llll(x1.first + x2.first - x0.second, x1.second + x2.second - x0.first);
    while (abs(oth.first % 2) != md) oth.first++;
    while (abs(oth.second % 2) != md) oth.second--;
    x3.first = max(x3.first, oth.first);
    x3.second = min(x3.second, oth.second);
    return x3.first <= x3.second;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            ll x, y, z; scanf("%I64d %I64d %I64d", &x, &y, &z);
            A[i] = x - y - z;
            B[i] = x - y + z;
            C[i] = x + y - z;
            D[i] = x + y + z;
        }
        sort(A, A + n);
        sort(B, B + n);
        sort(C, C + n);
        sort(D, D + n);
        ll lef = 0, rig = 3000000000000000002ll;
        while (lef <= rig) {
            ll mid = lef + rig >> 1ll;
            if (Check(mid, 0)) rig = mid - 1ll;
            else if (Check(mid, 1)) rig = mid - 1ll;
            else lef = mid + 1ll;
        }
        if (Check(lef, 0)) getAnswer();
        else if (Check(lef, 1)) getAnswer();
        else assert(false);
        printf("%I64d %I64d %I64d\n", X, Y, Z);
    }
    return 0;
}