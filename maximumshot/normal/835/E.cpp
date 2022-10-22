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

int n, x, y;

int ask(vec< int > arr) {
    if(arr.empty()) return 0;
    sort(ALL(arr));
    arr.resize(unique(ALL(arr)) - arr.begin());
    if((int)arr.size() == n) {
        return n % 2 ? x : 0;
    }
    cout << "? " << (int)arr.size();
    for(int x : arr) cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {

#ifdef debug
//    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> x >> y;

    int mask = 0;
    int last = 0;

    for(int j = 0;(1 << j) <= n;j++) {
        vec< int > a, b;
        for(int i = 1;i <= n;i++) {
            if((1 << j) & i) {
                a.push_back(i);
            }else {
                b.push_back(i);
            }
        }
        int r = ask(a);
        if((int)a.size() % 2) {
            if(r == y) {
                mask |= (1 << j);
                last = j;
            }
        }else {
            if(r == (x ^ y)) {
                mask |= (1 << j);
                last = j;
            }
        }
    }

    vec< int > a, b;

    for(int i = 1;i <= n;i++) {
        if((1 << last) & i) {
            a.push_back(i);
        }else {
            b.push_back(i);
        }
    }

    if(a.size() > b.size()) swap(a, b);

    int bl = 0;
    int br = (int)a.size();
    int bm;

    while(br - bl > 1) {
        bm = (bl + br) / 2;
        vec< int > ta(a.begin(), a.begin() + bm);
        int r = ask(ta);
        if((int)ta.size() % 2 == 1 && r == y ||
           (int)ta.size() % 2 == 0 && r == (x ^ y)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    int r1 = a[bl];
    int r2 = r1 ^ mask;

    if(r1 > r2) swap(r1, r2);

    cout << "! " << r1 << " " << r2 << endl;

    return 0;
}