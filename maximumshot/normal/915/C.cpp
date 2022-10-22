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

    string a, b;

    cin >> a >> b;

    assert(a.size() <= b.size());

    if(a.size() < b.size()) {
        sort(ALL(a));
        reverse(ALL(a));
        cout << a << "\n";
        return 0;
    }

    {
        string aa, bb;
        aa = a;
        bb = b;

        sort(ALL(aa));
        sort(ALL(bb));

        if(aa == bb) {
            cout << b << "\n";
            return 0;
        }
    }

    vec< int > cnt(10);

    for(char c : a) {
        cnt[c - '0']++;
    }

    for(int i = (int)b.size() - 1;i >= 0;i--) {
        int ok = 1;
        vec< int > tmp = cnt;
        for(int j = 0;j < i;j++) {
            int y = b[j] - '0';
            if(!tmp[y]) {
                ok = 0;
                break;
            }else {
                tmp[y]--;
            }
        }
        if(!ok) continue;
        for(int x = b[i] - '0' - 1;x >= (i == 0);x--) {
            if(!tmp[x]) continue;
            tmp[x]--;
            cout << b.substr(0, i);
            cout << x;
            for(int y = 9;y >= 0;y--) {
                for(int it = 0;it < tmp[y];it++) {
                    cout << y;
                }
            }
            cout << "\n";
            return 0;
        }
    }

    return 0;
}