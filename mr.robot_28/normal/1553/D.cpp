#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s, t;
        cin >> s >> t;
        bool fl = 1;
        int j = sz(s) - 1;
        for(int i = sz(t) - 1; i >= 0; i--)
        {
            while(j >= 0 && s[j] != t[i])
            {
                j -= 2;
            }
            if(j < 0)
            {
                fl = 0;
                break;
            }
            j --;
        }
        if(fl)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}