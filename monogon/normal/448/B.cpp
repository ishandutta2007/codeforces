
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int n, m;
string s, t;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for(char c : s) cnt[c - 'a']++;
    for(char c : t) cnt[c - 'a']--;
    rep(i, 0, 26) {
        if(cnt[i] < 0) {
            cout << "need tree\n";
            return 0;
        }
    }
    if(n == m) {
        cout << "array\n";
        return 0;
    }
    int j = 0;
    rep(i, 0, n) {
        if(j < m && s[i] == t[j]) {
            j++;
        }
    }
    if(j == m) {
        cout << "automaton\n";
    }else {
        cout << "both\n";
    }
}