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
int t, n, a[200001];

void solve() {
    cin >> n;
    F0R(i, n) cin >> a[i];
    vector<bool> drench(n, false);
    int todrench = n;
    R0F(i, n) {
        todrench = min(todrench, i-a[i]);
        if (i>todrench) drench[i]=true;
        else drench[i]=false;
    }
    F0R(i, n) {
        cout << (drench[i] ? 1 : 0) << ' ';

    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}