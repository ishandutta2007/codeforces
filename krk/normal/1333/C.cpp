#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
map <ll, int> M;
ll res;

int main()
{
    scanf("%d", &n);
    ll cur = 0;
    M[cur] = 0;
    int pnt = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cur += a[i];
        if (M.find(cur) != M.end())
            pnt = max(pnt, M[cur]);
        res += i - pnt - 1;
        M[cur] = i;
    }
    cout << res << endl;
    return 0;
}