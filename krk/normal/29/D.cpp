#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 305;

int n;
vector <int> neigh[Maxn];
set <int> cont[Maxn];
queue <int> Q;
vector <int> res;

void Init(int v, int p)
{
     if (v != 1) neigh[v].erase(find(neigh[v].begin(), neigh[v].end(), p));
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         Init(u, v);
         for (set <int>::iterator it = cont[u].begin(); it != cont[u].end(); it++)
             cont[v].insert(*it);
     }
     if (neigh[v].empty()) cont[v].insert(v);
}

void Search(int v)
{
     bool taken[Maxn] = {false};
     if (v == Q.front()) Q.pop();
     res.push_back(v);
     while (!Q.empty()) {
           int i, u;
           for (i = 0; i < neigh[v].size(); i++) if (!taken[i]) {
               u = neigh[v][i];
               if (cont[u].find(Q.front()) != cont[u].end()) break;
           }
           if (i < neigh[v].size()) {
                 Search(u);
                 taken[i] = true;
                 res.push_back(v);
           }
           else break;
     }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    int tmp;
    while (cin >> tmp) Q.push(tmp);
    Init(1, 0);
    Search(1);
    if (res.size() < 2 * n - 1) cout << "-1\n";
    else for (int i = 0; i < res.size(); i++)
             cout << res[i] << (i + 1 < res.size()? " ": "\n");
    return 0;
}