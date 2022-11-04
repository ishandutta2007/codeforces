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
#include <unordered_map>
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
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int N = 222222;

VI adj[N], id[N];

#define map unordered_map

typedef int CACHE[N * 10];

CACHE is_line_tree_cache, is_line_cache, is_special_cache;

bool is_special(int u, int fa, int key);
bool is_line_tree(int u, int fa, int key);
bool is_line(int u, int fa, int key);

bool is_special(int u, int fa, int key) {
 //   map<long long, bool>::iterator iter = is_special_cache.find(key);
    // if (iter != is_special_cache.end()) {
    if (is_special_cache[key]) {
        return is_special_cache[key] == 2;
    }
    int special_count = 0;
    bool ret = true;
    TR(it, adj[u]) {
        if (*it == fa) continue;
        if (!is_special(*it, u, id[u][it - adj[u].begin()])) {
            ret = false;
            break;
        }
        if (!is_line_tree(*it, u, id[u][it - adj[u].begin()])) {
            ++special_count;
        }
        if (special_count > 1) break;
    }
    if (special_count > 1) ret = false;
    is_special_cache[key] = ret ? 2 : 1;
    return ret;
}

bool is_line_tree(int u, int fa, int key) {
    // map<long long, bool>::iterator iter = is_line_tree_cache.find(key);
    // if (iter != is_line_tree_cache.end()) {
    if (is_line_tree_cache[key]) {
        return is_line_tree_cache[key] == 2;
    }
    int cnt = 0;
    TR(it, adj[u]) {
        if (*it == fa) continue;
        if (cnt > 1 || !is_line(*it, u, id[u][it - adj[u].begin()])) {
            is_line_tree_cache[key] = 1;
            return false;
        }
        ++cnt;
    }
    is_line_tree_cache[key] = 2;
    return true;
}

bool is_line(int u, int fa, int key) {
    // map<long long, bool>::iterator iter = is_line_cache.find(key);
    // if (iter != is_line_cache.end()) {
    if (is_line_cache[key]) {
        return is_line_cache[key] == 2;
    }
    int cnt = 0;
    TR(it, adj[u]) {
        if (*it == fa) continue;
        if (cnt || !is_line(*it, u, id[u][it - adj[u].begin()])) {
           // cout << "is_line(" << u << ", " << fa << ") is false" << endl;
            is_line_cache[key] = 1;
            return false;
        }
        ++cnt;
    }
    // cout << "is_line(" << u << ", " << fa << ") is true" << endl;
    is_line_cache[key] = 2;
    return true;
}

int main() {
    int n;
    cin >> n;
    int all = 0;
    REP(i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        adj[u].PB(v);
        id[u].PB(all++);
        adj[v].PB(u);
        id[v].PB(all++);
    }
    // cout << "is_special() = " << is_special(1, 0) << endl;
    bool result = false;
    REP(u, n) {
        bool ret = true;
        int special_count = 0;
        TR(it, adj[u]) {
            if (!is_special(*it, u, id[u][it - adj[u].begin()])) {
                ret = false;
                // cout << "HERE with " << *it << ", " << u << endl;
                break;
            }
            if (!is_line_tree(*it, u, id[u][it - adj[u].begin()])) {
                ++special_count;
                // cout << "HERE2" << endl;
            }
            if (special_count > 2) break;
        }
        if (special_count > 2) {
            ret = false;
        }
        if (ret) {
            result = true;
            break;
        }
    }
    cout << (result ? "Yes" : "No") << endl;
    return 0;
}