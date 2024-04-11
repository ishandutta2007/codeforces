#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int a[Maxn];

int getMex()
{
    set <int> S;
    for (int i = 1; i <= n; i++)
        S.insert(a[i]);
    int cur = 0;
    while (S.count(cur)) cur++;
    return cur;
}

int findInd()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != i - 1) return i;
    return -1;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        vector <int> res;
        while (true) {
            int m = getMex();
            if (m >= n) {
                int ind = findInd();
                if (ind == -1) break;
                res.push_back(ind);
                a[ind] = m;
            } else {
                res.push_back(m + 1);
                a[m + 1] = m;
            }
        }
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}