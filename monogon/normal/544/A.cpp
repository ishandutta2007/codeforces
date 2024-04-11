
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

int n, k;
string s;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> s;
    n = s.length();
    set<char> sc;
    for(char c : s) sc.insert(c);
    if(k > sz(sc)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES";
    rep(i, 0, n) {
        if(cnt[s[i] - 'a'] == 0 && k > 0) {
            cout << '\n';
            k--;
        }
        cout << s[i];
        cnt[s[i] - 'a']++;
    }
    cout << '\n';
}