
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

const int N = 1e5 + 5;
int n;
ll a[N];

bool lucky(ll k) {
    while(k > 0) {
        int d = k % 10;
        if(d != 4 && d != 7) return false;
        k /= 10;
    }
    return true;
}

int pos[N], invpos[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    vector<pii> luck;
    rep(i, 0, n) {
        cin >> a[i];
        ve.emplace_back(a[i], i);
        if(lucky(a[i])) luck.emplace_back(a[i], i);
        pos[i] = i;
        invpos[i] = i;
    }
    bool sorted = true;
    rep(i, 1, n) {
        if(a[i] < a[i - 1]) sorted = false;
    }
    if(sorted) {
        cout << "0\n";
        return 0;
    }
    if(luck.empty()) {
        cout << "-1\n";
        return 0;
    }
    vector<pii> ops;
    sort(all(ve));
    // pos[i] = where is original a[i] now?
    // invpos[i] = what index was current a[i] in originally?
    auto doswap = [&](int i, int j) {
        if(i != j) {
            ops.emplace_back(i, j);
            swap(pos[invpos[i]], pos[invpos[j]]);
            swap(invpos[i], invpos[j]);
        }
    };
    rep(i, 0, n) {
        if(!lucky(ve[i].first)) {
            // move ve[i].first to position i
            if(pos[ve[i].second] != i) {
                int p = pos[luck[0].second];
                doswap(i, p);
                doswap(i, pos[ve[i].second]);
            }
        }
    }
    rep(i, 0, n) {
        if(lucky(ve[i].first)) {
            if(pos[ve[i].second] != i) {
                doswap(pos[ve[i].second], i);
            }
        }
    }
    cout << sz(ops) << '\n';
    for(auto &pa : ops) {
        cout << pa.first+1 << ' ' << pa.second+1 << '\n';
    }
}