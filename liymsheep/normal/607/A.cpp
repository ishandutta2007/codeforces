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

const int N = 1000007;

int last[N];

int main() {
    int n;
    cin >> n;
    vector<PII> a(n);
    REP(i, n) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    SORT(a);
    int ans = 0x3f3f3f3f;
    last[0] = 1;
    REP(i, n) {
        if (!i) continue;
        int low = 0, high = i - 1;
        int at = a[i].first - a[i].second;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (a[mid].first >= at) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (a[low].first >= at) {
            --low;
        }

        if (low < 0) {
            last[i] = 1;
        } else {
            last[i] = last[low] + 1;
        }
    }


    REP(i, n) ans = min(ans, n - last[i]);
    cout << ans << endl;
    return 0;
}