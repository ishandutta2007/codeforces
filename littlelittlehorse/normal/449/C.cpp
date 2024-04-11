#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool b[100001];
int n, c[100001], len, ans[100001][2];
vector<int> a[100001];

int main(){
    memset(b, false, sizeof(b));
    b[1] = true; len = 0;
    for (int i = 2; i <= 100000; i++)
    {
        if (!b[i]) c[++len] = i;
        for (int j = 1; j <= len; j++)
            if (i * c[j] > 100000) break;
            else 
            {
                b[i * c[j]] = true;
                if (!(i % c[j])) break;
            }
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 2; i <= n; i++)
    {
        bool yourenyao = false;
        int now = i;
        for (int j = 1; c[j] * c[j] <= now; j++)
            if (!(now % c[j]))
            {
                if (c[j] != 2) 
                {
                    yourenyao = true; 
                    a[c[j]].push_back(i);
                    break;
                }
                for (; !(now % c[j]); now /= c[j]);
            }
        if (!yourenyao && now > 2) a[now].push_back(i);
        else if (!yourenyao) a[2].push_back(i);
    }
    int cnt = 0;
    for (int i = n; i > 2; --i)
        if (a[i].size() & 1)
            if (a[i].size() == 1) continue;
            else 
            {
                //printf("%d\n", i);
                for (int j = a[i].size() - 1; j > 2; j -= 2) ans[++cnt][0] = a[i][j], ans[cnt][1] = a[i][j - 1];
                ans[++cnt][0] = a[i][2]; ans[cnt][1] = a[i][0];
                a[2].push_back(a[i][1]);
            }
        else
            for (int j = a[i].size() - 1; j > 0; j -= 2) ans[++cnt][0] = a[i][j], ans[cnt][1] = a[i][j - 1];
    for (int j = a[2].size() - 1; j > 0; j -= 2) ans[++cnt][0] = a[2][j], ans[cnt][1] = a[2][j - 1];
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d %d\n", ans[i][0], ans[i][1]);
}