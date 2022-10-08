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
    long long n;
    cin >> n;
    long long answer = n;
    for (long long a=n; a>0; --a) {
        if (a*a*a < answer) break;
        for (long long b=a; b>0; --b) {
            if (a*b*b < answer) break;
            for (long long c=b; c>0; --c) {
                if (a*b*c < answer) break;
                long long cur = a;
                long long d1 = __gcd(a,b);
                cur /= d1;
                cur *= b;
                long long d2 = __gcd(cur,c);
                cur /= d2;
                cur *= c;
                answer = max( answer, cur );
            }
        }
    }
    cout << answer << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread