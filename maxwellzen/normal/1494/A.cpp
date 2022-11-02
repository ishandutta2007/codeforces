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
int t;
string s;

void solve() {
    cin >> s;
    for (int i = -1; i < 2; i += 2) {
        for (int j = -1; j < 2; j+= 2) {
            for (int k = -1; k < 2; k += 2) {
                int cur = 0;
                bool works=true;
                F0R(l, s.length()) {
                    if (s[l]=='A') cur += i;
                    else if (s[l]=='B') cur += j;
                    else if (s[l]=='C') cur += k;
                    if (cur<0) works=false;
                }
                if (works && cur==0) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}