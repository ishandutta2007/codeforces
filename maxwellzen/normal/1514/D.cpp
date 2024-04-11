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

int n, q, l, r;
vi a;
vvi freq;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a.rsz(n);
    freq.rsz(n);
    F0R(i, n) {cin >> a[i]; a[i]--; freq[a[i]].pb(i);}
    F0R(i, q) {
        cin >> l >> r;
        l--; r--;
        int m = r-l+1, f=0;
        F0R(rep, 40) {
            int ind = rng()%m + l, e=a[ind];
            f = max(f, (int)(upper_bound(all(freq[e]), r) - lower_bound(all(freq[e]), l)));
            if (f>(m+1)/2) break;
        }
        if (f>(m+1)/2) cout << 2*f-m << '\n';
        else cout << 1 << '\n';
    }
}