#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

signed main() {
//    ios::sync_with_stdio(0);
  //  cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = n;
        while(i > 0 && s[i - 1] == ')')
        {
            i--;
        }
        if(i < n - i)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}