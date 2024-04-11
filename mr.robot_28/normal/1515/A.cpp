#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;
const int N = 2e5+ 100;


signed main()
{
  //  ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n >> x;
        vector <int> w(n);
        for(int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        int s = 0;
        bool fl = 1;
        for(int i = 0; i < n; i++)
        {
            s += w[i];
            if(s == x)
            {
                if(w[n - 1] > w[i])
                {
                    swap(w[i], w[n - 1]);
                    break;
                }
                if(i != n - 1 && w[0] < w[n - 1])
                {
                    swap(w[0], w[n - 1]);
                    break;
                }
                fl = 0;
                break;
            }
        }
        if(fl)
        {
            cout << "YES\n";
            for(int i = 0; i < n; i++)
            {
                cout << w[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}