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

inline int lowest_p2(int n) {
    int z = 1;
    while (z < n) {
        z *= 2;
    }
    return z;
}

class Tree {
public:
    explicit Tree(int n = 0) :
        z(lowest_p2(n)),
        s(2 * z + 1, 1) {
        for (int i = z - 1; i >= 1; --i) {
            s[i] = s[ls(i)] + s[rs(i)];
        }
    }

    void erase_pth(int p) {
        del(1, 1, z, p);
    }

    bool erased(int x) const {
        return s[z + x - 1] == 0;
    }

private:
    static inline int ls(int x) { return x << 1; }
    static inline int rs(int x) { return (x << 1) + 1; }

    void del(int x, int l, int r, int c) {
        --s[x];
        if (l == r) {
            return;
        }
        int m = (l + r) / 2;
        if (s[ls(x)] >= c) {
            del(ls(x), l, m, c);
        } else {
            del(rs(x), m + 1, r, c - s[ls(x)]);
        }
    }

    int z;
    vector<int> s;
};

int main() {
    ios_base::sync_with_stdio(false);

    Tree trees[26];
    int k;
    string s;

    cin >> k;
    cin >> s;

    map<char, int> occurences;
    FORE (it, s) {
        ++occurences[*it];
    }
    FORE (it, occurences) {
        trees[(int) (it->ST - 'a')] = Tree(it->ND * k);
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p;
        char c;
        cin >> p >> c;
        trees[(int) (c - 'a')].erase_pth(p);
    }

    occurences.clear();
    for (int i = 0; i < (int) s.size() * k; ++i) {
        int occurence = ++occurences[s[i % s.size()]];
        if (!trees[(int) (s[i % s.size()] - 'a')].erased(occurence)) {
            putchar(s[i % s.size()]);
        }
    }
    putchar('\n');

}