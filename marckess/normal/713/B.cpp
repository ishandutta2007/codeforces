#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n;
int a[2], b[2], c[2], d[2];

int query (int a, int b, int c, int d) {
    if (a > c || b > d)
        return -1;

    cout << '?'  << " " << a << " " << b << " " << c << " " << d << endl;
    fflush(stdout);
    cin >> a;
    return a;
}

const int r = 18;

int res1 (int f) {
    int i = 1, j = n + 1, rep = r;

    while (rep--) {
        int m = (i+j)/2;
        if (query(1, 1, m, n) >= f)
            j = m;
        else
            i = m;
    }

    if (query(1, 1, j, n) >= f)
        return j;
    return i;
}

int res2 (int f) {
    int i = 1, j = n + 1, rep = r;

    while (rep--) {
        int m = (i+j)/2;
        if (query(1, 1, n, m) >= f)
            j = m;
        else
            i = m;
    }

    if (query(1, 1, n, j) >= f)
        return j;
    return i;
}

int res3 (int f) {
    int i = 1, j = n + 1, rep = r;

    while (rep--) {
        int m = (i+j)/2;
        if (query(m, 1, n, n) >= f)
            i = m;
        else
            j = m;
    }

    if (query(i, 1, n, n) >= f)
        return i;
    return j;
}

int res4 (int f) {
    int i = 1, j = n + 1, rep = r;

    while (rep--) {
        int m = (i+j)/2;
        if (query(1, m, n, n) >= f)
            i = m;
        else
            j = m;
    }

    if (query(1, i, n, n) >= f)
        return i;
    return j;
}

int main () {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < 2; i++) {
        c[i] = res1(i+1);
        d[i] = res2(i+1);
        a[i] = res3(i+1);
        b[i] = res4(i+1);
        //cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
    }

    for (int i = 0; i < 16; i++) {
        if (
            query(a[bool(i&1)], b[bool(i&2)], c[bool(i&4)], d[bool(i&8)]) == 1
        &&  query(a[!bool(i&1)], b[!bool(i&2)], c[!bool(i&4)], d[!bool(i&8)]) == 1
            ) {

            cout << "! " << a[bool(i&1)] << " " << b[bool(i&2)] << " " << c[bool(i&4)] << " " << d[bool(i&8)]
                 << ' ' << a[!bool(i&1)] << " " << b[!bool(i&2)] << " " << c[!bool(i&4)] << " " << d[!bool(i&8)] << endl;
            fflush(stdout);
            return 0;
        }
    }

    assert(0);

    return 0;
}