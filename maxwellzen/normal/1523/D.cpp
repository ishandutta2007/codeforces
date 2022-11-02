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

int t, n, m, p, half;
vector<vb> a;
vi cnt, valid, rep;
string s;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void solve() {
    cin >> n >> m >> p;
    half = (n+1)/2;
    a.rsz(n, vb(m));
    cnt.rsz(m, 0);
    F0R(i, n) {
        cin >> s;
        F0R(j, m) {
            a[i][j]=(s[j]=='1');
            if (a[i][j]) cnt[j]++;
        }
    }
    F0R(i, m) if (cnt[i]>=half) valid.pb(i);
    if (valid.size()<2) {
        s="";
        F0R(i, m) s += '0';
        F0R(i, valid.size()) s[valid[i]]='1';
        cout << s << '\n';
        return;
    }
    rep.rsz(n, 0);
    F0R(i, n) {
        F0R(j, valid.size()) {
            if (a[i][valid[j]]) rep[i] |= 1<<j;
        }
    }
    int ans=0, sol=0;
    F0R(r, 1000) {
        int cans=0, cand = 0, j, i;
        j = rng()%(n-1)+1;
        i = rng()%j;
        if (half > 1) cand = rep[i]&rep[j];
        else {
            if (rng()%2==0) cand=rep[i];
            else cand=rep[j];
        }
        cans = __builtin_popcount(cand);
        if (cans <= ans) continue;
        int cnt=0;
        F0R(i, n) {
            if ((cand&rep[i])==cand) cnt++;
            else if (__builtin_popcount(cand&rep[i])>ans) {
                cand &= rep[i];
                cans = __builtin_popcount(cand);
                cnt++;
            }
        }
        if (cnt>=half) {
            ans=cans;
            sol=cand;
        }
    }
    s="";
    F0R(i, m) s += '0';
    F0R(i, valid.size()) if (sol&(1<<i)) s[valid[i]]='1';
    cout << s << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}