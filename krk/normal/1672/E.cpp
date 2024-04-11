#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll res;
int n;
 
int Ask(int w)
{
    printf("? %d\n", w); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}
 
void Solve(int lef, int lres, int rig, int rres)
{
    if (lef + 1 == rig || (lef + 1) * rres >= res) return;
    int mid = lef + rig >> 1;
    int mres = Ask(mid);
    if (mres) res = min(res, ll(mres) * mid);
    if (mres != rres) Solve(mid, mres, rig, rres);
    if (mres != lres) Solve(lef, lres, mid, mres);
}
 
int main()
{
    scanf("%d", &n);
    res = 2001 * n;
    Solve(0, 0, 2001 * n, 1);
    printf("! %I64d\n", res); fflush(stdout);
    return 0;
}