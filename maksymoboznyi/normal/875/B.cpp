#include <bits/stdc++.h>
#define small -2000000000000000000
#define big 2000000000000000000
#define pb push_back
using namespace std;

int t[4000005], n, last[1000006], a[1000006], p[1000006], wait[1000006];
bool used[1000006];
void update(int v, int vl, int vr, int pos)
{
    if (vl == vr)
    {
        t[v] = 1;
        return;
    }
    int vm = (vl+vr)/2;
    if (pos <= vm)
        update(2*v, vl, vm, pos);
    else
        update(2*v+1, vm+1, vr, pos);
    t[v] = t[2*v] + t[2*v+1];
}

int sum(int v, int vl, int vr, int l, int r)
{
    if (l > r)
        return 0;
    if (vl == l && vr == r)
        return t[v];
    int vm = (vl+vr)/2;
    return sum(2*v, vl, vm, l, min(r, vm)) + sum(2*v+1, vm+1, vr, max(l, vm+1), r);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int k = 0;
    int minl = n+1;
    int pp = 0;
    cout <<"1 ";
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == 0)
            p[i] = n;
        pp = p[i];
        used[p[i]] = true;
        if (minl == p[i] +1)
            while (used[minl-1])
                minl--;
        pp = minl;
        a[i] = i - (n-pp);
        cout << a[i] << ' ';
    }
    return 0;
}