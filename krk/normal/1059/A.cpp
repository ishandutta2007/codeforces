#include <bits/stdc++.h>
using namespace std;

int n, L, a;
int res;

int main()
{
    int lst = 0;
    scanf("%d %d %d", &n, &L, &a);
    for (int i = 0; i < n; i++) {
        int t, l; scanf("%d %d", &t, &l);
        res += (t - lst) / a;
        lst = t + l;
    }
    res += (L - lst) / a;
    cout << res << endl;
    return 0;
}