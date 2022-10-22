// time-limit: 2000
// problem-url: https://codeforces.com/contest/1705/problem/F

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 1005;
const int BUF = 'T' + 'F';

int n, on;
string ans;
vi need;

int ask(string s) {
    cout << s << endl;
    int k; cin >> k;
    if (k == on) {
        exit(0);
    }
    return k;
}

int main() {
    cin >> n;
    on = n;
    ans = string(n, 'F');
    int af = ask(ans);
    while (n % 3 != 0) {
        ans[n - 1] = 'T';
        int tmp = ask(ans);
        if (tmp < af) {
            ans[n - 1] = 'F';
        } else {
            af = tmp;
        }
        n--;
    }
    string s = ans;
    for (int i = 0; i < n; i += 3) {
        s[i] = s[i + 1] = s[i + 2] = 'T';
        int tmp = ask(s);
        if (tmp - af == 3) {
            ans[i] = ans[i + 1] = ans[i + 2] = 'T';
        } else if (tmp - af == -3) {
            ans[i] = ans[i + 1] = ans[i + 2] = 'F';
        } else if (tmp - af == -1) { // TFF
            need.pb(i);
        } else if (tmp - af == 1) { // TTF
            need.pb(i);
            ans[i] = ans[i + 1] = ans[i + 2] = 'T';
        } else {
            assert(0);
        }
        s[i] = s[i + 1] = s[i + 2] = 'F';
    }
    s = ans;
    for (int i : need) {
        s[i] = BUF - s[i];
    }
    af = ask(s);
    for (int i : need) {
        s[i] = BUF - s[i];
        s[i + 1] = BUF - s[i + 1];
        int tmp = ask(s);
        if (tmp - af == -2) {
            ans[i] = BUF - ans[i];
        } else if (tmp - af == 2) {
            ans[i + 1] = BUF - ans[i + 1];
        } else if (tmp - af == 0) {
            ans[i + 2] = BUF - ans[i + 2];
        } else {
            assert(0);
        }
        s[i] = BUF - s[i];
        s[i + 1] = BUF - s[i + 1];
    }
    assert(ask(ans) == on);
    return 0;
}