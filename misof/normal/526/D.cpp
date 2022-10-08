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
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

vector<long long> KMP(const string &S) {
    vector<long long> kmp( S.size()+1, 0 );
    for (unsigned i=2; i<=S.size(); ++i) {
        int x = kmp[i-1];
        while (x != 0 && S[x] != S[i-1]) x = kmp[x];
        if (S[x] == S[i-1]) ++x;
        kmp[i] = x;
    }
    return kmp;
}

int main() {
    long long N, K; cin >> N >> K;
    string S; cin >> S;

    if (K==1) {
        cout << string(N,'1') << endl;
        return 0;
    }

    vector<long long> kmp = KMP(S);
    vector<long long> period(N+1);
    FOR(n,0,N) period[n] = n-kmp[n];

    vector<long long> update(N+1,0);

    FOR(n,1,N) {
        // FIXME mozno n==0?
        if (n<N && period[n+1]==period[n]) continue;
        //cout << "prefix dlzky " << n << " ma periodu dlzky " << period[n] << endl;
        for (long long m=1; ; ++m) {
            long long lo = K*period[n]*m, hi = (K+1)*period[n]*m;
            if (lo > n) break;
            if (hi > n) hi = n;
            //cout << "prefixy dlzok " << lo << " az " << hi << " su dobre" << endl;
            ++update[lo-1];
            --update[hi];
        }
    }
    
    int kolko = 0;
    REP(n,N) {
        kolko += update[n];
        cout << (kolko ? '1' : '0');
    }
    cout << endl;
    

    //DEBUG(kmp);
    //REP(n,N) cout << n-kmp[n] << " "; cout << endl;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread