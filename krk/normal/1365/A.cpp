#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n, m;
int inrow[Maxn], incol[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        fill(inrow, inrow + Maxn, 0);
        fill(incol, incol + Maxn, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int a; scanf("%d", &a);
                inrow[i] += a;
                incol[j] += a;
            }
        int r = 0, c = 0;
        for (int i = 0; i < n; i++)
            if (inrow[i] == 0) r++;
        for (int i = 0; i < m; i++)
            if (incol[i] == 0) c++;
        if (min(r, c) % 2) printf("Ashish\n");
        else printf("Vivek\n");
    }
    return 0;
}