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

int t, n, cr, cd;
vpi p;
vi d;
 
void solve() {
    cin >> n;
    p.rsz(n);
    F0R(i, n) cin >> p[i].F;
    F0R(i, n) cin >> p[i].S;
    sort(all(p));
    d.rsz(n);
    F0R(i, n) d[i]=p[i].F-p[i].S;
    int ans = 0;
    cr=1; cd=0;
    F0R(i, n) {
        if (d[i]==cd && cd%2==0) ans += p[i].F-cr;
        else if (d[i] != cd) {
            if (cd%2!=0) {
                cd++;
                ans++;
            }
            ans += (d[i]-cd)/2;
        }
        cr=p[i].F;
        cd=d[i];
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