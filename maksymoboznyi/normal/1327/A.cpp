#include <iostream>
#define int long long
using namespace std;

const int N = 1e7 + 2;

int p[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= 1e7; i++)
        p[i] = p[i - 1] + 2 * i - 1;
    while (t--) {
        int n, k;
        cin >> n >> k;
        n -= p[k - 1];
        if (n <= 0 || n % 2 == 0 || n < 2 * k - 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}