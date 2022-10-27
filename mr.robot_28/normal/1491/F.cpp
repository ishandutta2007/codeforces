#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define sz(a) (int)a.size()
#define X first
#define Y second

signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int st;
        vector <bool> used(n);
        for(int i = 1; i < n; i++)
        {
            cout << "? " << i << " " << 1 << endl;
            for(int j = 0; j < i; j++)
            {
                cout << j + 1 << " ";
            }
            cout << endl;
            cout << i + 1 << endl;
            int v;
            cin >> v;
            if(v != 0)
            {
                st = i;
                break;
            }
        }
        for(int i = st + 1; i < n; i++)
        {
            cout << "? " << 1 << " " << 1 << endl;
            cout << st + 1 << endl;
            cout << i + 1 << endl;
            int v;
            cin >> v;
            if(v != 0)
            {
                used[i] = 1;
            }
        }
        used[st] = 1;
        int l = -1, r = st - 1;
        while(r - l > 1)
        {
            int midd = (r + l) / 2;
            cout << "? " << midd + 1 << " " << 1 << endl;
            for(int i = 0; i <= midd; i++)
            {
                cout << i + 1 << " ";
            }
            cout << endl;
            cout << st + 1 << endl;
            int v;
            cin>> v;
            if(v == 0)
            {
                l = midd;
            }
            else
            {
                r = midd;
            }
        }
        used[r] = 1;
        vector <int> ans;
        for(int i = 0; i < n; i++)
        {
            if(!used[i])
            {
                ans.push_back(i + 1);
            }
        }
        cout << "! " << ans.size() << " ";
        for(auto v : ans)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}