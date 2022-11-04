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
typedef pair<int,int> PII;
typedef long long int64;
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int mat[50][3];
int sum[3];

struct Rec {
    int a, b, c;
    int track;

    Rec(int a, int b, int c, int track) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->track = track;
    }

    PII asDif() const{
        return MP(a - b, a - c);
    }

    bool operator < (const Rec& o) const {
        if (asDif() != o.asDif()) {
            return asDif() < o.asDif();
        }

        return a + b + c > o.a + o.b + o.c;
    }

    int getSum() {
        return a + b + c;
    }
};
vector< Rec > cache;

void dfs(int now, int target, int a, int b, int c, int track) {
    if (now == target) {
        // printf("a=%d,b=%d,c=%d\n", a, b, c);
        cache.PB(Rec(a, b, c, track));
        return;
    }

    dfs(now + 1, target, a + mat[now][0], b, c, track * 4 + 0);
    dfs(now + 1, target, a, b + mat[now][1], c, track * 4 + 1);
    dfs(now + 1, target, a, b, c + mat[now][2], track * 4 + 2);
}

int ansCost;
int ans[2];

void dfs2(int now, int target, int a, int b, int c, int track) {
    if (now == target) {
        // a = a + a'
        // b = b + b'
        // c = c + c'
        // sum0 - a = sum1 - b = sum2 - c
        // sum0 - sum1 = a - b = a + a' - b - b'
        // a' - b' = (sum0 - sum1) - (a - b)
        // a' - c' = (sum0 - sum2) - (a - c)
        int low = 0, high = cache.size() - 1;
        int ta = (sum[0] - sum[1]) - (a - b);
        int tb = (sum[0] - sum[2]) - (a - c);
        while (low < high) {
            int mid = ((low + high) >> 1) + 1;
            if (cache[mid].asDif() <= MP(ta, tb)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        // printf("a=%d,b=%d,c=%d,ta=%d,tb=%d,low=%d\n", a, b, c, ta, tb,low);

        if (cache[low].asDif() == MP(ta, tb)) {
            // cout << a + b + c + cache[low].getSum() << endl;
            if (ansCost == -1 || a + b + c + cache[low].getSum() < ansCost) {
                ansCost = a + b + c + cache[low].getSum();
                ans[0] = cache[low].track;
                ans[1] = track;
            }
        }

        return;
    }

    dfs2(now + 1, target, a + mat[now][0], b, c, track * 4 + 0);
    dfs2(now + 1, target, a, b + mat[now][1], c, track * 4 + 1);
    dfs2(now + 1, target, a, b, c + mat[now][2], track * 4 + 2);
}

char dir[] = "LMW";

void out(int x) {
    assert(x < 3);
    REP(i, 3) {
        if (i != x) cout << dir[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    REP(i, n) {
        REP(j, 3) {
            cin >> mat[i][j];
            sum[j] += mat[i][j];
        }
    }

    int half = (n + 1) / 2;
    dfs(0, half, 0, 0, 0, 0);

    SORT(cache);

    ansCost = -1;
    dfs2(half, n, 0, 0, 0, 0);

    if (ansCost == -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    REP(i, half) {
        out((ans[0] >> (2 * (half - 1 - i))) & 3);
    }
    REP(i, n - half) {
        out((ans[1] >> (2 * (n - half - 1 - i))) & 3);
    }
    return 0;
}