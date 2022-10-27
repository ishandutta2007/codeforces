#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
string s;

void solve() {
    cin >> n >> s;
    n *= 2;
    vector <int> used;
    int c[2]{};
    for (int i = 0 ; i < n ; ++ i) {
        c[s[i] - '0'] += 1;
    }
    if (c[0] % 2 || c[1] % 2) {
        cout << "-1\n";
        return;
    }

    int cnt = 0;
    char cur = 0;
    char carry = 0;

    for (int i = 0 ; i < n ; ++ i) {
        if (cur == 0 || s[i] == cur) {
            cnt += 1;
            cur = s[i];
        } else {
            if (cnt % 2) {
                if (carry == (s[i] ^ 1)) {
                    used.push_back(i);
                    carry = s[i];
                    cur = s[i];
                    cnt = 0;
                } else {
                    used.push_back(i - 1);
                    carry = s[i - 1];
                    cnt = 1;
                    cur = s[i];
                    i -= 1;
                }
            } else {
                cnt = 1;
                cur = s[i];
            }
        }
    }
    string t = s;
    cout << used.size() << ' ';

    for (int i = 0 ; i < used.size() ; ++ i) {
        cout << used[i] + 1 << ' ';
    }
    cout << '\n';
    for (int i = 0 ; i < n ; i += 2) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}