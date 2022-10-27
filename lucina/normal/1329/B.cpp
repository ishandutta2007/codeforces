#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int d, md;

int solve () {
    cin >> d >> md;
    int start = 1;
    int max_bit = 1;
    while (start <= d) {
        start <<= 1;
        ++ max_bit;
    }
    -- max_bit;
    int ret = (d - (1 << (max_bit - 1)) + 1);

    int ans = 1;

    for (int i = 1 ; i < max_bit ; ++ i) {
        int t = (1 << (i - 1)) % md;
  //      cerr << t << ' ';
        ans = 1LL * ans * (t + 1) % md;
    }
  //  cerr << ret << endl;

    ans = 1LL * ans  * (ret + 1) % md;

    return ((ans - 1) + md) % md;
}

int main () {
    int T;

   ios::sync_with_stdio(false);
    cin.tie(0);

    for (cin >> T ; T -- ;) {
        cout << solve() << '\n';
    }
}
/*
    Good Luck
        -Lucina
*/