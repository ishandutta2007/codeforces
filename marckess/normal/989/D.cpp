#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n;
ll a[MX], b[MX], v[MX], w, l, res = 0;
int fx = 0, fy = 0;
vector<ll> st;

int binBusc (ll x, ll a, ll b, auto &v) {
    if (v.empty())
        return 0;
    
    int i = 0, j = (int)v.size(), rep = 20;

    while (rep--) {
        int m = (i+j)/2;
        if (b * v[m] > x * a)
            j = m;
        else
            i = m;
    }

    return v.size() - (int)j;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> l >> w;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> v[i];
        b[i] = a[i] + l;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == -1 && b[i] < 0)
            st.push_back(b[i]);
    }
    sort(ALL(st));

    for (int i = 0; i < n; i++) {
        if (v[i] == 1 && a[i] <= 0) {
            res += binBusc(a[i], w - 1, w + 1, st);
        }
    }

    if (w > 1) {
        st.clear();
        for (int i = 0; i < n; i++) {
            if (v[i] == -1 && b[i] >= 0)
                st.push_back(b[i]);
        }
        sort(ALL(st));

        for (int i = 0; i < n; i++) {
            if (v[i] == 1 && a[i] > 0) {
                res += binBusc(a[i], w + 1, w - 1, st);
            }
        }
    }

    ll x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            if (a[i] < 0)
                x++;

            if (!a[i] && w > 1) {
                x++;
                fx = 1;
            }
        }

        if (v[i] == -1) {
            if (b[i] > 0)
                y++;

            if(!b[i] && w > 1) {
                y++;
                fy = 1;
            }
        }
    }

    res += x * y - fx * fy;;

    cout << res << endl;

    return 0;
}