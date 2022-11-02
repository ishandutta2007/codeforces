#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

const int maxn = 100100;

int n, p[maxn];
bool vis[maxn];
vector<vector<int> > cyc;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> p[i];
    
    for (int i=1; i<=n; i++)
        if (p[i] == i) {
            cout << "YES\n";
            for (int j=1; j<=n; j++)
                if (j != i) cout << i << ' ' << j << '\n';
            return 0;
        }

    for (int i=1; i<=n; i++)
        if (!vis[i]) {
            int cur = i;
            cyc.push_back(vector<int>());
            while (!vis[cur]) {
                vis[cur] = 1;
                cyc.back().push_back(cur);
                cur = p[cur];
            }
        }
    
    bool b = 0;
    for (vector<int> v : cyc)
        if (v.size() == 2) b = 1;

    if (!b) {
        cout << "NO\n";
        return 0;
    }

    for (vector<int> v : cyc)
        if (v.size()%2 == 1) {
            cout << "NO\n";
            return 0;
        }

    for (int i=0; i<cyc.size(); i++)
        if (cyc[i].size() == 2) {
            cout << "YES\n";
            cout << cyc[i][0] << ' ' << cyc[i][1] << '\n';
            for (int j=0; j<cyc.size(); j++)
                if (i != j)
                    for (int k=0; k<cyc[j].size(); k++)
                        cout << cyc[i][k%2] << ' ' << cyc[j][k] << '\n';
            return 0;
        }
    
   assert(0);
}