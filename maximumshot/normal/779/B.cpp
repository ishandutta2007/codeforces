#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    string s;
    cin >> s;

    int k;
    cin >> k;

    if(count(ALL(s), '0') < k) {
        cout << (int)s.size() - 1 << "\n";
        return 0;
    }

    int res = 0;

    for(int cur = 0, i = (int)s.size() - 1;i >= 0 && cur < k;i--) {
        if(s[i] == '0') {
            cur++;
        }else {
            res++;
        }
    }

    cout << res << "\n";

    return 0;
}