#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector <int> prefl(n), prefr(n);
        int bal = 0;
        vector <int> prefbal(n);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+')
            {
                bal++;
            }
            else
            {
                bal--;
            }
            prefbal[i] = bal;
            prefl[i] = prefr[i] = bal;
            if(i != 0)
            {
                prefl[i] =min(prefl[i], prefl[i - 1]);
                prefr[i] = max(prefr[i], prefr[i - 1]);
            }
            prefl[i] = min(prefl[i], 0);
            prefr[i] = max(prefr[i], 0);
        }
        vector <int> sufl(n + 1, 0), sufr(n + 1, 0);
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '+')
            {
                sufl[i]= min(0, sufl[i + 1] + 1);
                sufr[i] = max(0, sufr[i + 1] + 1);
            }
            else
            {
                sufl[i] = min(0, sufl[i + 1] - 1);
                sufr[i] = max(0, sufr[i + 1] - 1);
            }
        }
        for(int i = 0; i < n; i++)
        {
    //        cout << sufl[i] << " ";
        }
      //  cout << "\n";
        while(m--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int stbal = 0;
            int a = 0, b = 0, a1 = 0, b1 = 0;
            if(l != 0)
            {
                stbal = prefbal[l - 1];
                a = prefl[l - 1];
                b = prefr[l - 1];
            }
            if(r != n - 1)
            {
                a1 = sufl[r + 1] + stbal;
                b1 = sufr[r + 1] + stbal;
            }
            //cout << a << " " << b << " " << a1 << " " << b1 << "\n";
            a = min(a, a1);
            b = max(b, b1);
            cout << b - a + 1 << "\n";
        }
    }
    return 0;
}