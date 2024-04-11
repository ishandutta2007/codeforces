#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int Maxn = 105;

int n, k;
int a[Maxn];
int tims[Maxn];
int res;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (true) {
          int ind = 1;
          for (int i = 1; i <= n; i++)
             if (a[i] > a[ind]) ind = i;
          if (!a[ind]) break;
          if (a[ind] < k || tims[ind] == 3) {
                     res += a[ind]; a[ind] = 0;
          } else {
                 a[ind] -= k; tims[ind]++;
          }
    }
    cout << res << endl;
    return 0;
}