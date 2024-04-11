#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200000;
const int Maxb = 31;

int n;
int a[Maxn];
map <int, int> M;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        M[a[i]]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool was = false;
        for (int j = 0; j < Maxb; j++) {
            int nd = (1 << j) - a[i];
            if (nd != a[i] && M.find(nd) != M.end() ||
                nd == a[i] && M[nd] >= 2) { was = true; break; }
        }
        if (!was) res++;
    }
    printf("%d\n", res);
    return 0;
}