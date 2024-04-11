#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n;

    cin >> n;

    map< string, int > a[55];

    set< string > q;

    for(int i = 0;i < n;i++) {
        string s;
        cin >> s;
        for(int j = 0;j < (int)s.size();j++) {
            if(!a[i].count(s)) {
                a[i][s] = j;
            }
            q.insert(s);
            s = s.substr(1) + s.substr(0, 1);
        }
    }

    int res = -1;

    for(string x : q) {
        int tmp = 0;
        int ok = 1;
        for(int i = 0;i < n;i++) {
            if(!a[i].count(x)) {
                ok = 0;
                break;
            }else {
                tmp += a[i][x];
            }
        }
        if(ok) {
            if(res == -1 || res > tmp) {
                res = tmp;
            }
        }
    }

    cout << res << "\n";

    return 0;
}