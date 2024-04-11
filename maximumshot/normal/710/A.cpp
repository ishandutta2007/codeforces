#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    char c, d;
    cin >> c >> d;

    int i, j;

    i = c - 'a';
    j = d - '0' - 1;

    int res = 0;

    for(int di = -1;di <= 1;di++) {
        for(int dj = -1;dj <= 1;dj++) {
            if(di == 0 && dj == 0) continue;
            int toi, toj;
            toi = i + di;
            toj = j + dj;
            if(toi >= 0 && toi <= 7 && toj >= 0 && toj <= 7)
                res++;
        }
    }

    cout << res << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}