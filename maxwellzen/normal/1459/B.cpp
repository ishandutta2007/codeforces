#include <bits/stdc++.h>

using namespace std;

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
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if (n%2==0) {
        cout << pow((n+2)/2, 2) << endl;
    } else {
        cout << 2 * ((n+1)/2) * ((n+3)/2) << endl;
    }
//    set<pi> pre;
//    set<pi> nex;
//    nex.insert(mp(0, 0));
//    F0R(i, n) {
//        pre = nex;
//        nex.clear();
//        trav(p, pre) {
//            if (i%2==0) {
//                nex.insert(mp(p.F, p.S+1));
//                nex.insert(mp(p.F, p.S-1));
//            } else {
//                nex.insert(mp(p.F+1, p.S));
//                nex.insert(mp(p.F-1, p.S));
//            }
//        }
//    }
//    trav(p, nex) {
//        nex.insert(mp(p.S, p.F));
//    }
//    FOR(i, -(n+1)/2, (n+1)/2 + 1) {
//        FOR(j, -(n+1)/2, (n+1)/2 + 1) {
//            if (nex.find(mp(i, j))==nex.end()) cout << '_';
//            else cout << 'O';
//        }
//        cout << endl;
//    }
}