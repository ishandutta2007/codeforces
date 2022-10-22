#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int Maxn = 10005;
 
int n, c;
int p[Maxn];
int s[Maxn];
ll res;
ll A[Maxn];
int alen;
ll tim[Maxn];
 
void Insert(ll x)
{
    A[alen++] = x;
    int pnt = alen - 1;
    while (pnt > 0 && A[pnt] < A[pnt - 1]) {
        swap(A[pnt], A[pnt - 1]);
        pnt--;
    }
}
 
int main()
{
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        res += min(p[i], s[i]);
        p[i] -= s[i];
    }
    for (int i = 1; i <= n; i++) {
        ll st = p[i], got = 0;
        if (alen == 0) {
            if (st > 0) Insert(st);
            continue;
        }
        ll t = 0;
        int lef = alen - 1, rig = alen - 1;
        tim[lef] = -t;
        while (lef <= rig && lef >= 0)
            if (A[lef] - (tim[lef] + t) == (lef? A[lef - 1]: 0) || tim[lef] + t >= c) {
                lef--;
                if (lef < 0) break;
                tim[lef] = -t;
            } else if (tim[rig] + t >= c) rig--;
            else {
                if (A[lef] <= st) break;
                ll tk = min(A[lef] - (tim[lef] + t) - (lef? A[lef - 1]: 0), c - (tim[rig] + t));
                tk = min(tk, (A[lef] - st) / (rig - lef + 1));
                if (tk == 0) {
                    int ch = A[lef] - st;
                    for (int j = 0; j < ch; j++)
                        tim[lef + j]++;
                    st += ch;
                    got += ch;
                    break;
                }
                t += tk;
                st += tk * (rig - lef + 1);
                got += tk * (rig - lef + 1);
            }
        for (int i = max(lef, 0); i < alen; i++) {
            ll usd = min(ll(c), tim[i] + t);
            A[i] -= usd;
        }
        if (p[i] < 0) res += min(-ll(p[i]), got);
        if (st > 0) Insert(st);
    }
    cout << res << endl;
    return 0;
}