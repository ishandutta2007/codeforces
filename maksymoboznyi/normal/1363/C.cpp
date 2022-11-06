#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
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
        int n, x;
        cin >> n >> x;
        int k = 0;
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a == x || b == x)
                k++;
        }
        if (k <= 1) {
            cout << "Ayush\n";
            continue;
        }
        if (n % 2)
            cout << "Ashish\n";
        else
            cout << "Ayush\n";
    }
    return 0;
}