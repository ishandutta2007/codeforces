#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
ll st1, st2;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int l = -1, r = n;
    while (l < r) {
        if (st1 == st2) res = st1;
        if (l + 1 < r)
            if (st1 <= st2) st1 += a[++l];
            else st2 += a[--r];
        else break;
    }
    cout << res << endl;
    return 0;
}