#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < k - 3; i++)
            cout << "1 ";
        n -= k - 3;
        if (n % 4 == 0)
            cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << '\n';
        else if (n % 2)
            cout << "1 " << n / 2 << ' ' << n / 2 << '\n';
        else
            cout << "2 " << n / 2 - 1 << ' ' << n / 2 - 1 << '\n';
    }
}