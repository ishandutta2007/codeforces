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

const int N = 500;

int dis[N];
int conn[N][N];

int main(){
    int n, m;
    cin >> n >> m;
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        conn[u][v] = conn[v][u] = 1;
    }

    FILL(dis, -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, n) {
            if (dis[i] == -1 && conn[u][i]) {
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }

    int d1 = dis[n - 1];
    FILL(dis, -1);
    dis[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        REP(i, n) {
            if (dis[i] == -1 && !conn[u][i]) {
                dis[i] = dis[u] + 1;
                q.push(i);
            }
        }
    }
    int d2 = dis[n - 1];
    if (d1 == -1 || d2 == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << max(d1, d2) << endl;
    return 0;
}