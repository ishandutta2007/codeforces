#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0;i < t; i++){
        int x;
        cin >> x;
        int kol = x / 3;
        x %= 3;
        if (x == 1 || x == 0) {
            cout << kol;
        } else
        cout << kol + 1;
        cout << "\n";
    }
    return 0;
}