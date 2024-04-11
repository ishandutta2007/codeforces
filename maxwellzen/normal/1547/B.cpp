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

int t, n, aloc;
string s, s2;
bool ans;
 
void solve() {
    cin >> s;
    ans = true;
    n = s.length();
    s2 = s;
    sort(all(s2));
    F0R(i, n) if (s2[i] != 'a'+i) ans=false;
    F0R(i, n) if (s[i]=='a') aloc=i;
    F0R(i, aloc) if (s[i]<s[i+1]) ans=false;
    FOR(i, aloc, n-1) if (s[i]>s[i+1]) ans=false;
    if (ans) cout << "YES\n";
    else cout << "NO\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}