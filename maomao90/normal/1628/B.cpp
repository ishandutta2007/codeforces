// time-limit: 2000
// problem-url: https://codeforces.com/contest/1628/problem/B

// No temptation has overtaken you except what is common to mankind. And God 
// is faithful; he will not let you be tempted beyond what you can bear.
// But when you are tempted, he will also provide a way out so that you can 
// endure it.
// 1 Corinthians 10:13
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 200005

int t;
int n;
char tmp[5];
string s[MAXN], rs[MAXN];
set<string> st;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP (i, 0, n) {
            scanf(" %s", tmp);
            s[i] = tmp;
            rs[i] = tmp;
            reverse(ALL(rs[i]));
        }
        bool ans = 0;
        REP (i, 0, n) {
            if (s[i] == rs[i]) {
                ans = 1;
                break;
            }
        }
        if (ans) {
            printf("YES\n");
            continue;
        }
        st.clear();
        RREP (i, n - 1, 0) {
            if (st.find(rs[i]) != st.end()) {
                ans = 1;
                break;
            }
            st.insert(s[i]);
        }
        if (ans) {
            printf("YES\n");
            continue;
        }
        st.clear();
        RREP (i, n - 1, 0) {
            string t = s[i];
            t.pop_back();
            if (st.find(t) != st.end()) {
                ans = 1;
                break;
            }
            st.insert(rs[i]);
        }
        if (ans) {
            printf("YES\n");
            continue;
        }
        st.clear();
        REP (i, 0, n) {
            string t = rs[i];
            t.pop_back();
            if (st.find(t) != st.end()) {
                ans = 1;
                break;
            }
            st.insert(s[i]);
        }
        if (ans) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}