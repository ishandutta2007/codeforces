#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

const int Maxn = 105;
const double supermin = 0.0;
const double supermax = 100000.0;

int n, k, inone;
int a[Maxn];
int q;
bool was[Maxn];
double mn = supermax, mx = supermin;
vector <int> tosort;

int main()
{
    cin >> n >> k; inone = n / k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    while (q--) {
          int sum = 0;
          for (int i = 0; i < inone; i++) {
              int quest; cin >> quest;
              sum += a[quest];
              was[quest] = true;
          }
          double curres = double(sum) / double(inone);
          mn = min(mn, curres); mx = max(mx, curres);
    }
    int taken = 0;
    for (int i = 1; i <= n; i++)
       taken += was[i];
    k -= taken / inone;
    if (k) {
           for (int i = 1; i <= n; i++)
              if (!was[i]) tosort.push_back(a[i]);
           sort(tosort.begin(), tosort.end());
           int candmin = 0;
           for (int i = 0; i < inone; i++)
              candmin += tosort[i];
           mn = min(mn, double(candmin) / double(inone));
           int candmax = 0;
           for (int i = 0; i < inone; i++)
              candmax += tosort[tosort.size() - 1 - i];
           mx = max(mx, double(candmax) / double(inone));
    }
    cout << fixed << setprecision(10) << mn << " " << mx << endl;
    return 0;
}