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

const int N = 250005;

struct Gripper {
    int mass;
    int radius;
    int power;
    LL dist;
};

bool operator < (const Gripper &a, const Gripper &b) {
    return a.mass < b.mass;
}

LL sq(LL x) {
    return x * x;
}

vector<int> to_process[N];

Gripper grippers[N];

bool visited[N];

int x, y, p, r, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> p >> r >> n;
    for (int i = 1; i <= n; ++i) {
        int cx, cy;
        cin >> cx >> cy >> grippers[i].mass >> grippers[i].power >> grippers[i].radius;
        grippers[i].dist = sq(cx - x) + sq(cy - y);
    }
    sort(grippers + 1, grippers + n + 1);
    map<LL, int> dists;
    for (int i = 1; i <= n; ++i) {
        dists[grippers[i].dist] = 0;
    }
    int cur = 0;
    FORE (it, dists) {
        it->ND = ++cur;
    }
    for (int i = n; i >= 1; --i) {
        int c = dists[grippers[i].dist];
        while (c <= n) {
            to_process[c].PB(i);
            c += c & -c;
        }
    }
    queue<PII> q;
    q.push(MP(p, r));
    int result = -1;
    while (!q.empty()) {
        ++result;
        p = q.front().ST;
        {
            int le = 0, ri = n;
            while (le < ri) {
                int c = (le + ri + 1) / 2;
                if (grippers[c].mass > p) {
                    ri = c - 1;
                } else {
                    le = c;
                }
            }
            p = le;
        }
        r = q.front().ND;
        q.pop();
        map<LL, int>::iterator it = dists.upper_bound(sq(r));
        if (it == dists.end()) {
            r = cur;
        } else {
            r = it->ND - 1;
        }
        int c = r;
        while (c > 0) {
            while (!to_process[c].empty() && to_process[c].back() <= p) {
                if (!visited[to_process[c].back()]) {
                    int cur = to_process[c].back();
                    visited[cur] = true;
                    q.push(MP(grippers[cur].power, grippers[cur].radius));
                }
                to_process[c].pop_back();
            }
            c -= c & -c;
        }
    }
    cout << result << endl;
}