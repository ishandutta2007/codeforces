
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
    string a, s;
    cin >> a >> s;
    int n = a.length(), m = s.length();
    int j = m - 1;
    string b;
    for(int i = n - 1; i >= 0; i--) {
        if(j < 0) {
            cout << -1 << '\n';
            return;
        }
        if(s[j] >= a[i]) {
            b.push_back('0' + s[j] - a[i]);
            j--;
        }else {
            if(j == 0 || s[j - 1] != '1') {
                cout << -1 << '\n';
                return;
            }
            b.push_back('0' + 10 + s[j] - a[i]);
            j -= 2;
        }
    }
    while(j >= 0) {
        b.push_back(s[j]);
        j--;
    }
    while(b.size() > 1 && b.back() == '0') b.pop_back();
    reverse(all(b));
    cout << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}