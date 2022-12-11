#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int n, a[1111111], b[1111111];
long long vv[1111111];

struct summator
{
    long long a[1111111];
    summator()
    {
        for (int i = 0; i < 1111111; i++) a[i] = 0;
    }
    long long fsum(int x)
    {
        long long res = 0;
        while (x > 0)
        {
            res += a[x];
            x = x & (x - 1);
        }
        return res;
    }
    void modify(int x, long long val)
    {
        while (x < 1111111)
        {
            a[x] += val;
            x = 2 * x - (x & (x - 1));
        }
    }
};

map<int, int> mp;
summator ss, ss1;

int main()
{
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];

    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        mp[b[i]] = i;
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int xx = mp[a[i]];
        long long val = ss.fsum(xx);
        vv[xx] = val;
        //cout << xx << " " << val << endl;
        ss.modify(xx, 1);
    }
    for (int i = n; i >= 1; i--)
    {
        int xx = mp[a[i]];
        long long val = ss1.fsum(xx);
        ans += val;
        //cout << val << endl;
        ss1.modify(xx, vv[xx]);
    }
    cout << ans;
    return 0;
}