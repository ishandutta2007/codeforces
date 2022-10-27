#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 100;

signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    cout << "? " << 1 << endl;
    vector <int> d(n);
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
        if(d[i] % 2 == 0)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    vector <pair <int, int> > ans;
    if(cnt1 <= cnt2)
    {
        for(int j = 0; j < n; j++)
        {
            if(d[j] == 1)
            {
                ans.push_back({0, j});
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(d[i] % 2 == 0)
            {
                cout << "? " << i + 1 << endl;
                for(int j = 0; j < n; j++)
                {
                    int x;
                    cin >> x;
                    if(x == 1)
                    {
                        ans.push_back({i, j});
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(d[i] % 2 == 1)
            {
                cout << "? " << i + 1 << endl;
                for(int j = 0; j < n; j++)
                {
                    int x;
                    cin >> x;
                    if(x == 1)
                    {
                        ans.push_back({i, j});
                    }
                }
            }
        }
    }
    cout << "!" << endl;
    for(auto p : ans)
    {
        cout << p.X + 1 << " " << p.Y + 1 << endl;
    }
    return 0;
}