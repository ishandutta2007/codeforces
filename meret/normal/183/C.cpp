//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT

const int N = 100005;

int n, m;

vector<PII> e[N];
int depth[N];
bool visiting[N];
int parent[N];

int result;

int gcd(int a, int b) {
    while (a && b) {
        a > b ? a %= b : b %= a;
    }
    return a + b;
}

void dfs(int x) {
    visiting[x] = true;
    FORE (it, e[x]) {
        int v = it->ST;
        if (parent[v] != 0) {
            if (visiting[v]) {
                result = gcd(result, abs(depth[x] - depth[v] + it->ND));
            }
        } else {
            depth[v] = depth[x] + it->ND;
            parent[v] = parent[x];
            dfs(v);
        }
    }
    visiting[x] = false;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].PB(MP(b, 1));
        e[b].PB(MP(a, -1));
    }

    result = 0;

    for (int i = 1; i <= n; ++i) {
        if (parent[i] == 0) {
            parent[i] = i;
            dfs(i);
        }
    }

    if (result == 0) {
        result = n;
    }

    printf("%d\n", result);

    return 0;
}