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
        double ang = acos(-1) * (2 * n - 2) / (2 * n);
        int kol = n / 2 - 1 + 3;
        double sum = acos(-1) * (kol - 2);
        //cout << sum << ' ' << kol << endl;
        sum -= acos(-1) / 2;
        sum -= (2 * acos(-1) - ang) * (kol - 3);
        //cout << ang << endl;
        //cout << sum << endl;
        double al = sum / 2;
        //cout << al + ang / 2 - acos(-1) / 2 << ' ' << r << endl;

        cout << fixed << setprecision(7) << 2 * r * cos(ang / 2 + al - acos(-1) / 2) << "\n";
    }
    return 0;
}