// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans;
    if (a==b) {
        REP(i,a) ans.push_back(1);
        REP(i,b) ans.push_back(2);
    }
    if (a<b) {
        priority_queue< pair<int,int> > Q;
        REP(i,n) { int x; cin >> x; Q.push(make_pair(x,-i)); }
        ans.resize(n,2);
        REP(i,a) { ans[-Q.top().second]=1; Q.pop(); }
    }
    if (a>b) {
        priority_queue< pair<int,int> > Q;
        REP(i,n) { int x; cin >> x; Q.push(make_pair(x,i)); }
        ans.resize(n,1);
        REP(i,b) { ans[Q.top().second]=2; Q.pop(); }
    }
    REP(i,n) cout << ans[i] << (i==n-1?"\n":" ");
    return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread