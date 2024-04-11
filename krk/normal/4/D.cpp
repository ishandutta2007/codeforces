#include <iostream>
using namespace std;

const int Maxn = 5005;

int n, w[Maxn], h[Maxn];
bool was[Maxn];
int best[Maxn], p[Maxn];

void findBest(int v)
{
     if (was[v]) return;
     for (int i = 0; i <= n; i++) 
         if (w[v] < w[i] && h[v] < h[i]) {
                  findBest(i);
                  if (best[i] + 1 > best[v]) {
                              best[v] = best[i] + 1;
                              p[v] = i;
                  }
         }
     was[v] = true;
}

void Print(int v)
{
     cout << v;
     if (p[v]) {
               cout << " ";
               Print(p[v]);
     } else cout << endl;
}

int main()
{
    cin >> n >> w[0] >> h[0];
    for (int i = 1; i <= n; i++) 
        cin >> w[i] >> h[i];
    findBest(0);
    cout << best[0] << endl;
    if (best[0]) Print(p[0]);
    return 0;
}