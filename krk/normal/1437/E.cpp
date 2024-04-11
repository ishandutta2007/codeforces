#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
const int Inf = 2000000000;

int n, k;
int a[Maxn];

int getMax(int old, int nw, int lef, int rig)
{
    vector <int> seq;
    for (int i = old + 1; i < nw; i++)
        if (lef <= a[i] && a[i] <= rig) {
            int ind = upper_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
            if (ind < seq.size()) seq[ind] = a[i];
            else seq.push_back(a[i]);
        }
    return seq.size();
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    int lst = 0, val = -Inf;
    int res = n - k;
    for (int i = 1; i <= k; i++) {
        int nw; scanf("%d", &nw);
        if (a[nw] < val) { printf("-1\n"); return 0; }
        res -= getMax(lst, nw, val, a[nw]);
        lst = nw; val = a[nw];
    }
    res -= getMax(lst, n + 1, val, Inf);
    printf("%d\n", res);
    return 0;
}