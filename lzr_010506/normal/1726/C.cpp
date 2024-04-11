#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[N];
int T, n, fa[N], lef[N], st[N];

inline int find(int x) 
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() 
{
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        scanf("%s", s);
        n <<= 1;
        int nw = 0;
        for(int i = 0; i < n; i ++) fa[i] = i;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(') 
            {
                lef[i] = -1;
                st[++ nw] = i;
            }
            else lef[i] = st[nw --];
            if (lef[i] != -1)
            {
                int j = lef[i], x = find(i), y = find(j);
                if (x != y) fa[x] = y;
                if (j) j = lef[j - 1];
                else j = -1;
                if (j != -1) 
                {
                    x = find(i); 
                    y = find(j);
                    if (x != y) fa[x] = y;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i ++) if (fa[i] == i) ans ++;
        printf("%d\n", ans);
    }

    return 0;
}