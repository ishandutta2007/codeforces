#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5+5;
stack <pair<int, int> > q;
int n, a[N], go[N];
struct cell
{
    int max_l, max_r, or_l, or_r;
};
bool d[N][35];
cell b[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ///maski
    for (int i = 1; i <= n; i++)
    {
        int q = a[i], k = 1;
        while (q != 0)
        {
            d[i][k] = q % 2;
            q /= 2;
            k++;
        }
    }
    ///max_l
    q.push({0, 2e9});
    for (int i = 1; i <= n; i++)
    {
     //   cout << i << endl;
        while (q.top().second <= a[i])
            q.pop();
   // cout << i << endl;
        b[i].max_l = q.top().first;
        //cout << i << endl;
        q.push({i, a[i]});
      //  cout << i << endl;
    }
    //cout << 1;
    while (!q.empty())
        q.pop();
    //cout << 1;
    ///max_r
    q.push({n+1, 2e9});
    for (int i = n; i > 0; i--)
    {
        while (q.top().second < a[i])
            q.pop();
        b[i].max_r = q.top().first;
        q.push({i, a[i]});
    }
    while (!q.empty())
        q.pop();
    ///or_l
    for (int i = 1; i <= n; i++)
    {
        int k = 0;
        for (int j = 1; j < 35; j++)
            if (d[i][j] == 0)
                k = max(k, go[j]);
            else
                go[j] = i;
        b[i].or_l = k;
    }
    ///or_r
    for (int i = 1; i < 35; i++)
        go[i] = n+1;
    for (int i = n; i > 0; i--)
    {
        int k = n + 1;
        for (int j = 1; j < 35; j++)
            if (d[i][j] == 0)
                k = min(k, go[j]);
            else
                go[j] = i;
        b[i].or_r = k;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        if (b[i].max_l >= b[i].or_l)
            if (b[i].max_r <= b[i].or_r)
                continue;
            else
                ans += (i-b[i].max_l)*(b[i].max_r - b[i].or_r);
        else
            if (b[i].max_r <= b[i].or_r)
                ans += (b[i].or_l - b[i].max_l)*(b[i].max_r-i);
            else
            {
          //      cout << i << endl;
                ans += (b[i].or_l - b[i].max_l)*(b[i].or_r - i);
                ans += (b[i].max_r - b[i].or_r)*(i - b[i].or_l);
                ans += (b[i].or_l - b[i].max_l)*(b[i].max_r - b[i].or_r);
            }
        //cout << ans << ' ' << i << endl;
    }
    cout << ans;
    return 0;
}