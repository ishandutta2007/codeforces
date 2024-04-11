#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m, l;
ll a[Maxn];
int res;

int main()
{
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    int i = 1;
    while (i <= n)
        if (a[i] <= l) i++;
        else {
            int j = i;
            while (j <= n && a[j] > l) j++;
            res++;
            i = j;
        }
    while (m--) {
        char typ; scanf(" %c", &typ);
        if (typ == '0') printf("%d\n", res);
        else {
            int ind, val; scanf("%d %d", &ind, &val);
            ll bef = a[ind];
            a[ind] += val;
            if (bef <= l && a[ind] > l) {
                res++;
                if (ind + 1 <= n && a[ind + 1] > l) res--;
                if (ind - 1 > 0 && a[ind - 1] > l) res--;
            }
        }
    }
    return 0;
}