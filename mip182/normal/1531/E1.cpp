#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

template<class T>
bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

template<class T>
bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const ll INFLL = 1e18;
const int MAXN = 1e5 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;
vector<pair<pii, pii>> a;
pii pref[MAXN];

void ms(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    ms(l, mid);
    ms(mid + 1, r);
    a.pb({{l,       mid},
          {mid + 1, r}});
}

string ss;
vector<int> p;

void mss(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    mss(l, mid);
    mss(mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> b(r - l + 1);
//    cout << b.size() << " " << p.size() << '\n';
    int now = 0;
    while (i <= mid && j <= r) {
        if (p[i] < p[j])
            ss += '0', b[now++] = p[i++];
        else
            ss += '1', b[now++] = p[j++];
    }
    while (i <= mid)
        b[now++] = p[i++];
    while (j <= r)
        b[now++] = p[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        p[i] = b[j];
}

void solve() {
    string s;
    cin >> s;
    reverse(all(s));
    pref[0]={0,0};
    for (int i = 1; i <= s.size(); i++) {
        pref[i] = pref[i - 1];
        if (s[i - 1] == '0')
            pref[i].fi++;
        else
            pref[i].se++;
    }
    auto check_ans1 = [&](int n) {
        a.clear();
        ms(0, n - 1);
        reverse(all(a));
        vector<int> ans(n);
        int now = 0;
        auto does_zero = [&](int ff) {
            int cur = 1;
            int cnt1 = 0, cnt2 = 0;
            auto to = a[0];
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            cnt1 = 0, cnt2 = 0;
            now = ff;
            for (int i = now - 1; i >= 0; i--) {
                char u = s[i];
                if (u == '0')
                    ans[cnt1++] = cur++;
                else
                    ans[sz1 + cnt2] = cur++, cnt2++;
            }
            while (cnt1 < sz1)
                ans[cnt1++] = cur++;
            while (cnt2 < sz2)
                ans[sz1 + cnt2] = cur++, cnt2++;
        };
        auto does = [&](int delta, int _) {
            auto to = a[_];
            int cnt1 = 0, cnt2 = 0;
            int sz1 = to.fi.se - to.fi.fi + 1;
            int sz2 = to.se.se - to.se.fi + 1;
            int was = now;
            vector<int> fir(sz1), sec(sz2);
            cnt1 = 0;
            cnt2 = 0;
            int f = to.fi.fi;
            now += delta;
            for (int i = now - 1; i >= was; i--) {
                if (s[i] == '0')
                    fir[cnt1++] = ans[f++];
                else
                    sec[cnt2++] = ans[f++];
            }
            assert(cnt1 == sz1 || cnt2 == sz2);
            assert(cnt1 < sz1 || cnt2 < sz2);
            while (cnt1 < sz1)
                fir[cnt1++] = ans[f++];
            while (cnt2 < sz2)
                sec[cnt2++] = ans[f++];
            for (int i = to.fi.fi, j = 0; i <= to.fi.se; i++, j++)
                ans[i] = fir[j];
            for (int i = to.se.fi, j = 0; i <= to.se.se; i++, j++)
                ans[i] = sec[j];
        };
        vector<unordered_map<int, bool>> dp(a.size() + 1);
//        vector<map<int, int>> from(a.size() + 1);
        dp[0][0] = true;
        for (int i = 0; i < a.size(); i++) {
            if (dp[i].empty())
                break;
            auto to = a[i];
            for (auto too:dp[i]) {
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.fi.se - to.fi.fi + 1;
                int sz2 = to.se.se - to.se.fi + 1;
                int w = too.fi;
                int l = too.fi, r = min((int) s.size() - 1, too.fi + sz1 + sz2 - 1);
                while (l <= r) {
                    int mid = ((l + r) >> 1);
                    int x = pref[mid + 1].fi - pref[too.fi].fi;
                    int y = pref[mid + 1].se - pref[too.fi].se;
                    if (x < sz1 && y < sz2)
                        l = mid + 1;
                    else
                        r = mid - 1, cnt1 = x, cnt2 = y, w = mid + 1;
                }
//                while (w < s.size() && cnt1 < sz1 && cnt2 < sz2) {
//                    if (s[w] == '0')
//                        cnt1++;
//                    else
//                        cnt2++;
//                    w++;
//                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                if (cnt1 == sz1) {
                    if (s[too.fi] != '0')
                        continue;
                } else {
                    if (s[too.fi] != '1')
                        continue;
                }
                dp[i + 1][w] = true;
//                from[i + 1][w] = too.fi;
                while (w < s.size()) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1][w] = true;
//                    from[i + 1][w] = too.fi;
                }
            }
        }
        if (dp[a.size()].find(s.size()) == dp[a.size()].end()) {
            return false;
        }
        dp = vector<unordered_map<int, bool>>(a.size() + 1);
        vector<unordered_map<int, int>> from(a.size() + 1);
        dp[0][0] = true;
        for (int i = 0; i < a.size(); i++) {
            if (dp[i].empty())
                break;
            auto to = a[i];
            for (auto too:dp[i]) {
                int cnt1 = 0, cnt2 = 0;
                int sz1 = to.fi.se - to.fi.fi + 1;
                int sz2 = to.se.se - to.se.fi + 1;
                int w = too.fi;
                while (w < s.size() && cnt1 < sz1 && cnt2 < sz2) {
                    if (s[w] == '0')
                        cnt1++;
                    else
                        cnt2++;
                    w++;
                }
                if (cnt1 < sz1 && cnt2 < sz2)
                    continue;
                if (cnt1 == sz1) {
                    if (s[too.fi] != '0')
                        continue;
                } else {
                    if (s[too.fi] != '1')
                        continue;
                }
                dp[i + 1][w] = true;
                from[i + 1][w] = too.fi;
                while (w < s.size()) {
                    if (s[w] == '0') {
                        if (cnt1 + 1 < sz1)
                            cnt1++;
                        else
                            break;
                    } else {
                        if (cnt2 + 1 < sz2)
                            cnt2++;
                        else
                            break;
                    }
                    w++;
                    dp[i + 1][w] = true;
                    from[i + 1][w] = too.fi;
                }
            }
        }
        if (dp[a.size()].find(s.size()) == dp[a.size()].end()) {
            return false;
        }
        vector<int> x;
        now = 0;
        int ha = s.size();
        for (int j = (int) (a.size()); j > 0; j--) {
            int f = from[j][ha];
            x.pb(ha - f);
            ha = f;
        }
//        cout<<s.size()<<'\n';
//        cout << accumulate(all(x),0)<<'\n';
        reverse(all(x));
        does_zero(x[0]);
        assert(x.size() == a.size());
        for (int ii = 1; ii < x.size(); ii++)
            does(x[ii], ii);
//        ss = "";
//        p = ans;
//        mss(0, n - 1);
//        reverse(all(ss));
//        if (ss != s) {
//            for (auto to:x)
//                cout << to << " ";
//            cout << '\n';
//            cout << ss << '\n' << s << '\n';
//            for (auto to:ans)
//                cout << to << " ";
//            cout << '\n';
//            return true;
//        }
        cout << n << '\n';
        for (auto to:ans)
            cout << to << " ";
        cout << '\n';
        return true;
    };
    vector<int> ha(1e5 + 1);
    int now;
    for (int i = 2; i < ha.size(); i++) {
        int x = i / 2, y = i - x;
        ha[i] = ha[x] + ha[y] + x + y - 1;
        if (ha[i] >= s.size()) {
            now = i;
            break;
        }
    }
    while (1) {
        if (check_ans1(now++))
            return;
    }
    assert(false);
}

int main() {
#ifdef Mip182
    freopen("a.in", "r", stdin);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int _t;
    _t = 1;
//    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}