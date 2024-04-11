#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int total(int n, int s) {
    if (s == 1) {
        return n;
    }

    int a = n % (s - 1);
    int b = n / (s - 1);

    if (a > b) return -1;
    return (n + s - 1) / s;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    vector<int> good(n + 2);

    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        a[--x]++;
    }

    int tot_diff = 0;
    int top = oo;

    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            tot_diff++;

            top = min(top, a[i] + 1);

            for (int s = 1; s <= a[i] + 1; ++s) {
                int t = total(a[i], s);

                if (t == -1) {
                    good[s] = oo;
                } else {
                    good[s] = min(good[s] + t, oo);
                }
            }
        }
    }

    int best = oo;

    for (int i = 1; i <= top; ++i){
        best = min(best, good[i]);
    }

    cout << best << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t-->0) {
        solve();
    }

    return 0;
}