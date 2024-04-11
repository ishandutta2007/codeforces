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

int starting[2005];
int ending[2005];

int endingBefore[2005];

char s[2005];
int n;

void gen(int l, int r) {
    while (l >= 1 && r <= n && s[l] == s[r]) {
        ++starting[l];
        ++ending[r];
        --l;
        ++r;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> (s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; ++i) {
        gen(i, i);
        gen(i, i + 1);
    }

    for (int i = 1; i <= n; ++i) {
        endingBefore[i] = endingBefore[i - 1] + ending[i];
    }

    LL result = 0;
    for (int i = 1; i <= n; ++i) {
        result += starting[i] * (LL) endingBefore[i - 1];
    }
    cout << result << "\n";

}