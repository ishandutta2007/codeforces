
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

int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        fill(cnt, cnt + 26, 0);
        rep(i, 0, n) {
            string s;
            cin >> s;
            for(char c : s) {
                cnt[c - 'a']++;
            }
        }
        bool flag = true;
        rep(i, 0, 26) {
            flag &= ((cnt[i] % n) == 0);
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}