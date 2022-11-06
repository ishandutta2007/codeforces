#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, a[N], b[N];

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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1)
            cout << "FastestFinger\n";
        else if (n == 2)
            cout << "Ashishgup\n";
        else {
            int x = 1;
            int nn = n;
            while (n % 2 == 0)
                n /= 2, x *= 2;
            if (x == nn)
                cout << "FastestFinger\n";
            else
            if (x != 2) {
                cout << "Ashishgup\n";
            } else {
                n = nn;
                n /= 2;
                if (is_prime(n))
                    cout << "FastestFinger\n";
                else
                    cout << "Ashishgup\n";
            }
        }
    }
    return 0;
}