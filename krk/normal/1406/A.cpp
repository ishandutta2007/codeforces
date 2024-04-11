#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int freq[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(freq, freq + Maxn, 0);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            freq[a]++;
        }
        int pnt = 0;
        while (freq[pnt] >= 2) pnt++;
        int res = pnt;
        while (freq[pnt] >= 1) pnt++;
        res += pnt;
        printf("%d\n", res);
    }
    return 0;
}