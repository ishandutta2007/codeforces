#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
            if (k % 2 == 1) {
                if (n / 2 < k) {
                    cout << "NO" << "\n";
                    continue;
                } else {
                    cout << "YES\n";
                    for (int i = 0; i + 1 < k; ++i) {
                        cout << 2 << ' ';
                        n -= 2;
                    }
                    cout << n << "\n";
                }
            } else {
                if (n < k) {
                    puts("NO");
                    continue;
                }
                puts("YES");
                for (int i = 0; i + 1 < k; ++i) {
                    cout << 1 << " ";
                    --n;
                }
                cout << n << "\n";
            }
        } else {
            if (k % 2 == 0) {
                puts("NO");
                continue;
            }
            if (n < k) {
                puts("NO");
                continue;
            }
            puts("YES");
            for (int i = 0; i + 1 < k; ++i) {
                cout << 1 << ' ';
                --n;
            }
            cout << n << "\n";
        }
    }

    return 0;
}