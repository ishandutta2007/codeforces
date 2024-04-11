
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// [k (h + c) + h] / (2k + 1) = t
// k (h + c) + h = 2kt + t
// k (h + c - 2t) = t - h
// k = (t - h) / (h + c - 2t)

ll q, h, c, t;

bool better(int a, int b) {
    ll tmp1 = h * ((a + 1) / 2) + c * (a / 2);
    ll tmp2 = h * ((b + 1) / 2) + c * (b / 2);
    return b * abs(tmp1 - t * a) < a * abs(tmp2 - t * b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> h >> c >> t;
        if(t <= (h + c) / 2) {
            cout << "2\n";
        }else {
            ll k = max(0LL, (h - t) / (2 * t - h - c));
            ll opt = 2;
            if(better(2 * k + 1, opt)) opt = 2 * k + 1;
            if(better(2 * (k + 1) + 1, opt)) opt = 2 * (k + 1) + 1;
            cout << opt << '\n';
        }
    }
}