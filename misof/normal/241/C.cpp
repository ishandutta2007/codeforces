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
// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE
#define SIZE(t) ((int)((t).size()))
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

struct mirror { long long a,b,score; mirror(int l, int r, int s) : a(l), b(r), score(s) {} };
bool operator< (const mirror &A, const mirror &B) { return A.a < B.a; }

int N;
long long HL, origHR, H=100, W=100000;
vector<mirror> TOP, BOT;

inline bool mless(long long n1, long long d1, long long n2, long long d2) {
    return n1*d2 < n2*d1;
}

long long solve(int odrazy) {
    long long cur_score = 0;
    int tm=0, bm=0;
    long long Hdelta = 100-HL;
    Hdelta += H*(odrazy-1);
    if (odrazy%2) Hdelta += 100-origHR; else Hdelta += origHR;
    long long HR = HL+Hdelta;
    // ideme priamkou z (0,HL) do (W,HR)
    for (int o=1; o<=odrazy; ++o) {
        long long HC = H*o;
        long long inum = W*(HC-HL), iden = HR-HL;
        // if (odrazy==6 && HL==20) { DEBUG(inum); DEBUG(iden); }
        if (o%2) {
            // odraz od TOP
            while (tm < SIZE(TOP) && mless(TOP[tm].b,1,inum,iden)) ++tm;
            if (tm == SIZE(TOP)) return 0;
            if (mless(inum,iden,TOP[tm].a,1)) return 0;
            cur_score += TOP[tm].score;
            ++tm;
        } else {
            // odraz od BOT
            while (bm < SIZE(BOT) && mless(BOT[bm].b,1,inum,iden)) ++bm;
            if (bm == SIZE(BOT)) return 0;
            if (mless(inum,iden,BOT[bm].a,1)) return 0;
            cur_score += BOT[bm].score;
            ++bm;
        }
    }
    // cout << odrazy << " -> " << cur_score << endl;
    return cur_score;
}

int main() {
    cin >> HL >> origHR >> N;
    for (int n=0; n<N; ++n) { int v; string c; int a,b; cin >> v >> c >> a >> b; if (c=="T") TOP.push_back(mirror(a,b,v)); else BOT.push_back(mirror(a,b,v)); }
    sort( TOP.begin(), TOP.end() );
    sort( BOT.begin(), BOT.end() );
    long long best_score = 0;
    for (int odrazy=1; odrazy<=N; ++odrazy) best_score = max( best_score, solve(odrazy) );
    swap( TOP, BOT );
    HL = H - HL;
    origHR = H - origHR;
    for (int odrazy=1; odrazy<=N; ++odrazy) best_score = max( best_score, solve(odrazy) );
    cout << best_score << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread