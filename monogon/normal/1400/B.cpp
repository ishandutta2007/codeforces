
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
    int te;
    cin >> te;
    while(te--) {
        ll p, f, s, w;
        int cnts, cntw;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if(s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }
        ll best = 0;
        rep(a, 0, cnts + 1) {
            if(1LL * a * s > p) continue;
            ll b = min(1LL * cntw, (p - 1LL * a * s) / w);
            ll A = min((ll) cnts - a, f / s);
            ll B = min((ll) cntw - b, (f - 1LL * A * s) / w);
            best = max(best, a + b + A + B);
        }
        cout << best << '\n';
    }
}