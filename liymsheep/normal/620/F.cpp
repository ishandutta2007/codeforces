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

using namespace std;

const int N = 1000000 + 10;

int pSum[N];

//  k    1^2^k  1^2^(k-1)
int a[N], best[N];

vector<PII> leftEnds[N];

int main() {
    pSum[0] = 0;
    for (int i = 1; i < N; ++i) {
        pSum[i] = pSum[i - 1] ^ i;
    }

    int n, m;
    cin >> n >> m;
    REP(i, n) {
        scanf("%d", &a[i]);
    }
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        leftEnds[v].PB(MP(u, i));
    }

    VI answer(m, 0);

    REP(i, n) {
        for (int j = i; j >= 0; --j) {
            best[j] = max(best[j], pSum[max(a[i], a[j])] ^ pSum[min(a[i], a[j]) - 1]);
            if (j != i) {
                best[j] = max(best[j], best[j + 1]);
            }
        }
        TR(it, leftEnds[i]) {
            answer[it->second] = best[it->first];
        }
    }

    TR(it, answer) cout << *it << endl;
    return 0;
}