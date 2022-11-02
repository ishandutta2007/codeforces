#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAX 123456

int m, n;
vi edges[MAX];
bool mark[MAX] = {};
int height[MAX] = {}, par[MAX] = {};
bool subTree[MAX] = {};
bool vis[MAX] = {};
int dst[MAX] = {};

struct cmp_by_dst {
    bool operator()(const int &a, const int &b) {
        if (dst[a] != dst[b]) {
            return dst[a] > dst[b];
        }
        return a < b;
    }
};

// find height of all nodes
void bfs1()
{
    par[0] = 0;
    height[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(vi::iterator it = edges[cur].begin(); it != edges[cur].end(); ++it) {
            if(height[*it] == 0) {
                height[*it] = height[cur] + 1;
                par[*it] = cur;
                q.push(*it);
            }
        }
    }

    set<pii> q2;
    for(int i = 0; i < n; i++) {
        if(mark[i]) q2.insert(pii(height[i], i));
    }
    int numEdges = 0;
    while(!q2.empty()) {
        int cur = q2.rbegin()->second;
        q2.erase(prev(q2.end()));
//        cerr << cur << " in the tree." << endl;
        subTree[cur] = true;
        if(q2.empty()) {
            break;
        } else {
            numEdges++;
            q2.insert(pii(height[par[cur]], par[cur]));
        }
    }

//    cerr << numEdges << endl;
    int startPoint = -1;
    for (int i = 0; i < n; i++) {
        if (subTree[i]) {
            startPoint = i;
            break;
        }
    }
    assert(startPoint != -1);

    priority_queue<int, vector<int>, cmp_by_dst> q3;

    vis[startPoint] = true;
    dst[startPoint] = 1;
    q3.push(startPoint);
    int nextPoint = startPoint;
    while (!q3.empty()) {
        int cur = q3.top();
        q3.pop();

//        cerr << "Cur: " << cur << ", " << dst[cur] << endl;
        nextPoint = cur;

        if (subTree[par[cur]] && !vis[par[cur]]) {
            vis[par[cur]] = true;
            dst[par[cur]] = dst[cur] + 1;
            q3.push(par[cur]);
        }
        for(vi::iterator it = edges[cur].begin(); it != edges[cur].end(); ++it) {
            if (subTree[*it] && !vis[*it]) {
                vis[*it] = true;
                dst[*it] = dst[cur] + 1;
                q3.push(*it);
            }
        }
    }

    fill_n(vis, n, false);
    fill_n(dst, n, 0);
    startPoint = nextPoint;
    q3.push(startPoint);
    vis[startPoint] = true;
    dst[startPoint] = 1;
    while (!q3.empty()) {
        int cur = q3.top();
        q3.pop();

        nextPoint = cur;

        if (subTree[par[cur]] && !vis[par[cur]]) {
            vis[par[cur]] = true;
            dst[par[cur]] = dst[cur] + 1;
            q3.push(par[cur]);
        }
        for(vi::iterator it = edges[cur].begin(); it != edges[cur].end(); ++it) {
            if (subTree[*it] && !vis[*it]) {
                vis[*it] = true;
                dst[*it] = dst[cur] + 1;
                q3.push(*it);
            }
        }
    }
//    cerr << "De lengte: " << dst[nextPoint] << endl;
//    cerr << "longest distance is between " << nextPoint << ", " << startPoint << endl;

    int lowCity = min(nextPoint, startPoint);
    int totalDistance = 2 * numEdges - (dst[nextPoint] - dst[startPoint]);

    cout << (lowCity + 1) << endl;
    cout << totalDistance << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#endif // LOCAL

    cin >> n >> m;
    for(int i = n; --i > 0;) {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }
    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;
        mark[c - 1] = true;
    }

    bfs1();

    return 0;
}