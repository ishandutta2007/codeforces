#include<bits/stdc++.h>
using namespace std;
const int nax = 128;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1);
    int64_t sum = 0;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i], sum += a[i];
    vector <bool> toggle(n + 1, true);
    vector <int> buffer(n);
    iota(buffer.begin(), buffer.end(), 1);
    int last_val = -1;

    while (q --) {
        int t; cin >> t;
        if (t == 1) {
            int pos, val;
            cin >> pos >> val;
            if (toggle[pos]) {
                sum -= a[pos];
                sum += (a[pos] = val);
            } else {
                sum -= last_val;
                sum += (a[pos] = val);
                toggle[pos] = true;
                buffer.push_back(pos);
            }
        } else {
            for (int j : buffer) toggle[j] = false;
            buffer.clear();
            cin >> last_val;
            sum = 1ll * last_val * n;
        }
        cout << sum << '\n';
    }
}
/*
    GCJ
*/