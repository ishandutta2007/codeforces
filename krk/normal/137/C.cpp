#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii D[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &D[i].first, &D[i].second);
    sort(D, D + n);
    int l = D[0].first, r = 0;
    int i;
    for (i = 0; i < n && D[i].first == l; i++) r = max(r, D[i].second);
    while (i < n) {
          int nxtl = D[i].first, nxtr = r;
          for (; i < n && D[i].first == nxtl; i++) {
                if (D[i].second < r) res++;
                nxtr = max(nxtr, D[i].second);
          }
          l = nxtl, r = nxtr;
    }
    printf("%d\n", res);
    return 0;
}