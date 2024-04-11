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

int n;
set<array<int, 4>> pts;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    F0R(i, n) {
        array<int, 4> cur;
        cin >> cur[0] >> cur[1] >> cur[2];
        cur[3]=i+1;
        pts.insert(cur);
    }
    while (! pts.empty()) {
        array<int, 4> cur = *pts.begin(), c2=cur;
        c2[3]=0;
        pts.erase(pts.begin());
        F0R(i, 4) {
            auto it = pts.lower_bound(c2);
            if (i>0 && (*it)[i-1] != c2[i-1]) it--;
            c2[i]=(*it)[i];
        }
        cout << cur[3] << ' ' << c2[3] << '\n';
        pts.erase(c2);
    }
}