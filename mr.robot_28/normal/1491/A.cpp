#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz(a) (int)a.size()
#define X first
#define Y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt += a[i];
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x;
            cin >> x;
            x--;
            if(a[x] == 0)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            a[x] ^= 1;
        }
        else
        {
            int k;
            cin >> k;
            cout << (cnt >= k) << "\n";
        }
    }
    return 0;
}