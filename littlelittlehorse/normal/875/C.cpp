#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, c[100011], in[100011], ans[100011], tot;
bool b[100001];
vector<int> a[100011], edge[100011];

int main() {
    memset(b, false, sizeof(b));
    memset(in, 0, sizeof(in));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 100000; i++)
        a[i].clear(), edge[i].clear();
    b[0] = true;
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
        }
    }
    bool ok = true;
    for (int i = 1; i < n && ok; i++)
    {
        int len1 = a[i].size(), len2 = a[i + 1].size(), len = min(len1, len2);
        bool same = true;
        for (int j = 0; j < len; j++)
            if (a[i][j] != a[i + 1][j])
            {
                same = false;
                edge[a[i + 1][j]].push_back(a[i][j]);
                ++in[a[i][j]];
                break;
            }
        if (same && len1 > len2)
            ok = false;
    }
    if (!ok)
    {
        printf("No\n");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        if (!in[i])
            c[++cnt] = i;
    tot = 0;
    for (int l = 1; l <= cnt && ok; l++)
    {
        int m = c[l], len = edge[m].size(); 
        bool could = b[m];
        for (int i = 0; i < len && ok; i++)
            if (!--in[edge[m][i]])
                c[++cnt] = edge[m][i];
    }   
    if (cnt != m)
    {
        printf("No\n");
        return 0;
    }
    for (int i = m; i; --i) {
        int m = c[i], len = edge[m].size(); 
        for (int i = 0; i < len && ok; i++)
            if (m < edge[m][i])
                if (b[edge[m][i]])
                    ok = false;
                else
                    b[m] = true;
            else
                if (b[edge[m][i]])
                    b[m] = true;
    }
    if (!ok) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    cnt = 0;
    for (int i = 1; i <= m; i++)
        if (!b[i])
            ++cnt;
    printf("%d\n", cnt);
    for (int i = 1; i <= m; i++)
        if (!b[i])
            printf("%d ", i);
}