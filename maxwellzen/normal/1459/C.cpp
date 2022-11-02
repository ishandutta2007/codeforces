#include <bits/stdc++.h>

using namespace std;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
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
ll t, n, m;
vll a, b;

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    if (a<b) swap(a, b);
    while (b > 0) {
        a %= b;
        if (a<b) swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.rsz(n);
    b.rsz(m);
    F0R(i, n) cin >> a[i];
    F0R(i, m) cin >> b[i];
    ll agcd = 0;
    FOR(i, 1, n) agcd = gcd(agcd, abs(a[i] - a[0]));
    F0R(i, m) cout << gcd(agcd, a[0]+b[i]) << ' ';
    cout << '\n';
}