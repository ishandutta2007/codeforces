
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

int query(vi magnets, vi maggots) {
    cout << "? " << sz(magnets) << ' ' << sz(maggots) << endl;
    for(int x : magnets) cout << x << ' ';
    cout << endl;
    for(int x : maggots) cout << x << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<bool> alive(n + 1, false);
    rep(i, 2, n + 1) {
        vi left, right;
        rep(j, 1, i) left.push_back(j);
        right.push_back(i);
        int q = query(left, right);
        if(q != 0) {
            int L = 1, R = i - 1;
            while(L < R) {
                int m = (L + R) / 2;
                vi pref;
                rep(i, 1, m + 1) pref.push_back(i);
                if(query(pref, right) == 0) {
                    L = m + 1;
                }else {
                    R = m;
                }
            }
            alive[i] = true;
            alive[L] = true;
            for(int j = i + 1; j <= n; j++) {
                int q = query({i}, {j});
                if(q != 0) {
                    alive[j] = true;
                }
            }
            break;
        }
    }
    vi grave;
    rep(i, 1, n + 1) if(!alive[i]) grave.push_back(i);
    cout << "! " << sz(grave) << '\n';
    for(int x : grave) cout << x << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}