#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef long long LL;
typedef pair<LL,LL> PII;
typedef long long int64;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int main() {
    int n, m;
    cin >> n >> m;
    vector<PII> a, b;
    REP(i, m) {
        int c, in;
        scanf("%d%d", &c, &in);
        if (in) {
            a.PB(MP(c, i));
        } else {
            b.PB(MP(c, i));
        }
    }
    SORT(a);
    SORT(b);

    vector<PII> ans(m);
    REP(i, n - 1) {
        ans[a[i].second] = MP(0, i + 1);
    }
    bool bad = false;
    int ca = 1, cb = 0;
    TR(it, b) {
        if (it->first < a[ca].first) {
            bad = true;
            break;
        }
        ++cb;
        ans[it->second] = MP(ca - cb + 1, ca + 1);
        if (cb == ca) {
            ++ca;
            cb = 0;
        }
    }

    if (bad) {
        cout << -1 << endl;
        return 0;
    }

    REP(i, m) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }


    return 0;
}