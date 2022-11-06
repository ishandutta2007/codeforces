#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define M 1000000007;
using namespace std;
const int N = 2e5+6;
int n, k[10];
int g(int y)
{
    int res = 0;
    while (y % 10 == 9)
    {
        y/=10;
        res++;
    }
    return res;
}
int s(int y)
{
    int res = 0;
    while (y > 0)
    {
        res++;
        y /= 10;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n <= 4)
      {
        cout << n*(n-1)/2;
         return 0;
}
    int x = 0, pp = s(n);
    for (int i = 1; i <= pp; i++)
    {
        x*=10, x+=9;
    }
    int y = 5;
    for (int i = 1; i < pp; i++)
        y *= 10;
    if (x-n < n)
    {
        if (n == x)
            n--;
        cout << n-y+1;
    }else {
    x  /= 10;
    y /= 10;
    int ans = x-y+1;
    int p = n, q = 0;
    while (p > 0)
    {
        q = p % 10;
        p /= 10;
    }
    if (s(n) == 1)
        cout << ans-1;
    else
    {
        int p = 1;
        while (p*10 <= n)
            p*=10;
        int last = n%p, an = 0;
        for (int i = 1; i < q; i++)
            for (int j = i+1; j < q; j++)
                an += 2*ans;
        for (int i = 1; i < q; i++)
        {
            an += ans;
        }
        for (int i = 1; i < q; i++)
        {
            an += 2*ans-1;
        }
        an += ans-1;
        if (last == x)
            an += last;
        else
            an += last+1;
        for (int i = 1; i < q; i++)
        {
            an += last+1;
        }
        long long h = 0;
        an += max(h, last - y+1);
        cout << an;
    }
    }
    return 0;
}