#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn], w[Maxn];
double expect[Maxn];
int tim[Maxn], cnt[Maxn];

void Search(int v, int p)
{
     cnt[v]++;
     vector <pair <double, int> > tmp;
     for (int i = 0; i < neigh[v].size(); i++) {
         int u = neigh[v][i];
         if (u == p) continue;
         Search(u, v);
         expect[u] += w[v][i];
         tim[u] += 2 * w[v][i];
         tmp.push_back(make_pair(double(tim[u]) / double(cnt[u]), u));
         tim[v] += tim[u];
         cnt[v] += cnt[u];
     }
     sort(tmp.begin(), tmp.end());
     double T = 0;
     for (int i = 0; i < tmp.size(); i++) {
         expect[v] += double(cnt[tmp[i].second]) / double(cnt[v]) * (T + expect[tmp[i].second]);
         T += tim[tmp[i].second];
     }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(b); w[a].push_back(c);
        neigh[b].push_back(a); w[b].push_back(c);
    }
    Search(1, -1);
    cout << fixed << setprecision(10) << expect[1] * (double(n) / double(n - 1)) + 1e-12 << endl;
    return 0;
}