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

int t, h, w;
vb row, col;
vector<vb> table;
 
void solve() {
    cin >> h >> w;
    col.clear(); row.clear(); table.clear();
    col.rsz(h-1, false); row.rsz(w-1, false);
    table.rsz(h, vb(w, false));
    if (h%2 != 0 && w%2 != 0) {
        for (int i = 0; i < row.size(); i += 2) row[i]=true;
        for (int i = 0; i < col.size(); i += 2) col[i]=true;
    } else if (h%2==0 && w%2==0) {
        for (int i = 1; i < row.size(); i += 2) row[i]=true;
        for (int i = 1; i < col.size(); i += 2) col[i]=true;
    } else if (h%2==0) {
        for (int i = 1; i < col.size(); i += 2) col[i]=true;
        for (int i = 0; i < row.size(); i += 2) row[i]=true;
    } else {
        for (int i = 0; i < col.size(); i += 2) col[i]=true;
        for (int i = 1; i < row.size(); i += 2) row[i]=true;
    }
    F0R(i, h-1) {
        table[i][0]=table[h-1-i][w-1]=col[i];
    }
    F0R(i, w-1) {
        table[h-1][i]=table[0][w-1-i]=row[i];
    }
    F0R(i, h) {
        F0R(j, w) if (table[i][j]) cout << 1; else cout << 0;
        cout << endl;
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