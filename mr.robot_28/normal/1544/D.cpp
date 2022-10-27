#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
//#define int long long
using namespace std;
const int mod = 998244353;
const int N = 2e6;
vector <int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vector <int> dy = {-1, 0, 1, 1, -1, 0, 1, -1};
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;
        }
        vector <bool> used(n);
        vector <bool> used1(n);
        for(int i = 0; i < n; i++)
        {
            if(!used[a[i]])
            {
                used1[i] = 1;
                used[a[i]] = 1;
            }
        }
        int f1 = -1;
        int f = -1;
        int cnt1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(!used1[i])
            {
                f = i;
                cnt1++;
            }
            if(!used[i])
            {
                f1 = i;
            }
        }
        if(cnt1 == 1 && f1 == f)
        {
            cout << n - 1 << "\n";
            for(int i = 0; i < n; i++)
            {
                if(used1[i] && a[i] == a[f])
                {
                    a[i] = f;
                }
            }
            for(int i = 0; i < n; i++)
            {
                cout << a[i] + 1 << " ";
            }
            cout << "\n";
            continue;
        }
        int it = 0;
        vector <int> vec;
        int am;
        for(int i = 0; i < n; i++)
        {
            if(!used1[i] && !used[i])
            {
                vec.push_back(i);
            }
            else if(!used[i])
            {
                am = i;
            }
        }
        if(sz(vec) == 1)
        {
            a[vec[0]] = am;
            used[am] = 1;
            used1[vec[0]] = 1;
        }
        else
        {
        for(int i = 0; i < sz(vec); i++)
        {
            a[vec[i]] = vec[( i + 1) % sz(vec)];
            used1[vec[i]] = used[vec[i]] = 1;
        }
        }
        it = 0;
        for(int i = 0; i < n; i++)
        {
            if(!used1[i])
            {
                while(used[it])
                {
                    it++;
                }
                a[i] = it;
                used[it] = 1;
            }
        }
        cout << n - cnt1 << "\n";
        for(int i =0; i < n; i++)
        {
            cout << a[i] + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}