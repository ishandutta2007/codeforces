#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
const int N = 1e5;

ll is[200], n, m, k, f, maxn = 2000;
set<ll> ans;
int main()
{
    cin >> n >> m;
    if (m == 0)
    {

        if (n == 1)
            cout << 1;
        else
            cout << -1;
    return 0;
    }
    for (int i = 0; i < 200; i++)
        is[i] = 0;
    for (int j = 0; j < m; j++)
    {
        cin >> k >> f;
        if (k >= n)
            maxn = min(maxn, f);
        for (ll i = 1; i < 200; i++)
            if ((f-1)*i < k && f*i >= k)
             {
                 is[i]++;
         //       cout << i << endl;
             }
         //   cout << endl;
    }
    //cout << maxn;

    for (int i = 0; i < 200; i++)
        if (is[i] == m && (n-1)/i+1 <= maxn)
        {
            ans.insert((n-1)/i+1);
        }
    //cout << ans.size();
    if (ans.size() > 1)
        cout << -1;
    else
        cout << *ans.begin();
    return 0;
}