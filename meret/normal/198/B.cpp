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

int n, k;

string wall[2];

bool bfs(PII start) {
    vector<vector<int> > visited(n, vector<int>(2, -1));
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < 2; ++c) {
            if (wall[c][i] == 'X') {
                visited[i][c] = -2;
            }
        }
    }
    queue<PII> q;
    visited[start.ST][start.ND] = 0;
    q.push(start);
    while (!q.empty()) {
        int x = q.front().ST;
        int c = q.front().ND;
        q.pop();
        if (x + k >= n) {
            return true;
        }
        int water = visited[x][c];
        if (x - 1 > water && visited[x - 1][c] == -1) {
            visited[x - 1][c] = visited[x][c] + 1;
            q.push(MP(x - 1, c));
        }
        if (visited[x + 1][c] == -1) {
            visited[x + 1][c] = visited[x][c] + 1;
            q.push(MP(x + 1, c));
        }
        if (visited[x + k][!c] == -1) {
            visited[x + k][!c] = visited[x][c] + 1;
            q.push(MP(x + k, !c));
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    cin >> wall[0] >> wall[1];
    printf("%s\n", bfs(MP(0, 0)) ? "YES" : "NO");
}