#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m;
vector <int> neigh[Maxn];
bool taken[Maxn];
int freq[Maxn];
int siz[Maxn], has[Maxn], len;
int best[Maxn];

int getSize(int v)
{
    if (taken[v]) return 0;
    int res = 1; taken[v] = true;
    for (int i = 0; i < neigh[v].size(); i++) res += getSize(neigh[v][i]);
    return res;
}

bool Lucky(int x)
{
     while (x) {
           if (x % 10 != 4 && x % 10 != 7) return false;
           x /= 10;
     }
     return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    while (m--) {
          int a, b; scanf("%d %d", &a, &b);
          neigh[a].push_back(b); neigh[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) if (!taken[i]) freq[getSize(i)]++;
    for (int i = 1; i <= n; i++)
        while (freq[i]) {
              int j = 1;
              while ((1 << j + 1) - 1 <= freq[i]) j++;
              siz[len] = i; has[len] = j; len++;
              freq[i] -= (1 << j) - 1;
        }
    fill(best, best + n + 1, Maxn);
    best[0] = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < has[i]; j++) {
            int d = siz[i] * (1 << j);
            for (int l = n; l - d >= 0; l--)
                best[l] = min(best[l], best[l - d] + (1 << j));
        }
    int res = Maxn;
    for (int i = 1; i <= n; i++) if (Lucky(i)) res = min(res, best[i]);
    cout << (res < Maxn? res - 1: -1) << endl;
    return 0;
}