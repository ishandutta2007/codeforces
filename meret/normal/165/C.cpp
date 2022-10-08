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

int main() {
    ios_base::sync_with_stdio(false);
    int k;
    string s;
    cin >> k >> s;
    vector<int> ones;
    ones.push_back(-1);
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }
    ones.push_back((int) s.size());
    LL result = 0;
    if (k > 0) {
        for (int i = k; i < (int) ones.size() - 1; ++i) {
            result += (ones[i - k + 1] - ones[i - k]) * (LL) (ones[i + 1] - ones[i]);
        }
    } else {
        for (int i = 1; i < (int) ones.size(); ++i) {
            result += (ones[i] - ones[i - 1]) * (LL) (ones[i] - ones[i - 1] - 1) / 2;
        }
    }
    cout << result << "\n";
}