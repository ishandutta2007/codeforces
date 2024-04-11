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

int t, n, m;
char c;
vi x; vb l;
vi ans;
vvi e;

bool cmp(int p, int q) {
    return x[p] < x[q];
}

int collide(int p, int q) {
    int px, qx;
    if (l[p]) px=-x[p]; else px=x[p];
    if (l[q]) qx=x[q]; else qx=2*m-x[q];
    return (qx-px)/2;
}
 
void solve() {
    cin >> n >> m;
    l.rsz(n); x.rsz(n); ans.rsz(n); e.clear(); e.rsz(2);
    F0R(i, n) cin >> x[i];
    F0R(i, n) {
        cin >> c;
        l[i] = (c=='L');
        if (x[i]%2==0) e[0].pb(i); else e[1].pb(i);
    }
    sort(all(e[0]), cmp);
    sort(all(e[1]), cmp);
    vi s;
    F0R(rep, 2) {
        for (int i : e[rep]) {
            if (s.size()>0 && l[i]) {
                ans[i]=ans[s[s.size()-1]]=collide(s[s.size()-1], i);
                s.erase(--s.end());
            } else s.pb(i);
        }
        while (s.size()>1) {
            ans[s[s.size()-2]]=ans[s[s.size()-1]]=collide(s[s.size()-2], s[s.size()-1]);
            s.erase(--s.end()); s.erase(--s.end());
        }
        if (s.size()==1) ans[s[0]]=-1;
        s.clear();
    }
    F0R(i, n) cout << ans[i] << ' ';
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