
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
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    s.push_back('X');
    int n = s.length();
    int cnt = 0;
    vi ve;
    rep(i, 0, n) {
        if(s[i] == '.') {
            cnt++;
        }else {
            if(cnt >= b) {
                ve.push_back(cnt);
            }
            cnt = 0;
        }
    }
    sort(all(ve), greater<>());
    if(ve.empty() || ve[0] < a) {
        cout << "NO\n";
        return;
    }
    if(sz(ve) >= 2 && ve[1] >= 2 * b) {
        cout << "NO\n";
        return;
    }

    if(ve[0] >= 2 * b) {
        // must split ve[0]
        rep(x, 0, ve[0] - a + 1) {
            int y = ve[0] - x - a;
            int num = sz(ve) - 1 + (x >= b) + (y >= b);
            if(x < 2 * b && y < 2 * b && 
                    num % 2 == 0 && min({ve.back(), (x < b ? INT_MAX : x), (y < b ? INT_MAX : y)}) >= a) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
        return;
    }else {
        // may split anything >= a
        if(sz(ve) % 2 == 1 && ve.back() >= a) {
            cout << "YES\n";
            return;
        }else {
            cout << "NO\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}