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
int query(vector <int> vec)
{
    cout << "? ";
    for(auto p : vec)
    {
        cout << p + 1 << " ";
    }
    cout << endl;
    int x;
    cin>> x;
    return x;
}
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(n >= 2 * k && (k + n % k) % 2 == 0 && n % k != 0)
    {
        int ans = 0;
        for(int i = 0; i * k + 2 * k <= n; i++)
        {
            cout << "? ";
            for(int j = 1; j <= k; j++)
            {
                cout << i * k + j << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            ans = ans ^ x;
        }
        int p = ((n % k) + k) / 2;
        for(int i = 0; i < p * 2; i += p)
        {
            cout << "? ";
            for(int j = 0; j < k - p; j++)
            {
                cout << j + 1 << " ";
            }
            for(int j = 0; j < p; j++)
            {
                cout << (n - i - j) << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            ans = ans ^ x;
        }
        cout << "! " << ans << endl;
    }
    else if((n % k) % 2 == 0)
    {
        int ans = 0;
        for(int i = 0; i * k + k <= n; i++)
        {
            cout << "? ";
            for(int j = 1; j <= k; j++)
            {
                cout << i * k + j << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            ans = ans ^ x;
        }
        int p = (n % k) / 2;
        for(int i = 0; i < p * 2; i += p)
        {
            cout << "? ";
            for(int j = 0; j < k - p; j++)
            {
                cout << j + 1 << " ";
            }
            for(int j = 0; j < p; j++)
            {
                cout << (n - i - j) << " ";
            }
            cout << endl;
            int x;
            cin >> x;
            ans = ans ^ x;
        }
        cout << "! " << ans << endl;
    }
    else if(n % 2 == 0)
    {
        int ans = 0;
        int p = min(k - 1, n - k);
        for(int i = 0; i + 2 * p <= n; i += 2 * p)
        {
            cout << "? ";
            vector <int> vec;
            for(int j = 0; j < n; j++)
            {
                if(sz(vec) < k - p && (j < i || j >= i + 2 * p))
                {
                    vec.push_back(j);
                }
            }
            for(int j = i; j < i + p; j++)
            {
                cout << j + 1 << " ";
            }
            for(auto v : vec)
                cout << v + 1 << " ";
            cout << endl;
            int x;
            cin >> x;
            cout << "? ";
            for(int j = i + p; j < i + 2 * p; j++)
            {
                cout << j + 1 << " ";
            }
            for(auto v : vec)
            {
                cout << v + 1 << " ";
            }
            cout << endl;
            int x1;
            cin >> x1;
            ans = ans ^ x ^ x1;
        }
        p = (n % (2 * p)) / 2;
        if(p != 0)
        {
            int i = n - 2 * p;
            cout << "? ";
            vector <int> vec;
            for(int j = 0; j < n; j++)
            {
                if(sz(vec) < k - p && (j < i || j >= i + 2 * p))
                {
                    vec.push_back(j);
                }
            }
            for(int j = i; j < i + p; j++)
            {
                cout << j + 1 << " ";
            }
            for(auto v : vec)
                cout << v + 1 << " ";
            cout << endl;
            int x;
            cin >> x;
            cout << "? ";
            for(int j = i + p; j < i + 2 * p; j++)
            {
                cout << j + 1 << " ";
            }
            for(auto v : vec)
            {
                cout << v + 1 << " ";
            }
            cout << endl;
            int x1;
            cin >> x1;
            ans = ans ^ x ^ x1;
        }
        cout << "! " << ans;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}