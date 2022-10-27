#include<bits/stdc++.h>
using namespace std;
#define int long long
int go_to(int ind, int n, int l, int r)
{
    if(l > r)
    {
        exit(0);
   }
    if(ind == (r + l) / 2)
    {
        return n % 2;
    }
    n /= 2;
    if(ind < (r + l) / 2)
    {
        return go_to(ind, n, l, (r + l) / 2- 1);
    }
    else
    {
        return go_to(ind, n, (r + l) / 2 + 1, r);
    }
}
int rec(int n)
{
    if(n  <= 1)
    {
        return 1;
    }
    return 1 + rec(n / 2) * 2;
}
signed main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    int len = rec(n);
    int ans = 0;
    for(int i = l; i <= r; i++)
    {
        ans += go_to(i, n, 1, len);
    }
    cout << ans;
    return 0;
}