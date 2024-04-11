
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vi a;
    for(char c : s) a.push_back(c - 'A');
    int n = s.length();
    rep(i, 2, n) {
        if((a[i - 2] + a[i - 1]) % 26 != a[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}