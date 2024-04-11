
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int a, b; cin >> a >> b;
    int n = a + b;
    string s;
    cin >> s;
    vector<int> pos2, pos1;
    auto no = [&]() {
        cout << -1 << '\n';
        return;
    };
    rep(i, 0, n / 2) {
        if(s[i] == '?') {
            if(s[n - i - 1] == '?') {
                pos2.push_back(i);
            }else {
                s[i] = s[n - i - 1];
            }
        }else if(s[n - i - 1] == '?') {
            s[n - i - 1] = s[i];
        }else if(s[i] != s[n - i - 1]) return no();
    }
    if(n % 2 == 1) {
        if(s[n / 2] == '?') {
            pos1.push_back(n / 2);
        }
    }
    rep(i, 0, n) {
        if(s[i] == '0') a--;
        if(s[i] == '1') b--;
    }
    if(a % 2 == 1 && b % 2 == 1) return no();
    if(a % 2 == 1) {
        if(pos1.empty()) return no();
        else {
            s[pos1[0]] = '0';
            a--;
        }
    }else if(b % 2 == 1) {
        if(pos1.empty()) return no();
        else {
            s[pos1[0]] = '1';
            b--;
        }
    }
    while(a > 0 && !pos2.empty()) {
        assert(!pos2.empty());
        a -= 2;
        int i = pos2.back(); pos2.pop_back();
        s[i] = '0';
        s[n - i - 1] = '0';
    }
    while(b > 0 && !pos2.empty()) {
        assert(!pos2.empty());
        b -= 2;
        int i = pos2.back(); pos2.pop_back();
        s[i] = '1';
        s[n - i - 1] = '1';
    }
    if(a > 0 || b > 0) return no();
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}