#include<bits/stdc++.h>
using namespace std;
string a, s;


bool solve() {
    cin >> a >> s;
    string b;
    while (s.size() && a.size()) {
        if (a.back() <= s.back()) {
            b += s.back() - a.back() + '0';
            a.pop_back(); s.pop_back();
        } else {
            char foo = s.back();
            s.pop_back();
            if (s.empty()) return false;
            if (s.back() != '1') return false;
            s.pop_back();
            b += foo + 10 - a.back() + '0';
            a.pop_back();
        }
    }
    if (!a.empty()) return false;
    reverse(b.begin(), b.end());
    b = s + b;
    reverse(b.begin(), b.end());
    while(b.back() == '0') b.pop_back();
    reverse(b.begin(), b.end());
    cout << b << '\n';
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        if (!solve()) {
            cout << "-1\n";
        }
    }
}