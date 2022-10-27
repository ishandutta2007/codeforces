#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
#define int int64_t
int n;
int a[nax];
int b[nax];
int sa[nax];
int sb[nax];

void solve() {

    cin >> n;
    for (int i = 1 ; i <= n;  ++ i)
        cin >> sa[i];
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> sb[i];
    }

    int cur = 0;
    for (int k = 29, v = 0 ; k >= 0 ; -- k) {
        int t = cur | (1 << k);
        /**
            how is checking bit by bit wrong?
            Ok, first, look at 29th bit,
            0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0
            1 1 1 1 1 1 1 1 1 0 0 0 0 1 1 1
            it must be completely matched, then, it's confirmed that
            Ok, if we can, it means the answer is 1.....
            if not?
            The answer is obviously 0.......

            NO!, that's where you are wrong!
            It's fine to have something not according to this, but
        */
        v |= (1 << k);
        for (int i = 1 ; i <= n ;++ i) {
            a[i] = sa[i] & v & t;
            b[i] = sb[i] & v & t;
        }
        vector <int> x, y;
        for (int i = 1 ; i <= n ; ++ i) {
            x.push_back(b[i]);
            y.push_back(t ^ a[i]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        if (x == y) cur = t;
    }
    cout << cur << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;


    for (cin >> T ; T -- ;) {
        solve();
    }
}