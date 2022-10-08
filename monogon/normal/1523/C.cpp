
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
    vi ve;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if(a != 1) {
            while(!ve.empty() && ve.back() != a - 1) ve.pop_back();
            if(!ve.empty() && ve.back() == a - 1) {
                ve.pop_back();
            }
        }
        ve.push_back(a);
        rep(j, 0, sz(ve)) {
            cout << ve[j];
            if(j < sz(ve) - 1) cout << '.';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}