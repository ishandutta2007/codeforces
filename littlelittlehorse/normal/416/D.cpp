#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int f[1000001], n, a[200001], last[200001], v[200001];

int main(){
    //freopen("d.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int now = 0;
    for (int i = 1; i <= n; i++)
    {
        last[i] = now;
        if (a[i] != -1) now = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int L = i, A = 0;
        long long rate = 1 << 30, value = 0;
        for (; L <= n; L++)
        {
            if (a[L] == -1)
               if (rate == 1 << 30) continue;
               else 
               {
                    value += rate; 
                    if (value <= 0) break;
               }
            else
                if (!A) A = L;
                else
                    if ((a[L] - a[A]) % (L - A)) break;
                    else
                        if (rate == 1 << 30)
                        {
                           rate = (a[L] - a[A]) / (L - A);
                           if ((long long)a[L] - rate * (L - i) <= 0) break;
                           value = a[L];
                        }
                        else
                           if ((a[L] - a[A]) / (L - A) != rate) break;
                           else value = a[L];
        }
        i = --L; ++ans;
    }
    printf("%d\n", ans);
}