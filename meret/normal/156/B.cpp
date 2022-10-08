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

int countYes;
int countNo;

int yes[100005];
int no[100005];

int answer[100005];

bool may[100005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        answer[i] = x;
        if (x > 0) {
            ++yes[x];
            ++countYes;
        } else {
            ++no[-x];
            ++countNo;
        }
    }
    int nMay = 0;
    for (int i = 1; i <= n; ++i) {
        may[i] = ((yes[i] + countNo - no[i]) == m);
        nMay += may[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (answer[i] > 0) {
            if (may[answer[i]] && nMay == 1) {
                puts("Truth");
            } else if (may[answer[i]]) {
                puts("Not defined");
            } else {
                puts("Lie");
            }
        } else {
            if (may[-answer[i]] && nMay == 1) {
                puts("Lie");
            } else if (may[-answer[i]]) {
                puts("Not defined");
            } else {
                puts("Truth");
            }
        }
    }
}