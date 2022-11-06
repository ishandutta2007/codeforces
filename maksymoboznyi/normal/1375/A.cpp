#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 3e5 + 5;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i % 2 == 0)
                if (x < 0)
                    cout << x << ' ';
                else
                    cout << -x << ' ';
            else
                if (x < 0)
                    cout << -x << ' ';
                else
                    cout << x << ' ' ;
        }
        cout << "\n";
    }
    return 0;
}