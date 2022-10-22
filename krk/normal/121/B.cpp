#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, k;
char s[Maxn];
bool was[Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int pnt = 0;
    while (k) {
          while (pnt + 1 < n && (s[pnt] != '4' || s[pnt + 1] != '7')) pnt++;
          if (pnt + 1 == n) break;
          if (pnt % 2 == 0) s[++pnt] = '4';
          else s[pnt--] = '7';
          if (k > 1 && was[pnt]) { k %= 2; k = 1 - k; }
          else k--;
          was[pnt] = true;
    }
    for (int i = 0; i < n; i++) printf("%c", s[i]);
    printf("\n");
    return 0;
}