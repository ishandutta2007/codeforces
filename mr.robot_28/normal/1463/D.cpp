#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;

signed main()
{
 //   ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> b(n);
        vector <bool> used(n * 2 + 1);
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
            used[b[i]] = 1;
        }
        sort(b.begin(), b.end());
        int l =-1, r = n + 1;
        while(r - l > 1)
        {
            int midd = (r + l) / 2;
            set <int> st;
            for(int i = 1; i <= n * 2; i++)
            {
                if(!used[i])
                {
                    st.insert(i);
                }
            }
            bool fl = 1;
            for(int i = midd - 1; i >= 0; i--)
            {
                if(*st.rbegin() < b[i])
                {
                    fl = 0;
                    break;
                }
                st.erase(*st.rbegin());
            }
            if(!fl)
            {
                r = midd;
                continue;
            }
            for(int i = n - 1; i >= midd; i--)
            {
                if(*st.rbegin() > b[i])
                {
                    fl = 0;
                    break;
                }
                st.erase(*st.rbegin());
            }
            if(!fl)
            {
                l = midd;
            }
            else
            {
                r = midd;
            }
        }
        int l1 = -1, r1 = n + 1;
        while(r1  - l1 > 1)
        {
            int midd = (l1 + r1) / 2;
            set <int> st;
            for(int i = 1; i <= n * 2; i++)
            {
                if(!used[i])
                {
                    st.insert(i);
                }
            }
            bool fl = 1;
            for(int i = midd - 1; i >= 0; i--)
            {
                if(*st.rbegin() < b[i])
                {
                    fl = 0;
                    break;
                }
                st.erase(*st.rbegin());
            }
            if(!fl)
            {
                r1 = midd;
            }
            else
            {
                l1 = midd;
            }
        }
        cout << l1 - l << "\n";
    }
    return 0;
}