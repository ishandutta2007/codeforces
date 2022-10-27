#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 5;

void solve() {
    int n;
    cin >> n;

    vector <int> x(n + 2);
    for (int &i : x)
        cin >> i;
    sort(x.begin(), x.end());
    int64_t sum = accumulate(x.begin(), x.end(), 0LL);

    {
        int w = x.back();
        sum -= w;
        for (int j = 0 ; j < n + 1 ; ++ j) {
            if (w == sum - x[j]) {
                for (int i = 0 ; i < n + 1 ; ++ i) {
                    if (i != j) cout << x[i] << ' ';
                }
                cout << '\n';
                return;
            }
        }
        sum += w;
    }

    {
        sum -= x.back();
        sum -= x[n];
        int w = x[n];
        if (w == sum) {
            for (int j = 0 ; j < n ; ++ j)
                cout << x[j] << ' ';
            cout << '\n';
            return;
        }
    }
    cout << "-1\n";

}

int main() {


    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    for (int _ = 1 ; _ <= T ; ++ _) {
        solve();
    }

}