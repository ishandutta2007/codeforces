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
string s;
vb b, c;
bool cont;
 
void solve() {
    cin >> n >> m >> s;
    b.rsz(n);
    F0R(i, n) b[i]=(s[i]=='1');
    cont=true;
    F0R(i, m) {
        if (!cont) break;
        cont=false;
        c=b;
        if (b[1]) c[0]=true;
        if (b[n-2]) c[n-1]=true;
        FOR(j, 1, n-1) if ((b[j+1]^b[j-1]) && !b[j]) {
            c[j]=true;
            cont=true;
        }
        b=c;
    }
    F0R(i, n) cout << b[i] ? '1' : '0';
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