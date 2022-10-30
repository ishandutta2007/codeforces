#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int A, B, C, D; cin >> A >> B >> C >> D;
        int X, Y, X1, Y1, X2, Y2; cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2;
        X1 -= X; Y1 -= Y; X2 -= X; Y2 -= Y;
        int dx = B - A; int dy = D - C;
        if (X2 < dx || X1 > dx || Y2 < dy || Y1 > dy) {
            cout << "NO" << endl;
        } else {
            if ((X1 == X2 && (A+B)>0) || (Y1 == Y2 && (C+D) > 0)) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } 
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343