
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// 1 1 1 1 1 1 1 1 1 (S - N + 1)
// what sum cannot be achieved? S / 2, assuming N - 1 < S / 2 < S - N + 1

int n, s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    if(n - 1 < s / 2 && s / 2 < s - n + 1) {
        cout << "YES\n";
        rep(i, 0, n - 1) {
            cout << "1 ";
        }
        cout << s - n + 1 << '\n';
        cout << s / 2 << '\n';
    }else {
        cout << "NO\n";
    }
}