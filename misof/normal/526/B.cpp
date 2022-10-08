// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int main() {
    int N; cin >> N;
    vector<int> A(1<<(N+1));
    for (int n=2; n<(1<<(N+1)); ++n) cin >> A[n];
    vector<int> P(1<<(N+1),0);
    int answer = 0;
    for (int n=(1<<N)-1; n>=1; --n) {
        int left = A[2*n] + P[2*n];
        int right = A[2*n+1] + P[2*n+1];
        answer += abs( left - right );
        P[n] = max( left, right );
    }
    cout << answer << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread