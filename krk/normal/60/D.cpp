#include <iostream>
#include <algorithm>
#include <vector>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 10000005;

int n;
int a[Maxn], where[Maxm];
vector <int> neigh[Maxn];
bool taken[Maxn];
int res;

int gcd(int x, int y)
{
    if (x == 0) return y;
    return gcd(y % x, x);
}

void Fill(int v)
{
     if (taken[v]) return;
     taken[v] = true;
     for (int i = 0; i < neigh[v].size(); i++)
        Fill(neigh[v][i]);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) where[a[i]] = i + 1;
    for (int i = 1; i <= Maxm; i++)
       for (int j = 1; j < i && 2 * i * j <= Maxm; j++)
          if ((i - j) % 2 && gcd(i, j) == 1) {
                 int a = -1, b = -1, c = -1;
                 ll needa = ll(i) * ll(i) - ll(j) * ll(j);
                 if (needa < ll(Maxm)) a = where[needa] - 1;
                 ll needb = 2LL * ll(i) * ll(j);
                 if (needb < ll(Maxm)) b = where[needb] - 1;
                 ll needc = ll(i) * ll(i) + ll(j) * ll(j);
                 if (needc < ll(Maxm)) c = where[needc] - 1;
                 if (a != -1 && b != -1) {
                       neigh[a].push_back(b);
                       neigh[b].push_back(a);
                 }
                 if (a != -1 && c != -1) {
                       neigh[a].push_back(c);
                       neigh[c].push_back(a);
                 }
                 if (b != -1 && c != -1) {
                       neigh[b].push_back(c);
                       neigh[c].push_back(b);
                 }
          }
    for (int i = 0; i < n; i++) if (!taken[i]) {
        res++;
        Fill(i);
    }
    cout << res << endl;
    return 0;
}