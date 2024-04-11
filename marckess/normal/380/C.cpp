#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

typedef tuple<int, int, int> iii;

struct segment_tree {
    vector<iii> st;
    string s;

    segment_tree () : st(4e6) {}

    void construct (int i, int j, int pos) {
        if ( i == j ) {
            if ( s[i-1] == '(' )
                st[pos] = iii(1, 0, 0);
            else
                st[pos] = iii(0, 0, 1);
            return;
        }

        int m = (i + j) / 2;
        construct(i, m, pos*2);
        construct(m+1, j, pos*2+1);
        
        st[pos] = marge(st[pos*2], st[pos*2+1]);
    }

    iii query (int i, int j, int a, int b, int pos) {
        if ( i > b || j < a )
            return iii(0, 0, 0);

        if ( i >= a && j <= b )
            return st[pos];

        int m = (i + j) / 2;
        return marge( query(i, m, a, b, pos*2), query(m+1, j, a, b, pos*2+1) );
    }

    iii marge (iii a, iii b) {
        int l1, l2, x1, x2, r1, r2, l, x, r;
        tie(l1, x1, r1) = a;
        tie(l2, x2, r2) = b;
        x = min(l1, r2);
        l = l1 + l2 - x;
        r = r1 + r2 - x;
        x += x1 + x2;
        return iii(l, x, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int q, a, b, n;

    segment_tree st;
    cin >> st.s >> q;

    n = st.s.size();
    st.construct(1, n, 1);
    while (q--) {
        cin >> a >> b;
        cout << get<1>( st.query(1, n, a, b, 1) ) * 2 << endl;
    }

    return 0;
}