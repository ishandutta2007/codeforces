#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int Maxn = 1000005;

int n, m, k;
vector <int> neigh[Maxn];
bool taken[Maxn];
int comp;
priority_queue <int> Q;

int getSize(int v)
{
     if (taken[v]) return 0;
     int res = 1; taken[v] = true;
     for (int i = 0; i < neigh[v].size(); i++) res += getSize(neigh[v][i]);
     return res;
}

bool Enough(int x)
{
     priority_queue <int> curQ = Q;
     while (x--) {
           int a = -curQ.top(); curQ.pop();
           int b = -curQ.top(); curQ.pop();
           curQ.push(-min(a + b, k));
     }
     priority_queue <int> nxtQ;
     while (!curQ.empty()) { nxtQ.push(-curQ.top()); curQ.pop(); }
     while (!nxtQ.empty()) {
           int a = nxtQ.top(); nxtQ.pop();
           if (nxtQ.empty()) return true;
           if (!a) return false;
           int b = nxtQ.top(); nxtQ.pop();
           if (!b) return false;
           nxtQ.push(a + b - 2);
     }
     return true;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    while (m--) {
          int a, b; scanf("%d %d", &a, &b);
          neigh[a].push_back(b); neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!taken[i]) { Q.push(-min(getSize(i), k)); comp++; }
    int l = 0, r = comp - 1;
    while (l < r) {
          int mid = (l + r) / 2;
          if (Enough(mid)) r = mid;
          else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}