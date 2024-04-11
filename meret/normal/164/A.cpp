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

const int N = 100005;

int n;

vector<bool> bfs(const vector<int>& starting, vector<int>* e) {
    vector<bool> result(n + 1, false);
    queue<int> q;
    FORE (it, starting) {
        result[*it] = true;
        q.push(*it);
    }
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        FORE (it, e[c]) {
            if (!result[*it]) {
                result[*it] = true;
                q.push(*it);
            }
        }
    }
    return result;
}

vector<int> e[N];
vector<int> re[N];

int m;

int states[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &states[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (states[b] != 1) {
            e[a].PB(b);
            re[b].PB(a);
        }
    }
    vector<bool> v1, v2;
    {
        vector<int> starting;
        for (int i = 1; i <= n; ++i) {
            if (states[i] == 1) {
                starting.PB(i);
            }
        }
        v1 = bfs(starting, e);
    }
    {
        vector<int> starting;
        for (int i = 1; i <= n; ++i) {
            if (states[i] == 2) {
                starting.PB(i);
            }
        }
        v2 = bfs(starting, re);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", (int) (v1[i] && v2[i]));
    }
}