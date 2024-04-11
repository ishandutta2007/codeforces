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

int height, width;

char t[1005][1005];

int dist[2005];
bool visited[2005];

int main() {
    scanf("%d %d", &height, &width);
    for (int i = 0; i < height; ++i) {
        scanf("%s", t[i]);
    }
    queue<int> q;
    visited[height - 1] = true;
    q.push(height - 1);
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (c < height) {
            for (int i = 0; i < width; ++i) {
                if (!visited[height + i] && t[c][i] == '#') {
                    visited[height + i] = true;
                    dist[height + i] = dist[c] + 1;
                    q.push(height + i);
                }
            }
        } else {
            for (int i = 0; i < height; ++i) {
                if (!visited[i] && t[i][c - height] == '#') {
                    visited[i] = true;
                    dist[i] = dist[c] + 1;
                    q.push(i);
                }
            }
        }
    }

    if (!visited[0]) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[0]);
    }
}