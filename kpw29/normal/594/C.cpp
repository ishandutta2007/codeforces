#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 100100

pair <double, double > punkty[maxn];
double x1, x2, help, y2;
int n, k;
pair <double, int> srtx[maxn];
pair <double, int> srty[maxn];
bool jest[maxn];
multiset <double> X, Y;

long long Fmax(long double wart)
{
    ll ret = wart;
    if (ret < wart) return ++ret;
    return max(1LL, ret);
}
int main()
{
    scanf("%d%d", &n, &k);
    fill(jest + 1, jest + n + 1, false);
    if (k == n-1) OUT("1");
    long long all = INF;
    for (int i=1; i<=n; ++i) {
        scanf("%lf%lf%lf%lf", &x1, &help, &x2, &y2);
        punkty[i].e1 = (x2 + x1) * 0.5;
        punkty[i].e2 = (help + y2) * 0.5;
        srtx[i].e1 = punkty[i].e1;
        srtx[i].e2 = srty[i].e2 = i;
        srty[i].e1 = punkty[i].e2;
        X.insert(punkty[i].e1);
        Y.insert(punkty[i].e2);
    }
    sort(srtx+1, srtx + n + 1);
    sort(srty+1, srty + n + 1);
    
    for (int a=0; a<=10; ++a)
      for (int b=0; b<=10; ++b)
        for (int c=0; c<=10; ++c)
          for (int d=0; d<=10; ++d)
          {
              if (a + b + c + d > k) continue;
              vector <int> wyk;
              wyk.clear();
              for (int i=1; i<=a; ++i) 
              {
                  int elem = srtx[i].e2;
                  if (!jest[elem]) {
                      jest[elem] = 1;
                      wyk.pb(elem);
                      X.erase(X.find(punkty[elem].e1));
                      Y.erase(Y.find(punkty[elem].e2));
                    }
              }
              for (int i=1; i<=b; ++i)
              {
                  int elem = srtx[n - i + 1].e2;
                  if (!jest[elem]) {
                      jest[elem] = 1;
                  wyk.pb(elem);
                  X.erase(X.find(punkty[elem].e1));
                  Y.erase(Y.find(punkty[elem].e2));
              }
                    
              }
              for (int i=1; i<=c; ++i)
              {
                  int elem = srty[i].e2;
                   if (!jest[elem]) {
                      jest[elem] = 1;
                  wyk.pb(elem);
                  X.erase(X.find(punkty[elem].e1));
                  Y.erase(Y.find(punkty[elem].e2));
                }
              }
              for (int i=1; i<=d; ++i)
              {
                  int elem = srty[n - i + 1].e2;
                   if (!jest[elem]) {
                      jest[elem] = 1;
                  wyk.pb(elem);
                  X.erase(X.find(punkty[elem].e1));
                  Y.erase(Y.find(punkty[elem].e2));
                }
              }
              //puts("ELEMS");
              //for (int i=1; i<=n; ++i) printf("%d ", jest[i]);
              multiset <double>::iterator it = X.end();
              it--;
              long double MAXX = *it;
              it = X.begin();
              long double MINX = *it;
              it = Y.end(); --it;
              long double MAXY = *it;
              it = Y.begin();
              long double MINY = *it;
              long long result = Fmax(MAXX - MINX) * (Fmax(MAXY - MINY));
              all = min(all, result);
              for (ui i=0; i<wyk.size(); ++i)
              {
                  jest[wyk[i]] = false;
                  X.insert(punkty[wyk[i]].e1);
                  Y.insert(punkty[wyk[i]].e2);
              }
          }
    cout << all;
}