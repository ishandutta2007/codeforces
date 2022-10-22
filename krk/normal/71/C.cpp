#include <cstdio>
using namespace std;

const int Maxn = 100000;

int n, moods[Maxn];

bool Polyg(int x)
{
     if (n / x < 3) return false;
     bool canGet[Maxn];
     for (int i = 0; i < n; i++) {
         if (i < x) canGet[i] = moods[i];
         else canGet[i] = canGet[i-x] && moods[i];
         if (canGet[i] && i >= n - x) return true;
     }
     return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
       scanf("%d", &moods[i]);
    int i;
    for (i = 1; i * i <= n; i++)
       if (n % i == 0)
          if (Polyg(i) || Polyg(n / i)) break;
    if (i * i > n) printf("NO\n");
    else printf("YES\n");
    return 0;
}