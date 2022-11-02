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

ll q, ldep, t, v, w, bought, spent;
vll a, c;
vvi up;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    while (pow(2, ldep)<q+1) ldep++; ldep++;
    up.rsz(q+1, vi(ldep, 0));
    a.rsz(q+1); c.rsz(q+1);
    cin >> a[0] >> c[0];
    FOR(i, 1, q+1) {
        cin >> t;
        if (t==1) {
            cin >> up[i][0] >> a[i] >> c[i];
            FOR(j, 1, ldep) up[i][j]=up[up[i][j-1]][j-1];
        } else {
            cin >> v >> w;
            bought=0; spent=0;
            while (a[v]>0 && bought<w) {
                int copy = v;
                R0F(j, ldep) if (a[up[copy][j]]>0) copy=up[copy][j];
                ll b = min(a[copy], w-bought);
                a[copy] -= b;
                bought += b;
                spent += b*c[copy];
            }
            cout << bought << ' ' << spent << endl;
        }
    }
}