#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int N, Q, a[maxn];

int main () 
{
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i ++)
        a[i] = i;

    bool flag = false;
    int k, l, r;
    int n = N, bw = 0;

    while (Q--) 
    {
        scanf("%d%d", &k, &l);
        if (k == 1) 
        {
            if (l > n - l) 
            {
                flag = !flag;
                l = n - l;
            }

            if (flag) 
            {
                for (int i = 0; i < l; i ++)
                    a[bw + n - l - i] += N - a[bw + n - l + i];
            } 
            else 
            {
                bw += l;
                for (int i = 0; i < l; i ++)
                    a[bw + i] -= a[bw - i];
            }
            n -= l;

        } 	
        else 
        {
            scanf("%d", &r);
            if (flag) 
            {
                int tmp = n - r;
                r = n - l;
                l = tmp;
            }
            printf("%d\n", a[bw + r] - a[bw + l]);
        }
    }
    return 0;
}