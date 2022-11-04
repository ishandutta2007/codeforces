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
    int n;
    cin >> n;
    VI a(n);
    VI at(n);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) at[a[i] - 1] = i;
    int ans = n - 1;

    int cur = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (at[i] < at[i + 1]) {
            ++cur;
        } else {
            cur = 1;
        }
        ans = min(ans, i + (n - i - cur));
    }
    cout << ans << endl;
    return 0;
}