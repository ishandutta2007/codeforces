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

const int N = 200007;

int di[N], hi[N];

struct Node {
    LL max_v, max_prefix, max_suffix, di_sum;
} nodes[N * 4];

Node combine(const Node& a, const Node& b) {
    Node c;
    c.max_v = max(a.max_v, b.max_v);
    c.max_v = max(c.max_v, a.max_suffix + b.max_prefix);
    c.di_sum = a.di_sum + b.di_sum;
    c.max_prefix = max(a.max_prefix, a.di_sum + b.max_prefix);
    c.max_suffix = max(b.max_suffix, a.max_suffix + b.di_sum);
    return c;
}

void build(int l, int r, int x) {
    if (l == r) {
        nodes[x].max_v = 0;
        nodes[x].max_prefix = hi[l];
        nodes[x].max_suffix = hi[l] + (LL) di[l];
        nodes[x].di_sum = di[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, x * 2);
    build(mid + 1, r, x * 2 + 1);
    nodes[x] = combine(nodes[x * 2], nodes[x * 2 + 1]);
}

Node get_interval(int left, int right, int l, int r, int x) {
    if (l <= left && r >= right) {
        return nodes[x];
    }

    int mid = (left + right) >> 1;
    if (l <= mid) {
        if (r <= mid) {
            return get_interval(left, mid, l, r, x * 2);
        }
        return combine(get_interval(left, mid, l, r, x * 2),
            get_interval(mid + 1, right, l, r, x * 2 + 1));
    }
    return get_interval(mid + 1, right, l, r, x * 2 + 1);
}

int main() {
    int n, q;
    cin >> n >> q;
    REP(i, n) {
        scanf("%d", &di[i]);
        di[i + n] = di[i];
    }
    REP(i, n) {
        scanf("%d", &hi[i]);
        hi[i] *= 2;
        hi[i + n] = hi[i];
    }
    build(0, 2 * n - 1, 1);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        Node result;
        if (l <= r) {
            result = get_interval(0, 2 * n - 1, r + 1, l + n - 1, 1);
        } else {
            result = get_interval(0, 2 * n - 1, r + 1, l - 1, 1);
        }
        cout << result.max_v << endl;
    }
    return 0;
}