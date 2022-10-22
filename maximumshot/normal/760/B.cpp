#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n, m, k;

ll get(int st, int cn) {
    return 1ll * (st + st - cn + 1) * cn / 2;
}

bool check(int x) {
    ll tot = x;
    if(k > 1) {
        if(k - 1 <= x - 1) {
            tot += get(x - 1, k - 1);
        }else {
            tot += get(x - 1, x - 1) + k - 1 - (x - 1);
        }
    }
    if(k < n) {
        if(n - k <= x - 1) {
            tot += get(x - 1, n - k);
        }else {
            tot += get(x - 1, x- 1) + n - k - (x - 1);
        }
    }
    return tot <= (ll)m;
}

int main() {

    cin >> n >> m >> k;
    
    int bl, br, bm;
    
    bl = 1;
    br = m;
    
    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(check(bm)) bl = bm;
        else br = bm - 1;
    }
    
    if(bl < br && check(br)) {
        cout << br << "\n";
    }else {
        cout << bl << "\n";
    }
    
    return 0;
}