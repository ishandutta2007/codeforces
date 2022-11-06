#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
#define int long long
using namespace std;

const int N = 1e5 + 5;

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> pr;
    for (int i = 2; i <= 3200; i++)
        if (is_prime(i))
            pr.pb(i);
    int n;
    cin >> n;
    vi d1, d2;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int a = -1;
        for (auto y: pr)
            if (x % y == 0 && x != y) {
                a = y;
                break;
            }
        //cout << a << endl;
        if (a == -1) {
            d1.pb(-1);
            d2.pb(-1);
            continue;
        }
        while (x % a == 0)
            x /= a;
        if (x == 1) {
            d1.pb(-1);
            d2.pb(-1);
            continue;
        }
        d1.pb(a);
        d2.pb(x);
    }
    for (auto x: d1)
        cout << x << ' ';
    cout << "\n";
    for (auto x: d2)
        cout << x << ' ';

    return 0;
}