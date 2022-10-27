#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()

using namespace std;

const int N = 5e5 + 100;
const int T = 350;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int n = a + b + c;
        int minb = (a > 0) + (b > 0) + (c > 0);
        int maxb = n - max(0, max(a, max(b, c)) * 2 - 1 - (a + b + c));
 //       cout << minb << " " << maxb << "\n";
        if(n - m >= minb && n - m <= maxb){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}