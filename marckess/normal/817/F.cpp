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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
struct ST {
    int st[12*MX], lz[12*MX];

    void init (int i, int j, int pos) {
        st[pos] = lz[pos] = 0;
        if (i < j) {
            int m = (i+j)/2;
            init(i, m, pos*2);
            init(m+1, j, pos*2+1);
        }
    }

    void updateLazy (int i, int j, int pos) {
        if (lz[pos] == 1) {
            st[pos] = j - i + 1;
            if (i < j)
                lz[pos*2] = lz[pos*2+1] = 1;
        } else if (lz[pos] == -1) {
            st[pos] = 0;
            if (i < j)
                lz[pos*2] = lz[pos*2+1] = -1;
        } else {
            st[pos] = j - i + 1 - st[pos];
            if (i < j) {
                for (int k = 0; k < 2; k++) {
                    if (!lz[pos*2+k])
                        lz[pos*2+k] = 2;
                    else if (lz[pos*2+k] == 2)
                        lz[pos*2+k] = 0;
                    else
                        lz[pos*2+k] *= -1;
                }
            }
        }
        lz[pos] = 0;
    }

    void update (int i, int j, int pos, int a, int b, int k) {
        if (lz[pos])
            updateLazy(i, j, pos);

        if (b < i || j < a)
            return;

        if (a <= i && j <= b) {
            lz[pos] = k;
            updateLazy(i, j, pos);
            return;
        }

        int m = (i+j)/2;
        update(i, m, pos*2, a, b, k);
        update(m+1, j, pos*2+1, a, b, k);

        st[pos] = st[pos*2] + st[pos*2+1];
    }

    int query (int i, int j, int pos) {
        if (lz[pos])
            updateLazy(i, j, pos);

        if (st[pos] == j - i + 1)
            return -1;

        if (i == j)
            return i;

        int m = (i+j)/2;
        int d = query(i, m, pos*2);
        if (d == -1)
            return query(m+1, j, pos*2+1);
        return d;
    }
}st;

int n, q, t[MX];
ll l[MX], r[MX];
vector<ll> con;

#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    con.push_back(1);

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> t[i] >> l[i] >> r[i];
        con.push_back(l[i]);
        con.push_back(r[i]);
        con.push_back(r[i]+1);
    }

    sort(ALL(con));
    con.erase(unique(ALL(con)), con.end());
    n = con.size();
    st.init(1, n, 1);

    for (int i = 0; i < q; i++) {
        l[i] = find(con, l[i]) + 1;
        r[i] = find(con, r[i]) + 1;
        if (t[i] == 1) {
            st.update(1, n, 1, l[i], r[i], 1);
        } else if (t[i] == 2) {
            st.update(1, n, 1, l[i], r[i], -1);
        } else {
            st.update(1, n, 1, l[i], r[i], 2);
        }

        cout << con[st.query(1, n, 1) - 1] << endl;
    }

    return 0;
}