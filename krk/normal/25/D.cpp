#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1001;

vector <int> neigh[Maxn];
bool taken[Maxn];
int n, p[Maxn];
set <pair <int, int> > todel;

void DFS(int x, int p) 
{
     taken[x] = true;
     for (int i = 0; i < neigh[x].size(); i++) if (neigh[x][i] != p)
        if (taken[neigh[x][i]]) todel.insert(make_pair(min(neigh[x][i], x), max(neigh[x][i], x)));
        else DFS(neigh[x][i], x);
}

int main()
{
    int a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        neigh[a].push_back(b); neigh[b].push_back(a);
    }
    for (int i = 1; i < Maxn; i++)
       for (int j = 1; j <= n; j++)
          if (!taken[j]) {
                         p[i] = j;
                         DFS(j, -1);
                         break;
          }
    set <pair <int, int> >::iterator it;
    int i;
    cout << todel.size() << endl;
    for (i = 0, it = todel.begin(); i < todel.size(); i++, it++)
       cout << it->first << " " << it->second << " " << p[i+1] << " " << p[i+2] << endl;
    return 0;
}