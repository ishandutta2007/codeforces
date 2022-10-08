
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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    for(int mask = 0; ; mask++) {
        rep(i, 0, n) {
            bool flag = false;
            rep(j, 0, m) {
                if(((a[i] & b[j]) | mask) == mask) {
                    flag = true;
                    break;
                }
            }
            if(!flag) goto hell;
        }
        cout << mask << '\n';
        return 0;
        hell:;
    }
}