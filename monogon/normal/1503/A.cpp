
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (s[i] == '1');
    }
    if(cnt % 2 == 1 || s[0] == '0' || s.back() == '0') {
        cout << "NO\n";
        return;
    }
    string a, b;
    int k = 0;
    bool flip = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            a.push_back(2 * k < cnt ? '(' : ')');
            b.push_back(a.back());
            k++;
        }else {
            a.push_back(flip ? '(' : ')');
            b.push_back(flip ? ')' : '(');
            flip = !flip;
        }
    }
    cout << "YES\n" << a << '\n' << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}