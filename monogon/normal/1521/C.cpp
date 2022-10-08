
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

int ask(int t, int i, int j, int x) {
    cout << "? " << t << ' ' << i << ' ' << j << ' ' << x << endl;
    int ans;
    cin >> ans;
    if(ans == -1) exit(0);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int idx = -1;
    for(int i = 1; i + 1 <= n; i += 2) {
        int x = ask(2, i, i + 1, 1);
        if(x == 1) {
            idx = i;
            break;
        }else if(x == 2) {
            x = ask(2, i + 1, i, 1);
            if(x == 1) {
                idx = i + 1;
                break;
            }
        }
    }
    if(idx == -1) idx = n;
    vi p(n + 1);
    p[idx] = 1;
    rep(i, 1, n + 1) {
        if(i != idx) {
            p[i] = ask(1, idx, i, n - 1);
        }
    }
    cout << "! ";
    rep(i, 1, n + 1) cout << p[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}