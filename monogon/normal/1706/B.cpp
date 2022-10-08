
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
    int n;
    cin >> n;
    vector<string> ve(n + 1);
    rep(i, 0, n) {
        int x;
        cin >> x;
        ve[x].push_back(i % 2 == 0 ? 'a' : 'b');
    }
    rep(idx, 1, n + 1) {
        string &s = ve[idx];
        char c = 'c';
        int cnt = 0;
        for(char ch : s) {
            if(c != ch) {
                c = ch;
                cnt++;
            }
        }
        cout << cnt << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}