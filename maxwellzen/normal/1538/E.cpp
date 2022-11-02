#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

struct var {
    ll len, ans;
    string first, last, str;
    void init(string s) {
        len=s.length();
        ans=0;
        if (len<10) str=s;
        if (len >= 3) {
            first=s.substr(0, 3);
            last=s.substr(len-3, 3);
        }
        F0R(i, len-3) if (s.substr(i, 4)=="haha") ans++;
    }
    void add(var other) {
        if (len+other.len<10) {
            len += other.len;
            str += other.str;
            ans=0;
            if (len >= 3) {
                first=str.substr(0, 3);
                last=str.substr(len-3, 3);
            }
            F0R(i, len-3) if (str.substr(i, 4)=="haha") ans++;
        } else if (len<3) {
            first=str + other.first;
            last=other.last;
            len += other.len;
            ans += other.ans;
            F0R(i, first.length()-3) if (first.substr(i, 4)=="haha") ans++;
            first=first.substr(0, 3);
        } else if (other.len<3) {
            last=last+other.str;
            len += other.len;
            F0R(i, last.length()-3) if (last.substr(i, 4)=="haha") ans++;
            last=last.substr(last.length()-3, 3);
        } else {
            ans += other.ans;
            len += other.len;
            string mid = last+other.first;
            F0R(i, mid.length()-3) if (mid.substr(i, 4)=="haha") ans++;
            last=other.last;
        }
    }
};

int t, n;
map<string, var> vars;
string a, symbol, b, c;
var x, y, z;
 
void solve() {
    cin >> n;
    vars.clear();
    F0R(i, n) {
        cin >> a >> symbol;
        if (symbol==":=") {
            cin >> b;
            vars[a].init(b);
        } else {
            cin >> b >> symbol >> c;
            x=vars[b];
            x.add(vars[c]);
            vars[a]=x;
        }
        // cout << a << ' ';
        // if (vars[a].len<10) cout << vars[a].str << ' ' << vars[a].ans << endl;
        // else cout << vars[a].first << ' ' << vars[a].last << ' ' << vars[a].ans << endl;
    }
    cout << vars[a].ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}