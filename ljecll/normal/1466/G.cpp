#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define int long long

const int MAXN = 1e6 + 13;
const int CO = 1e6 + 33;
const int MOD = 1e9 + 933;
const int INF = 1e9 + 7;

int add(int a, int b)
{
    a += b; if (a >= INF) a -= INF; return a;
}
int mul(int a, int b)
{
    return (ll) a * b % INF;
}
int sub(int a, int b)
{
    a -= b; if (a < 0) a += INF; return a;
}
int pwr(int a, int b)
{
    int res = 1;
    while(b > 0)
    {
        if (b & 1) res = mul(res, a);
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}
int inv(int a)
{
    return pwr(a, INF - 2);
}
int dvd(int a, int b)
{
    return mul(a, inv(b));
}

int N, M, Q;
string s, t;
string st[28];
int cnt[MAXN][28], cnt0[28];
int pw2[MAXN], inv2[MAXN];
bitset<MAXN> fw, bw;

string getrange(string s, int a, int b)
{
    string res;
    FOR(i, a, b + 1)
    {
        res += s[i];
    }
    return res;
}
bool issuf(string a, string b) //is b a suffix of a?
{
    if (SZ(b) > SZ(a)) return false;
    FOR(i, 0, SZ(b))
    {
        if (b[SZ(b) - i] != a[SZ(a) - i]) return false;
    }
    return true;
}
bool ispref(string a, string b) //is b a prefix of a
{
    if (SZ(b) > SZ(a)) return false;
    FOR(i, 0, SZ(b))
    {
        if (b[i] != a[i]) return false;
    }
    return true;
}
int work(int k, string str) //this counts the # of ways to assign
{
    // cerr << "work " << k << ' ' << str << endl;
    int K = SZ(str);
    int res = 0;
    int idx = 0;
    while(SZ(st[idx]) < K) idx++;
    if (idx > k + 1) return 0;
    // cerr << "idx = " << idx << ' ' << st[idx] << endl;
    //010 aaa, and you looking for it in 0102010
    //0102010 aaa
    //smth of length 3 in
    pll hst, hstr, pw;
    hst = {0, 0}; hstr = {0, 0}; pw = {1, 1};
    FOR(i, 0, K)
    {
        bw[i] = (hst == hstr);
        hstr.fi += pw.fi * str[K - 1 - i]; hstr.fi %= INF;
        hstr.se += pw.se * str[K - 1 - i]; hstr.se %= MOD;
        hst.fi *= CO; hst.fi += st[idx][i]; hst.fi %= INF;
        hst.se *= CO; hst.se += st[idx][i]; hst.se %= MOD;
        pw.fi *= CO; pw.se *= CO; pw.fi %= INF; pw.se %= MOD;
    }
    hst = {0, 0}; hstr = {0, 0}; pw = {1, 1};
    FOR(i, 0, SZ(str))
    {
        fw[i] = (hst == hstr);
        hst.fi += pw.fi * st[idx][SZ(st[idx]) - 1 - i]; hst.fi %= INF;
        hst.se += pw.se * st[idx][SZ(st[idx]) - 1 - i]; hst.se %= MOD;
        hstr.fi *= CO; hstr.fi += str[i]; hstr.fi %= INF;
        hstr.se *= CO; hstr.se += str[i]; hstr.se %= MOD;
        pw.fi *= CO; pw.se *= CO; pw.fi %= INF; pw.se %= MOD;
    }
    // cerr << "from " << idx - 1 << " to " << k << endl;
    FOR(i, 0, K)
    {
        if (fw[i] && bw[K - 1 - i])
        {
            int c = str[i] - 'a';
            res = add(res, sub(cnt[k + 1][c], cnt[idx][c]));
        }
    }
    res = mul(res, pw2[k]);
    // cerr << "res " << res << endl;
    hst = {0, 0};
    FOR(i, 0, K)
    {
        hst.fi *= CO; hst.fi += st[idx][i]; hst.fi %= INF;
        hst.se *= CO; hst.se += st[idx][i]; hst.se %= MOD;
    }
    if (hst == hstr)
    {
        res = add(res, pw2[k + 1 - idx]);
    }
    FOR(i, K, SZ(st[idx]))
    {
        hst.fi *= CO; hst.fi += st[idx][i]; hst.fi -= pw.fi * st[idx][i - K]; hst.fi %= INF; if (hst.fi < 0) hst.fi += INF;
        hst.se *= CO; hst.se += st[idx][i]; hst.se -= pw.se * st[idx][i - K]; hst.se %= MOD; if (hst.se < 0) hst.se += MOD;
        if (hst == hstr)
        {
            res = add(res, pw2[k + 1 - idx]);
        }
    }
    return res;
}
int solve(int k, string str)
{
    int res = 0;
    FOR(i, 0, M + 1)
    {
        string chk;
        bool ok = true;
        FOR(j, 0, SZ(str))
        {
            int x = (j - i) % (M + 1);
            if (x < 0) x += (M + 1);
            if (x == M)
            {
                chk += str[j];
                continue;
            }
            if (str[j] != s[x])
            {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        if (chk.empty())
        {
            res = add(res, pw2[k + 1]);
        }
        else
        {
            res = add(res, work(k, chk));
        }
    }
    return res;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    pw2[0] = 1;
    FOR(i, 1, MAXN - 3)
    {
        pw2[i] = add(pw2[i - 1], pw2[i - 1]);
    }
    inv2[MAXN - 4] = dvd(1, pw2[MAXN - 4]);
    FORD(i, MAXN - 4, 0)
    {
        inv2[i] = add(inv2[i + 1], inv2[i + 1]);
    }
    assert(inv2[0] == 1);
    cin >> N >> Q >> s >> t; M = SZ(s);
    while(SZ(t) < 22)
    {
        t += '!';
    }
    N = SZ(t);
    FOR(i, 0, SZ(s))
    {
        cnt0[s[i] - 'a']++;
    }
    FOR(i, 0, N)
    {
        FOR(j, 0, 27)
        {
            cnt[i + 1][j] = cnt[i][j];
            if (t[i] == ('a' + j))
            {
                // cerr << "ADDS " << inv2[i] << " to " << i + 1 << ',' << j << endl;
                cnt[i + 1][j] = add(cnt[i + 1][j], inv2[i]);
            }
        }
    }
    st[0] = "";
    FOR(i, 1, 21)
    {
        st[i] = st[i - 1] + t[i - 1] + st[i - 1];
    }
    FOR(i, 0, Q)
    {
        int k; string str;
        cin >> k >> str;
        k--;
        cout << solve(k, str) << '\n';
    }
    return 0;
}