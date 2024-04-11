#include <bits/stdc++.h>

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
vi a, p;

void solve() {
    cin >> n;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    p.rsz(n+1);
    p[0]=0;
    F0R(i, n) {
        p[i+1]=p[i]^a[i];
    }
    if (p[n]==0) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (p[i]==(p[j]^p[i]) && p[i]==(p[n]^p[j])) {
                cout << "YES\n";
                return;
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