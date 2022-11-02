#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
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
int t, n;
int dts[4] = {-2, -1, 1, 2};
string s;

void solve() {
    cin >> s;
    int ans = 0;
    FOR(i, 1, s.length()) {
        if (s[i]==s[i-1] || (i>1 && s[i]==s[i-2])) {
            ans++;
            set<char> no;
            for (int d = -2; d < 3; d++) {
                if (d==0) continue;
                if (i+d>=0 && i+d<s.length()) no.insert(s[i+d]);
            }
            for (char c = 'a'; c <= 'z'; c++) {
                if (no.find(c)==no.end()) {
                    s[i]=c;
                    break;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}