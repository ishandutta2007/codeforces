// another fine solution by misof
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

string A;
int bestpal[1024][1024];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A;
    for (int l=2; l<=SIZE(A); ++l) {
        for (int a=0; a+l<=SIZE(A); ++a) {
            int b = a+l;
            if (A[a] == A[b-1]) bestpal[a][b] = bestpal[a+1][b-1];
            else bestpal[a][b] = min( bestpal[a+1][b], bestpal[a][b-1] );
        }
    }
    int lo = 0, hi = SIZE(A);
    string palindrom;
    while (hi - lo > 1) {
        if (A[lo] == A[hi-1]) {
            palindrom += A[lo];
            ++lo;
            --hi;
        } else {
            if (bestpal[lo+1][hi] < bestpal[lo][hi-1]) {
                palindrom += A[lo];
                ++lo;
            } else {
                palindrom += A[hi-1];
                --hi;
            }
        }
    }
    string rpalindrom = palindrom;
    reverse( rpalindrom.begin(), rpalindrom.end() );
    if (hi == lo) cout << palindrom << rpalindrom << endl; else cout << palindrom << A[lo] << rpalindrom << endl;
    
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread