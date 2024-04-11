#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int freq[Maxn], sum[Maxn];
vector <int> cnt[Maxn];
int BIT[Maxn];

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Insert(int x)
{
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i]++;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(freq, freq + Maxn, 0);
        for (int i = 1; i < Maxn; i++)
            cnt[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            freq[a[i]]++;
        }
        for (int i = 1; i < Maxn; i++)
            sum[i] = sum[i - 1] + freq[i];
        fill(BIT + 1, BIT + Maxn, 0);
        bool fall = false;
        for (int i = 1; i <= n; i++) {
            int lef = (i - 1) - Get(a[i]) + sum[a[i] - 1] - Get(a[i] - 1);
            cnt[a[i]].push_back(lef % 2);
            Insert(a[i]);
        }
        for (int i = 1; i < Maxn; i++) {
            int cand = 0;
            for (int j = 0; j < cnt[i].size(); j++)
                if (cnt[i][j])
                    if (j % 2 == 0) cand++;
                    else cand--;
            if (cand) fall = true;
        }
        printf("%s\n", fall? "NO": "YES");
    }
    return 0;
}