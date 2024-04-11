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

int n, mxdep;
vi dep, dist, p;
vvi bydep;
set<int> solve;

void query(int i) {
    cout << "? " << i+1 << endl;
    F0R(i, n) cin >> dist[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n==2) {
        cout << "!\n1 2" << endl;
        return 0;
    }
    dep.rsz(n);
    dist.rsz(n);
    p.rsz(n, -1);
    bydep.rsz(n);
    p[0]=0;
    query(0);
    mxdep=0;
    F0R(i, n) {
        dep[i]=dist[i];
        bydep[dep[i]].pb(i);
        mxdep = max(mxdep, dep[i]);
    }
    F0R(i, mxdep-1) if (bydep[i].size()==1) for (int j : bydep[i+1]) p[j]=bydep[i][0];
    F0R(i, n) if (p[i]==-1) solve.insert(i);
    while (!solve.empty()) {
        for (int i : bydep[mxdep]) if (solve.find(i)!=solve.end()) {
            query(i);
            vi path(dep[i]+1);
            F0R(j, n) if (dep[j]+dist[j]==dep[i]) path[dep[j]]=j;
            F0R(j, mxdep) {p[path[j+1]]=path[j]; solve.erase(path[j+1]);}
            F0R(j, n) if (dep[j]+dist[j]==dep[i]+2) {p[j]=path[dep[j]-1]; solve.erase(j);};
        }
        mxdep--;
    }
    cout << "!\n";
    FOR(i, 1, n) cout << i+1 << ' ' << p[i]+1 << '\n';
}