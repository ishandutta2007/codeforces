
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

ll ask(const vi &v) {
    if(v.empty()) return 0;
    cout << "? " << sz(v);
    for(int x : v) {
        cout << ' ' << x + 1;
    }
    cout << endl;
    ll ans;
    cin >> ans;
    return ans;
}

const int N = 1005;
int n;
ll mask[N];
vi query[13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi perm(13, 1);
    rep(i, 0, 6) perm[i] = 0;
    rep(i, 0, n) {
        rep(op, 0, 13) {
            if(perm[op]) query[op].push_back(i);
        }
        next_permutation(all(perm));
    }
    rep(op, 0, 13) {
        ll ans = ask(query[op]);
        rep(i, 0, n) {
            if(!binary_search(all(query[op]), i)) {
                mask[i] |= ans;
            }
        }
    }
    cout << "! ";
    rep(i, 0, n) {
        cout << mask[i] << ' ';
    }
    cout << endl;
}