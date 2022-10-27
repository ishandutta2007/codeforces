
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector <pair <int, int> > x(n);
        for(int i = 0; i < n; i++)
        {
            cin >> x[i].first >> x[i].second;
        }
        bool flag = 0;
        for(int i = 0; i < n; i++)
        {
            bool fl = 1;
            for(int j = 0; j < n; j++)
            {
                if(abs(x[i].first - x[j].first) + abs(x[i].second - x[j].second) > k)
                {
                    fl = 0;
                }
            }
            flag = flag | fl;
        }
        if(flag)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}