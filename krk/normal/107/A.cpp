#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, p;
int neigh[Maxn], d[Maxn];
bool to[Maxn], from[Maxn];
vector <int> res1, res2, res3;

void findRes(int p, int v, int cap)
{
     if (to[v] && !from[v]) {
               res1.push_back(p);
               res2.push_back(v);
               res3.push_back(cap);
     } else findRes(p, neigh[v], min(cap, d[v]));
}

int main()
{
    cin >> n >> p;
    while (p--) {
          int a, b, c;
          cin >> a >> b >> c;
          neigh[a] = b; d[a] = c;
          from[a] = to[b] = true;
    }
    for (int i = 1; i <= n; i++)
       if (!to[i] && from[i]) findRes(i, i, 1000000000);
    cout << res1.size() << endl;
    for (int i = 0; i < res1.size(); i++)
       cout << res1[i] << " " << res2[i] << " " << res3[i] << endl;
    return 0;
}