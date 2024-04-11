#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111;

int f[max_n], s[max_n];
int both[max_n * 2];
pair<int, int> sp[max_n];
int n, m, k;

bool check(int mc)
{
    merge(f, f + n, s + m - mc, s + m, both);
    int len = n + mc;
    int curday = 0, curm = 0;
    while(true)
    {
        for(int i = 0; i < k; ++i)
        {
            if (curm == len) return true;
            if (both[curm] < curday) return false;
            curm++;
        }
        curday++;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", f + i);
    }
    sort(f, f + n);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &sp[i].F);
        sp[i].S = i;
    }

    sort(sp, sp + m);
    for (int i = 0; i < m; ++i)
    {
        s[i] = sp[i].F;
    }

    if (check(0) == false)
    {
        cout << -1;
        return 0;
    }

    int l = 0, r = m + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;
    for (int i = 0; i < l; ++i)
    {
        printf("%d ", sp[m - i - 1].S + 1);
    }

    return 0;
}