
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
    int len = 0;
    while((len + 1) + (len + 1) / 2 <= n) len++;
    assert(len + len / 2 == n || len + (len + 1) / 2 == n);
    string s(len, '1');
    int start = 1;
    if(len + (len + 1) / 2 == n) {
        start = 0;
    }
    for(int i = start; i < len; i += 2) {
        s[i] = '2';
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}