#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 2e5 + 5;

int n;

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
        if (n == 1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n - 2; i++)
            cout << '8';
        cout << "58\n";

    }
    return 0;
}