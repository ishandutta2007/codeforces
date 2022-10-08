
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
    string s, t;
    cin >> s >> t;
    if(s.length() != t.length()) {
        cout << "NO\n";
        return 0;
    }
    auto vowel = [&](char c) {
        return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
    };
    int n = s.length();
    rep(i, 0, n) {
        if(vowel(s[i]) != vowel(t[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}