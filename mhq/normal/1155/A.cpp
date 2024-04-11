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
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] > s[i + 1]) {
            cout << "YES" << '\n' << i + 1 << " " << i + 2;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}