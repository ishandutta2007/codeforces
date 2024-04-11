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

int t, n, z;
string s;
vvi dp;
 
void solve() {
    cin >> n >> s;
    z=0;
    for (char c : s) if (c=='0') z++;
    bool ispal=true;
    F0R(i, n) if (s[i] != s[n-1-i]) ispal=false;
    if (ispal) {
        if (z%2==0 || z==1) cout << "BOB\n";
        else cout << "ALICE\n";
    } else {
        if (n%2!=0 && s[n/2]=='0' && z==2) cout << "DRAW\n";
        else cout << "ALICE\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}