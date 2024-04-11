#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(q) (q).begin(), (q).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;



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
        double r = 1.0 / (2 * sin(2 * acos(-1) / 4 / n));
        double ang = (2 * acos(-1) / 2 / n * (n - 1));
        double c = sqrt(2 * r * r - 2 * r * r * cos(ang));
        cout << fixed << setprecision(7)  << c << "\n";
    }
    return 0;
}