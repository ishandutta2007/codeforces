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
const int MAXN = 1e6 + 100;
const ll INF = 1e9;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 21;

void solve() {
    string s;
    cin >> s;
    sort(all(s));
    if (s[0] == s.back()) {
        cout << s << '\n';
        return;
    }
    vector<int> cnt(26);
    for (auto to:s)
        cnt[to - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] == 1) {
            cout << (char) ('a' + i);
            for (int j = 0; j < i; j++) {
                while (cnt[j])
                    cout << (char) ('a' + j),cnt[j]--;
            }
            for (int j = i + 1; j < 26; j++) {
                while (cnt[j])
                    cout << (char) ('a' + j),cnt[j]--;
            }
            cout << '\n';
            return;
        }
    }
    int ind = 0;
    while (cnt[ind] == 0)
        ind++;
    int els = (int) (s.size()) - cnt[ind];
    int n = s.size();
    if (els >= cnt[ind] - 2) {
        cout << (char) ('a' + ind) << (char) ('a' + ind);
        cnt[ind] -= 2;
        for (int i = ind + 1; i < 26; i++) {
            if (cnt[i] == 0)
                continue;
            while (cnt[i] > 0 && cnt[ind] > 0) {
                cout << (char) ('a' + i) << (char) ('a' + ind);
                cnt[i]--;
                cnt[ind]--;
            }
            while (cnt[i] > 0) {
                cout << (char) ('a' + i);
                cnt[i]--;
            }
        }
        if (cnt[ind]) {
            assert(cnt[ind] == 1);
            cout << (char) ('a' + ind);
        }
        cout << '\n';
    } else {
        cnt[ind]--;
        n--;
        cout << (char) ('a' + ind);
        int f = ind + 1;
        while (cnt[f] == 0)
            f++;
        int t = f + 1;
        while (t < 26 && cnt[t] == 0)
            t++;
        if (t < 26) {
            cout << (char) ('a' + f);
            cnt[f]--;
            while (cnt[ind])
                cout << (char) ('a' + ind),cnt[ind]--;
            cout << (char) ('a' + t);
            cnt[t]--;
            for (int i = 0; i < 26; i++) {
                while (cnt[i])
                    cout << (char) ('a' + i),cnt[i]--;
            }
        } else {
            while (cnt[f])
                cout << (char) ('a' + f),cnt[f]--;
            while (cnt[ind])
                cout << (char) ('a' + ind),cnt[ind]--;
        }
        cout << '\n';
    }
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
    cin >> _t;
    while (_t--)
        solve();
#ifdef Mip182
    cout << '\n' << "Time : " << (double) (clock()) / CLOCKS_PER_SEC << '\n';
#endif
}