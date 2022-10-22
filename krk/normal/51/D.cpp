#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxn = 100000;
ld small = 0.00000001;

int n, a[Maxn];

int main()
{
    int i, tmp1, tmp2;
    long double q;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    if (n == 1) cout << "0\n";
    else {
         if (a[0] == 0) q = 0;
         else q = (ld)a[1] / a[0];
         for (i = 1; i < n; i++)
            if (fabs(a[i] - a[i-1] * q) > small) break;
         if (i == n) cout << "0\n";
         else {
              if (n == 2) {
                    cout << "1\n"; return 0;
              }
              bool mist = false;
              if (a[0] == 0) q = 0;
              else q = (ld)a[1] / a[0];
              for (i = 1; i < n; i++)
                 if (fabs(a[i] - a[i-1] * q) > small)
                    if (mist) break;
                    else {
                         mist = true;
                         tmp1 = i; tmp2 = a[i]; a[i] = a[i-1];
                    }
              if (mist) a[tmp1] = tmp2;
              if (i == n) cout << "1\n";
              else {
                   if (a[1] == 0) q = 0;
                   else q = (ld)a[2] / a[1];
                   for (i = 2; i < n; i++)
                      if (fabs(a[i] - a[i-1] * q) > small) break;
                   if (i == n) cout << "1\n";
                   else {
                        a[1] = a[0];
                        if (a[1] == 0) q = 0;
                        else q = (ld)a[2] / a[1];
                        for (i = 2; i < n; i++)
                           if (fabs(a[i] - a[i-1] * q) > small) break;
                        if (i == n) cout << "1\n";
                        else cout << "2\n";
                   }
              }
         }
    }
    return 0;
}