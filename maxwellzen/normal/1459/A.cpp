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
int t, n, r[1001], b[1001];
string s;

void solve() {
    cin >> n;
    cin >> s;
    F0R(i, n) r[i]=stoi(s.substr(i, 1));
    cin >> s;
    F0R(i, n) b[i]=stoi(s.substr(i, 1));
    int ans = 0;
    F0R(i, n) {
        if (r[i]==b[i]) continue;
        if (r[i]>b[i]) ans++;
        if (r[i]<b[i]) ans--;
    }
    if (ans>0) cout << "RED\n";
    else if (ans<0) cout << "BLUE\n";
    else cout << "EQUAL\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}