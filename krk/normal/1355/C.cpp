#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A, B, C, D;
ll add;
ll res;

ll Get(ll d)
{
    ll lef = max(ll(A), C - d);
    ll rig = min(ll(B), D - d);
    return lef <= rig? rig - lef + 1: 0;
}

int main()
{
    scanf("%d %d %d %d", &A, &B, &C, &D);
    int pnt = 0;
    for (int y = B; y <= C; y++) {
        while (pnt < y) add += Get(pnt++);
        res += add;
    }
    cout << res << endl;
    return 0;
}