#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 1e5 + 5;



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
        string s;
        for (int i = 0; i < n; i++)
            s += '9';
        int cur = n - 1;
        for (int i = 0; i < n / 4; i++)
            s[cur] = '8', cur--;
        if (n % 4 != 0)
            s[cur] = '8';
        cout << s << "\n";
    }
    return 0;
}