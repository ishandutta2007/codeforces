// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

int main() {
    int N; scanf("%d",&N);
    vector<int> A(N); for (int &a:A) scanf("%d",&a);
    A.push_back( A[N-1] );
    A.insert( A.begin(), A[0] );
    int answer = 0, curl = 0;
    for (int n=1; n<=N; ++n) {
        if (A[n] == A[n-1] || A[n] == A[n+1]) { 
            for (int i=1; i<=curl; ++i) if (2*i<=curl) A[n-i] = A[n]; else A[n-i] = A[n-curl-1];
            answer = max( answer, (curl+1)/2 ); 
            curl = 0; 
        } else ++curl;
    }
    printf("%d\n",answer);
    for (int n=1; n<=N; ++n) printf("%d%s",A[n],n==N?"\n":" ");
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread