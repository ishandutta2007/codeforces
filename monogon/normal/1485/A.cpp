
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
        ll a, b;
        cin >> a >> b;
        int ops = 0;
        if(b == 1) {
            b++;
            ops++;
        }
        int best = INT_MAX;
        rep(x, 0, sqrt(a) + 1) {
            int o = x;
            ll aa = a;
            while(aa > 0) {
                aa /= (b + x);
                o++;
            }
            best = min(ops + o, best);
        }
        cout << best << '\n';
    }
}