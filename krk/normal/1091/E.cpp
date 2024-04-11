#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 22;
const int Inf = 1000000000;

int n;
int a[Maxn];
int md;
ll lefD[Maxn], rigD[Maxn];
ll st[Maxn];
ll L[Maxn], R[Maxn];
ll rmq[Maxn][Maxm];
vector <int> res;

bool Less(const int &a, const int &b)
{
    return a > b;
}

int getLess(int lef, int rig, int val)
{
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (a[mid] < val) rig = mid - 1;
        else lef = mid + 1;
    }
    return rig + 1;
}

ll getMin(int lef, int rig)
{
    ll mn = Inf;
    for (int i = Maxm - 1; i >= 0; i--)
        if (lef + (1 << i) <= rig + 1) {
            mn = min(mn, rmq[lef][i]);
            lef += 1 << i;
        }
    return mn;
}

bool Check(int a, int val)
{
    if (val % 2 != md) return false;
    if (a > 0) {
        int lst = min(a, val);
        if (L[lst] < 0) return false;
        if (getMin(lst + 1, a) < -val) return false;
    }
    int fir = getLess(a + 1, n, a + 1);
    ll my = ll(a + 1) * a + ll(fir - a - 1) * (a + 1) + rigD[fir] - lefD[a] - val;
    if (my < 0) return false;
    if (R[a + 1] < val) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        md = (md + a[i]) % 2;
    }
    sort(a + 1, a + n + 1, Less);
    for (int i = 1; i <= n; i++)
        lefD[i] = lefD[i - 1] + a[i];
    R[n + 1] = Inf;
    for (int i = n; i > 0; i--) {
        rigD[i] = rigD[i + 1] + a[i];
        int fir = getLess(i + 1, n, i);
        st[i] = ll(i) * (i - 1) + ll(fir - i - 1) * i + rigD[fir] - lefD[i];
        fir = getLess(i + 1, n, i + 1);
        ll fut = ll(i + 1) * i + ll(fir - i - 1) * (i + 1) + rigD[fir] - lefD[i];
        R[i] = min(R[i + 1], fut);
        rmq[i][0] = st[i];
    }
    L[0] = Inf;
    for (int i = 1; i <= n; i++)
        L[i] = min(L[i - 1], st[i] + ll(i));
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i + (1 << j) <= n + 1; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << j - 1)][j - 1]);
    for (int v = 0; v < a[n]; v++)
        if (Check(n, v)) res.push_back(v);
    for (int i = n; i > 1; i--)
        for (int v = a[i]; v < a[i - 1]; v++)
            if (Check(i - 1, v)) res.push_back(v);
    for (int v = a[1]; v <= n; v++)
        if (Check(0, v)) res.push_back(v);
    if (res.empty()) printf("-1\n");
    else for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}