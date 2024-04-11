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

int n, k;
ll m=1e9+7, p=9973;
vll h, pexp;
string s, unit;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s;
    pexp.rsz(n+1);
    pexp[0]=1;
    FOR(i, 1, n+1) pexp[i]=(pexp[i-1]*p)%m;
    h.rsz(n+1);
    h[0]=0;
    FOR(i, 1, n+1) {
        h[i] = ((h[i-1]*p)%m + s[i-1])%m;
    }
    unit=s[0];
    FOR(i, 1, n) {
        int l=0, r=n-1-i, ans=-1;
        while (l <= r) {
            int mid = (l+r)/2;
            ll h1 = h[mid+1], h2 = h[i+mid+1]-(h[i]*pexp[mid+1])%m;
            while (h2<0) h2 += m;
            if (h1==h2) {
                ans=mid;
                l=mid+1;
            } else r=mid-1;
        }
        if (ans==n-1-i) break;
        if (s[ans+1]<s[i+ans+1]) break;
        unit += s[i];
    }
    while (unit.length()<k) unit = unit+unit;
    unit = unit.substr(0, k);
    cout << unit << '\n';
}