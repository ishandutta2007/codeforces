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

int main() {

    string a, b;
    cin >> a >> b;

    int n = (int)a.size();
    int m = (int)b.size();

    vec< int > pr(m);
    vec< int > sf(m);

    for(int j = 0, i = 0;i < m;i++) {
        while(j < n && a[j] != b[i]) {
            j++;
        }
        pr[i] = min(n, j++);
    }

    for(int j = n - 1, i = m - 1;i >= 0;i--) {
        while(j >= 0 && a[j] != b[i]) {
            j--;
        }
        sf[i] = max(-1, j--);
    }

    // for(int i = 0;i < m;i++) {
    //     cout << pr[i] << " " << sf[i] << "\n";
    // }

    int cnt = m;
    int l = 0, r = m - 1;

    if(pr[m - 1] < n) {
        cout << b;
        return 0;
    }

    for(int bl, br, bm, qr, ql = 0;ql < m;ql++) {
        if(!((ql == 0 || pr[ql - 1] < n))) continue;
        bl = ql;
        br = m - 1;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if( (ql > 0 ? pr[ql - 1] : -1) < (bm + 1 < m ? sf[bm + 1] : n) ) {
                br = bm;
            }else {
                bl = bm + 1;
            }
        }
        if(bl < br &&
                (ql > 0 ? pr[ql - 1] : -1) < (bl + 1 < m ? sf[bl + 1] : n)) {
            qr = bl;
        }else {
            qr = br;
        }
        int tmp = qr - ql + 1;
        if(tmp < cnt) {
            cnt = tmp;
            l = ql;
            r = qr;
        }
        // cout << ql << " " << qr << "\n";
    }

    int ok = 0;

    for(int i = 0;i < m;i++) {
        if(l > r || i < l || i > r) {
            cout << b[i];
            ok = 1;
        }
    }

    if(!ok) cout << "-";

    cout << "\n";

    return 0;
}