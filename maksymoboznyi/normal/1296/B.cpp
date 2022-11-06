#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;

int n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long s;
        cin >> s;
        long long sum = 0;
        while (s >= 10) {
            sum += s - s % 10;
            int x = s % 10;
            s = s / 10 + x;
        }
        sum += s;
        cout << sum << "\n";
    }
    return 0;
}