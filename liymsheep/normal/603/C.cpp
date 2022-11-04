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

#include <unordered_set>
#include <unordered_map>

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int k;

int sg0[5] = {0, 1, 0, 1, 2};

int go(int n) {
    if (n < 5) {
        return sg0[n];
    }
    if (n & 1) {
        return 0;
    }
    int sg1 = go(n - 1);
    int sg2 = go(n / 2);
    bool ouc[3] = {0, 0, 0};
    ouc[sg1] = ouc[sg2] = 1;
    for (int i = 0; i <= 2; ++i) {
        if (!ouc[i]) {
            return i;
        }
    }
    assert(false);
    return -1;
}

int getSg(int n) {
    if (k % 2 == 0) {
        if (n <= 2) {
            return n;
        }
        return n % 2 ? 0 : 1;
    }
    return go(n);
}

int main() {
    int n;
    cin >> n >> k;
    int sg = 0;
    REP(i, n) {
        int a;
        scanf("%d", &a);
        sg ^= getSg(a);
    }
    cout << (!sg ? "Nicky" : "Kevin") << endl;
    return 0;
}