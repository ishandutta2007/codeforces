#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
ll s;
int L[Maxn], R[Maxn];

int getStatus(ll X)
{
    int nd = n / 2 + 1;
    ll pay = 0;
    vector <int> seq;
    for (int i = 0; i < n; i++)
        if (R[i] < X) pay += L[i];
        else if (X < L[i]) { pay += L[i]; nd--; }
        else seq.push_back(L[i]);
    sort(seq.rbegin(), seq.rend());
    if (nd - int(seq.size()) > 0) return -1;
    nd = max(nd, 0);
    pay += X * ll(nd);
    for (int i = nd; i < seq.size(); i++)
        pay += seq[i];
    return pay <= s? 1: -1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %I64d", &n, &s);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &L[i], &R[i]);
        int lef = 0, rig = 1000000000;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (getStatus(mid) > 0) lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", lef - 1);
    }
    return 0;
}