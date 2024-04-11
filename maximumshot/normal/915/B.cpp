#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, pos, l, r;

    cin >> n >> pos >> l >> r;

    if(l == 1 && r == n) {
        cout << "0\n";
        return 0;
    }

    int res = 0;

    if(pos <= l) {
        res += l - pos;
        if(l > 1) res++;
        if(r < n) res += r - l + 1;
    }else if(pos >= r) {
        res += pos - r;
        if(r < n) res++;
        if(l > 1) res += r - l + 1;
    }else {
        int res1 = 0;

        int npos = pos;

        if(l > 1) {
            res1 += pos - l + 1;
            pos = l;
        }

        if(r < n) {
            res1 += r - pos + 1;
            pos = r;
        }

        pos = npos;

        int res2 = 0;

        if(r < n) {
            res2 += r - pos + 1;
            pos = r;
        }

        if(l > 1) {
            res2 += pos - l + 1;
            pos = l;
        }

//        cout << res1 << " " << res2 << "\n";

        res = min(res1, res2);
    }

    cout << res << "\n";

    return 0;
}