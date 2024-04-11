#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

set<pii> s;

bool less_than(int u, int v) {
    if (s.find(pii(u, v)) != s.end()) return true;
    if (s.find(pii(v, u)) != s.end()) return false;

    cout << "? " << u << " " << v << endl; cout.flush();
    string p; cin >> p;

    if (p == "<") {
        s.insert(pii(u, v));
        return true;
    } else {
        s.insert(pii(v, u));
        return false;
    }
}

void solve() {
    s.clear();

    int n; cin >> n;

    auto o = [&](int u) {
        if (u <= n) return u + n;
        else return u - n;
    };

    vector<int> small;

    for (int i = 1; i <= n; ++i){
        if (less_than(i, o(i)))
            small.push_back(i);
        else
            small.push_back(o(i));
    }

    sort(small.begin(), small.end(), less_than);

    int a = small.back();
    small.pop_back();

    for (int i = 0; i + 1 < n; ++i){
        small.push_back(o(small[i]));
    }

    sort(small.begin(), small.end(), less_than);
    less_than(a, small[n - 1]);

    cout << "!" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}