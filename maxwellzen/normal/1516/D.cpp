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
int n, q, lef, righ;
vi a, p, last, r;
vector<bool> isp;
vector<vi> up;

void sieve() {
    isp.rsz(10001, true);
    for (int i = 2; i < 10001; i++) {
        if (isp[i]) {
            p.pb(i);
            for (int j = i*i; j < 10001; j += i) isp[j]=false;
        }
    }
}

int solve() {
    if (up[lef][0]>righ) return 1;
    for (int i = 1; i < up[0].size(); i++) {
        if (up[lef][i]>righ) {
            lef=up[lef][i-1];
            return (1<<(i-1))+solve();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    cin >> n >> q;
    a.rsz(n);
    F0R(i, n) cin >> a[i];
    last.rsz(100001);
    fill(last.begin(), last.end(), n);
    r.rsz(n, n);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < p.size(); j++) {
            if (p[j]*p[j]>a[i]) break;
            if (a[i]%p[j]==0) {
                r[i]=min(r[i], last[p[j]]);
                last[p[j]]=i;
                while (a[i]%p[j]==0) a[i]=a[i]/p[j];
            }
        }
        if (a[i]>1) {
            r[i]=min(r[i], last[a[i]]);
            last[a[i]]=i;
        }
        if (i<n-1) r[i]=min(r[i], r[i+1]);
    }
    int dep = 0, ind=0;
    while (ind<n) {
        dep++;
        ind=r[ind];
    }
    int log = 1;
    while (pow(2, log) <= dep) log++;
    log++;
    up.rsz(n+1, vi(log));
    F0R(i, n) up[i][0]=r[i];
    up[n][0]=n;
    FOR(i, 1, log) {
        F0R(j, n+1) up[j][i]=up[up[j][i-1]][i-1];
    }
    F0R(i, q) {
        cin >> lef >> righ;
        lef--; righ--;
        cout << solve() << '\n';
    }
}