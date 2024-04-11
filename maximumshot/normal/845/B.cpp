#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    string ss;

    cin >> ss;

    int r = inf;

    for(int x = 0;x < 1000000;x++) {
        int s = 0;
        int vx = x;
        int df = 0;
        for(int i = 0;i < 6;i++, vx /= 10) {
            if(ss[i] - '0' != vx % 10) df++;
            if(i < 3) {
                s += vx % 10;
            }else {
                s -= vx % 10;
            }
        }
        if(!s) r = min(r, df);
    }

    cout << r << "\n";

    return 0;
}