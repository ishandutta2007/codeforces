#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    string s;
    cin >> s;

    if((int)s.size() % 2) {
        cout << -1 << "\n";
        return true;
    }

    int cl, cr, cu, cd;
    cl = cr = cu = cd = 0;

    for(char c : s) {
        if(c == 'L') cl++;
        else if(c == 'R') cr++;
        else if(c == 'U') cu++;
        else cd++;
    }

    cout << (int)s.size() / 2 - min(cl, cr) - min(cu, cd) << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}