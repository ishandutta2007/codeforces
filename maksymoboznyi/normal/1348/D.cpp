#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 1e5 + 5;

int n, k, kol[26];
string s;
string q[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int o;
    cin >> o;
    while (o--) {
        int n;
        cin >> n;
        if (n == 2) {
            cout << "1\n0\n";
            continue;
        }
        n--;
        int sum = 0, x = 2;
        vector<int> all;
        all.pb(1);
        while (sum + x < n)
            all.pb(x), sum += x, x *= 2;
        x = n - sum;
        if (x >= all.back()) {
            all.pb(x);
            cout << all.size() - 1 << "\n";
            for (int i = 1; i < all.size(); i++)
                cout << all[i] - all[i - 1] << ' ';
            cout << "\n";
            continue;
        }
        int k;
        if ((all.back() - x) % 2 == 0) {
            k = (all.back() - x) / 2;
            all.back() -= k;
            all.pb(x + k);
            cout << all.size() - 1 << "\n";
            for (int i = 1; i < all.size(); i++)
                cout << all[i] - all[i - 1] << ' ';
            cout << "\n";
            continue;
        }
        k = (all.back() - x + 1) / 2;
        //cout << k << endl;
        all.back() -= k;
        all.pb(x + k);
        cout << all.size() - 1 << "\n";
        for (int i = 1; i < all.size(); i++)
            cout << all[i] - all[i - 1] << ' ';
        cout << "\n";
    }
    return 0;
}