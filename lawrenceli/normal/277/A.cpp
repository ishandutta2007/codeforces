#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 105;

int n, m, c, num;
int comp[MAXN], numl[MAXN];
bool vis[MAXN];
vector<int> el[MAXN], le[MAXN], edges[MAXN];

void dfs(int node) {
    if (vis[node]) return;
    vis[node]=true;
    for (int i=0; i<el[node].size(); i++) comp[el[node][i]]=c;
    for (int i=0; i<edges[node].size(); i++) dfs(edges[node][i]);
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        for (int j=0; j<k; j++) {
            int a;
            cin >> a;
            el[i].push_back(a);
            le[a].push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<el[i].size(); j++) {
            int l = el[i][j];
            for (int k=0; k<le[l].size(); k++) {
                edges[i].push_back(le[l][k]);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            c++;
            dfs(i);
        }
    }
    num=c-1;
    for (int i=1; i<=m; i++) numl[comp[i]]++;
    bool b = true;
    for (int i=1; i<=c; i++)
        if (numl[i]>0) b = false;
    cout << num+b << endl;
}