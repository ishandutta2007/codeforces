#include <bits/stdc++.h>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,c) for(decltype(c.begin()) i=c.begin();i!=c.end();++i)
#define Fid(i,c) for(decltype(c.rbegin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

int m, n;
vector<string> a;
const char *chars = "AGCT";

vector<string> flip(vector<string> a) {
    int m = a.size();
    int n = a[0].size();
    vector<string> res(n);
    Rep(i, n) {
        string s(m, ' ');
        Rep(j, m) s[j] = a[j][i];
        res[i] = s;
    }
    return res;
}

int diff(string s1, string s2) {
    int c = 0;
    Rep(i, s1.length()) if (s1[i] != s2[i]) ++c;
    return c;
}

// pair<string, int> get(string s, char c0, char c1) {
//     int n = s.length();
//     string s1(n, ' '), s2(n, ' ');
//     Rep(i, n) if (i % 2 == 0) s1[i] = c0; else s1[i] = c1;
//     Rep(i, n) if (i % 2 == 0) s2[i] = c1; else s2[i] = c0;
//     if (diff(s, s1) < diff(s, s2)) return MP(s1, diff(s, s1));
//     else return MP(s2, diff(s, s2));
// }

int get(string &s, char c0, char c1) {
    int n = s.length();
    int res = 0;
    Rep(i, n) if ((i % 2 == 0 && s[i] != c0)  || (i % 2 == 1 && s[i] != c1)) ++res;
    return res;
}

void construct(string &s, char c0, char c1) {
    int n = s.length();
    Rep(i, n) if (i % 2 == 0) s[i] = c0; else s[i] = c1;
}

pair<vector<string>, int> solve(vector<string> a) {
    int m = a.size();
    int n = a[0].size();
    VI p;
    Rep(i, 4) p.pb(i);
    vector<string> res;
    int bestcost = -1;
    do {
    // Rep(k, 6) {
        vector<string> cur(m);
        int cost = 0;
        Rep(i, m) {
            char c[2];
            int base = (i % 2 == 0) ? 0 : 2;
            c[0] = chars[p[0 + base]];
            c[1] = chars[p[1 + base]];
            // pair<string, int> s1 = get(a[i], c[0], c[1]);
            // pair<string, int> s2 = get(a[i], c[1], c[0]);
            // if (s1.se < s2.se) cur[i] = s1.fi;
            // else cur[i] = s2.fi;
            // cost += min(s1.se, s2.se);
            int cost1 = get(a[i], c[0], c[1]);
            int cost2 = get(a[i], c[1], c[0]);
            cost += min(cost1, cost2);
            cur[i] = string(n, ' ');
            if (cost1 < cost2) construct(cur[i], c[0], c[1]);
            else construct(cur[i], c[1], c[0]);
        }
        if (bestcost == -1 || bestcost > cost) {
            bestcost = cost;
            res = cur;
        }
    // }
    } while(next_permutation(p.begin(), p.end()));
    return MP(res, bestcost);
}

int main() {
    cin >> m >> n;
    // m = 150000;
    // n = 2;
    a = vector<string>(m);
    Rep(i, m) {
        string s;
        cin >> s;
        // cout << "read " << s << endl;
        a[i] = s;
    }
    pair<vector<string>, int> sol1 = solve(a);
    pair<vector<string>, int> sol2 = solve(flip(a));
    vector<string> res = sol1.fi;
    if (sol2.se < sol1.se) res = flip(sol2.fi);
    Rep(i, m) {
        cout << res[i] << endl;
    }
    // cout << min(sol1.se, sol2.se) << endl;
    return 0;
}