#include <iostream>
#include <vector>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
vector <bool> lucky[Maxn];
int lu[Maxn], un[Maxn];
ll res;

bool getLuck(int x)
{
     while (x) {
           if (x % 10 != 4 && x % 10 != 7) return false;
           x /= 10;
     }
     return true;
}

void Search1(int v, int p)
{
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         if (u == p) continue;
         Search1(u, v);
         if (lucky[v][i]) lu[v] += lu[u] + un[u] + 1;
         else { lu[v] += lu[u]; un[v] += un[u] + 1; }
     }
}

void Search2(int v, int p, int l, int u, bool good)
{
     if (good) lu[v] += l - lu[v] - un[v] - 1 + u;
     else {
          lu[v] += l - lu[v];
          un[v] += u - un[v] - 1;
     }
     res += ll(lu[v]) * ll(lu[v] - 1LL);
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         if (u == p) continue;
         Search2(u, v, lu[v], un[v] + 1, lucky[v][i]);
     }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        neigh[a].push_back(b); 
        neigh[b].push_back(a);
        bool luck = getLuck(c);
        lucky[a].push_back(luck); 
        lucky[b].push_back(luck);
    }
    Search1(1, 0);
    Search2(1, 0, lu[1], un[1] + 1, false);
    cout << res << endl;
    return 0;
}