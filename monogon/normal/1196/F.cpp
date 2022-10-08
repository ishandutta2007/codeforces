
#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

#define ll long long
using namespace std;

// suppose a shortest path has j edges. Then
// it is at least the j + (j - 1) + ... + 1 th
// = j (j + 1) / 2 th
// smallest shortest path.
// So, j (j + 1) / 2 <= k
// j (j + 1) <= 2k <= 800
// j <= 27

// shortest path is the edge with minimum weight
// second shortest path is edge with second smallest weight
// 3rd path is either edge with smallest weight, or a combination of
// an existing shortest path and another shortest path of length 1.

// Maintain a list of the i smallest shortest paths.
// At each iteration, check all pairs of paths to see if they
// can be combined into the (i+1)st shortest path, or if we should choose
// another length-1 path.

struct path {
    int x;
    int y;
    ll w;
    bool operator<(const path &p) const {
        return w == p.w ? x == p.x ? y == p.y ? true : y < p.y : x < p.x : w < p.w;
    }
};

const int MAX_N = 2e5 + 5;
int n, m, k, x, y;
ll w;
path p[MAX_N], p2[MAX_N];
set<pair<int, int> > d;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        p[i] = {x, y, w};
    }
    sort(p, p + m);
    int e = 0;
    path minpath = {-1, -1, LLONG_MAX};

    // d contains the forbidden edges
    for(int i = 0; i < n; i++) {
        d.insert({i, i});
    }
    for(int i = 0; i < k; i++) {
        minpath = {-1, -1, LLONG_MAX};
        for(int j = 0; j < i; j++) {
            for(int l = j + 1; l < i; l++) {
                if(p2[j].w + p2[l].w < minpath.w) {
                    if(p2[j].x == p2[l].x && d.count(make_pair(p2[j].y, p2[l].y)) == 0) {
                        minpath = {p2[j].y, p2[l].y, p2[j].w + p2[l].w};
                    }else if(p2[j].x == p2[l].y && d.count(make_pair(p2[j].y, p2[l].x)) == 0) {
                        minpath = {p2[j].y, p2[l].x, p2[j].w + p2[l].w};
                    }else if(p2[j].y == p2[l].x && d.count(make_pair(p2[j].x, p2[l].y)) == 0) {
                        minpath = {p2[j].x, p2[l].y, p2[j].w + p2[l].w};
                    }else if(p2[j].y == p2[l].y && d.count(make_pair(p2[j].x, p2[l].x)) == 0) {
                        minpath = {p2[j].x, p2[l].x, p2[j].w + p2[l].w};
                    }
                }
            }
        }
        while(e < m && d.count({p[e].x, p[e].y}) > 0) e++;
        if(e < m && p[e].w < minpath.w) {
            minpath = p[e];
            e++;
        }
        d.insert(make_pair(minpath.x, minpath.y));
        d.insert(make_pair(minpath.y, minpath.x));
        p2[i] = minpath;
        // cout << minpath.x << " " << minpath.y << " " << minpath.w << endl;
    }
    cout << minpath.w << endl;
}