#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

pair<int,int> query(vector<int> q) {
    cout << "?";
    for (auto u : q) {
        cout << " " << u;
    }
    cout << endl; cout.flush();

    int p, v; cin >> p >> v;
    return make_pair(p, v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> q(k);
    iota(q.begin(), q.end(), 1);

    auto t = query(q);

    q[t.first - 1] = k + 1;
    auto tlast = query(q);

    int small = 0;

    bool was_smaller = tlast.second < t.second;

    q[t.first - 1] = t.first;

    for (int i = 1; i <= k; ++i) {
        if (i == t.first)
            continue;

        q[i - 1] = k + 1;
        auto tc = query(q);

        if (was_smaller) {
            if (tc.first == t.first) {
                small++;
            }
        } else {
            if (tc.first != t.first) {
                small++;
            }
        }

        q[i - 1] = i;
    }

    cout << "! " << small + 1 << endl;

    return 0;
}