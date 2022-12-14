/**
 *    author:  tourist
 *    created: 09.05.1945 00:43:00
**/
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <complex>
#include <cstdint>
#include <fstream>
#include <forward_list>
#include <iomanip>
#include <assert.h>

#define all(x) (x).begin(), (x).end()
#define re return
#define fi first
#define sz(x) (int)(x).size()
#define se second
#define mp make_pair
#define pb emplace_back
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define unq(x) { sort(x.begin(), x.end()); x.resize(unique (x.begin(), x.end()) - x.begin()); }

//#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef complex<double> cmp;
typedef double D;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int N = 50 + 5;
const ll INF = 2e18;
const D PI = acos(-1);

mt19937 rnd(time(0));

struct pt {
    ll x, y;
    pt () {}
    pt (ll X, ll Y){
        x = X; y = Y;
    }
    pt operator + (pt A) {
        return {x + A.x, y + A.y};
    }
    pt operator - (pt A) {
        return {x - A.x, y - A.y};
    }
    pt operator * (ll k) {
        return {x * k, y * k};
    }
    pt operator / (ll k) {
        assert(abs(k) > 1e-20);
        return {x / k, y / k};
    }
    bool operator == (const pt &A) {
        re x == A.x && y == A.y;
    }
    bool operator != (const pt &A) {
        re x != A.x || y != A.y;
    }
    bool operator < (const pt& A) {
        re x < A.x || (x == A.x && y < A.y);
    }
    ll operator * (pt A) {
        return x * A.y - y * A.x;
    }
    ll operator % (pt A) {
        return x * A.x + y * A.y;
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    ll len2() {
        return x * x + y * y;
    }
    pt rotate () {
        return {-y, x};
    }
    void read() {
        cin >> x >> y;
    }
    void out() {
        cout << x << ' ' << y << '\n';
    }
};

bool In_otr (pt A, pt B, pt C)
{
    pt v1 = B - A, v2 = C - A, v3 = A - B, v4 = C - B;
    if(v1 * v2 == 0 && v1 % v2 >= 0 && v3 % v4 >= 0)
        re true;
    re false;
}

bool F (pt a, pt b)
{
    if(a.x != b.x)
        re a.x < b.x;
    re a.y < b.y;
}

int s_vec (pt v1, pt v2)
{
    ll q = v1 * v2;
    if(q > 0)
        re 1;
    if(q == 0)
        re 0;
    re -1;
}

void Convex_hull (vector<pt>& a)
{
    if (sz(a) < 3) re;
    sort(all(a), F);
    pt A = a[0],  B = a[sz(a) - 1];
    vector<pt> up, down;
    up.push_back (A);
    down.push_back (A);
    for (int i = 1; i < sz(a); i++)
    {
        pt v1 = B - A, C = a[i];
        pt v2 = C - A;
        int sign = s_vec(v1, v2);
        if (sign == 1 || i == sz(a) - 1)
        {
            while (sz(up) > 1)
            {
                pt A1 = up[sz(up) - 2], B1 = up[sz(up) - 1], C1 = a[i];
                v1 = B1 - A1, v2 = C1 - A1;
                if (s_vec(v1, v2) >= 0)
                    up.pop_back();
                else break;
            }
            up.pb(a[i]);
        }
        if (sign == -1 || i == sz(a) - 1)
        {
            while (sz(down) > 1)
            {
                pt A1 = down[sz(down) - 2], B1 = down[sz(down) - 1], C1 = a[i];
                v1 = B1 - A1, v2 = C1 - A1;
                if (s_vec(v1, v2) <= 0)
                    down.pop_back();
                else break;
            }
            down.pb(a[i]);
        }
    }
    a.clear();
    rep (i, sz(up))
        a.push_back (up[i]);
    for (int i = sz(down) - 2; i > 0; i--)
        a.push_back (down[i]);
}

D Try1(vector<pt> A, pt Bad, pt S) {
    int pos = 0;
    int n = sz(A);
    rep (i, n) {
        if (A[i] == S) {
            pos = i;
            break;
        }
    }

    D mi = INF;
    rep (i, n - 1) {
        pt v1 = Bad - A[i], v2 = Bad - A[i + 1], v3 = A[i + 1] - A[i];
        mi = min(mi, v1.len() + v2.len() - v3.len());
    }
    pt v1 = A[pos] - A[0], v2 = A[pos] - A.back();
    re mi + v1.len() * 2 + v2.len();
}

D Try2(vector<pt> A, pt Bad, pt S) {
    int pos = 0;
    int n = sz(A);
    rep (i, n) {
        if (A[i] == S) {
            pos = i;
            break;
        }
    }

    if (pos == n - 1) {
        pt v1 = A[pos] - A[0], v2 = Bad - A[0];
        re v1.len() + v2.len();
    }

    pt v1 = A[pos] - A[0], v2 = Bad - A[0], v3 = A[pos + 1] - A.back(), v4 = A[pos + 1] - Bad;
    re v1.len() + v2.len() + v3.len() + v4.len();
}

D Try3(vector<pt> A, pt Bad, pt S) {
    int pos = 0;
    int n = sz(A);
    rep (i, n) {
        if (A[i] == S) {
            pos = i;
            break;
        }
    }
    pt v1 = A[pos] - A[0], v2 = A[pos] - A.back(), v3 = Bad - A.back();
    re v1.len() * 2 + v2.len() + v3.len();
}

void solve()
{
    cout << setprecision(20) << fixed;
    int n, k;
    cin >> n >> k;
    k--;
    vector<pt> A(n);
    rep (i, n) {
        A[i].read();
    }
    pt S = A[k];
    unq(A);
    n = sz(A);

    vector<pt> CH = A;
    Convex_hull(CH);
    pt Bad = A[0];
    if (sz(CH) == 3 && sz(A) > 3) {
        pt Out;
        rep (i, n) {
            if (A[i] != CH[0] && A[i] != CH[1] && A[i] != CH[2]) {
                Out = A[i];
                break;
            }
        }
        rep (i, 3) {
            for (int j = i + 1; j < 3; j++) {
                pt v1 = Out - CH[i], v2 = CH[j] - CH[i];
                if (v1 * v2 != 0) {
                    continue;
                }
                rep (h, 3) {
                    if (h != i && h != j) {
                        Bad = CH[h];
                        break;
                    }
                }
            }
        }
    }
    vector<pt> B;
    rep (i, n) {
        if (A[i] != Bad) {
            B.pb(A[i]);
        }
    }

    A = B;

    if (S == Bad) {
        pt v1 = A[0] - A.back(), v2 = A[0] - Bad, v3 = A.back() - Bad;
        cout << v1.len() + min(v2.len(), v3.len());
        re;
    }
    D an = min({Try1(A, Bad, S), Try2(A, Bad, S), Try3(A, Bad, S)});
    reverse(all(A));
    an = min(an, min({Try1(A, Bad, S), Try2(A, Bad, S), Try3(A, Bad, S)}));
    cout << an;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
    int qq = 1;
//    cin >> qq;
    rep(i, qq)
        solve();
}