#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int maxn = 200100;
const ld eps = 1e-15;

int n, w, a[maxn];

int main() {
   cin >> n >> w;
   for (int i=0; i<2*n; i++) cin >> a[i];
   sort(a, a+2*n);


   ld mi = min(ld(a[0]), ld(a[n])/2);
   mi = min(mi, ld(w)/(3*n));
   cout << fixed << setprecision(10) << 3*n*mi << '\n';
}