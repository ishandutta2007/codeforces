#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int moves1 = (n - 11) / 2;
    int moves2 = (n - 11) / 2;
    for (int i = 0; i < n; i++) {
        if (s[i] == '8') {
            moves2--;
        }
        else {
            moves1--;
        }
        if (moves1 < 0) {
            cout << "NO";
            return 0;
        }
        else if (moves2 < 0) {
            cout << "YES";
            return 0;
        }
    }
    return 0;
}