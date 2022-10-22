#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int mn = 1000000007;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            mn = min(mn, a[i]);
        }
        vector <int> inds, vals;
        for (int i = 0; i < n; i++) if (a[i] % mn == 0) {
            inds.push_back(i);
            vals.push_back(a[i]);
        }
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); i++)
            a[inds[i]] = vals[i];
        bool ok = true;
        for (int i = 0; i + 1 < n && ok; i++)
            ok = a[i] <= a[i + 1];
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}