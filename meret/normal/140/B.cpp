#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

vector<int> pref[301];

int n;

vector<int> getPref() {
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        res.PB(a);
    }
    return res;
}

int wouldSend(int t, int x, vector<int>& myPref) {
    int c = 0;
    while (c < n && (myPref[c] == x || myPref[c] > t)) {
        ++c;
    }
    if (c == n) {
        return n;
    }
    int a = 0;
    while (pref[x][a] != myPref[c]) {
        ++a;
    }
    return a;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        pref[i] = getPref();
    }
    vector<int> myPref = getPref();
    for (int i = 1; i <= n; ++i) {
        int ch = 1;
        for (int j = 2; j <= n; ++j) {
            if (wouldSend(j, i, myPref) < wouldSend(ch, i, myPref)) {
                ch = j;
            }
        }
        printf("%d ", ch);
    }
    printf("\n");
}