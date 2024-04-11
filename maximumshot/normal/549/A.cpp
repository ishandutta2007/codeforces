#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    string face = "face";
    sort(ALL(face));

    int n, m;
    cin >> n >> m;

    vec< string > a(n);

    for(int i = 0;i < n;i++) cin >> a[i];

    int res = 0;

    for(int i = 0;i + 1 < n;i++) {
        for(int j = 0;j + 1 < m;j++) {
            string t = a[i].substr(j, 2) + a[i + 1].substr(j, 2);
            sort(ALL(t));
            res += (face == t);
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