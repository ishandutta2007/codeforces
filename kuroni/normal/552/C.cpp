#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, le = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    while (n > 0 || le > 0) {
        le += n % m; n /= m;
        int tmp = le % m; le /= m;
        if (tmp != 0 && tmp != 1 && tmp != m - 1) {
            return cout << "NO", 0;
        }
        if (m != 2 && tmp == m - 1) {
            le++;
        }
    }
    cout << "YES";
}