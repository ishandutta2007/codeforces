#include <iostream>
#include <vector>
using namespace std;

const int Maxn = 101;
const int Inf = 1000001;

int n, m, num[Maxn];
vector <int> neigh[Maxn], g[Maxn], l[Maxn];
bool del[Maxn], taken[Maxn], stop;

int gcd(int x, int y)
{
    while (x != 0) {
          int tmp = y % x;
          y = x;
          x = tmp;
    }
    return y;
}

void Search(int v)
{
     int i;
     for (i = 0; i < neigh[v].size() && !stop; i++)
        if (num[v] % g[v][i] || l[v][i] % num[v]) stop = true;
        else {
             int newnum = l[v][i] / num[v] * g[v][i];
             if (gcd(newnum, num[v]) != g[v][i] || 
                 num[neigh[v][i]] && num[neigh[v][i]] != newnum) stop = true;
             else if (num[neigh[v][i]]) continue;
             else {
                  num[neigh[v][i]] = newnum;
                  Search(neigh[v][i]);
             }
        }
}

void DFS(int v)
{
     if (del[v]) return;
     del[v] = true;
     for (int i = 0; i < neigh[v].size(); i++)
        DFS(neigh[v][i]);
}

void SwitchBack(int v)
{
     if (num[v] == 0) return;
     num[v] = 0;
     for (int i = 0; i < neigh[v].size(); i++)
        SwitchBack(neigh[v][i]);
}

int main()
{
    int a, b, c, d;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        neigh[a].push_back(b); g[a].push_back(c); l[a].push_back(d);
        neigh[b].push_back(a); g[b].push_back(c); l[b].push_back(d);
    }
    int i;
    for (i = 1; i <= n; i++) if (!del[i]) {
        int j;
        for (j = 1; j < Inf; j++) {
            stop = false;
            num[i] = j;
            Search(i);
            if (!stop) break;
            SwitchBack(i);
        }
        if (j == Inf) break;
        DFS(i);
    }
    if (i <= n) cout << "NO\n";
    else {
         cout << "YES\n";
         for (int i = 1; i <= n; i++) {
             if (i > 1) cout << " ";
             cout << num[i];
         }
         cout << endl;
    }
    return 0;
}