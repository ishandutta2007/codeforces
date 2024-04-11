#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 200000;
const ld small = 0.000000001;

int n, xi[Maxn];
ld ans, m;

void findBigger(const ld &d, int l, int r, int &res)
{
     if (l > r) return;
     int mid = (l + r) / 2;
     if (xi[mid] > d) {
                 res = mid;
                 findBigger(d, l, mid-1, res);
     } else findBigger(d, mid+1, r, res);
}

void findSmaller(const ld &d, int l, int r, int &res)
{
     if (l > r) return;
     int mid = (l + r) / 2;
     if (xi[mid] < d) {
                 res = mid;
                 findSmaller(d, mid+1, r, res);
     } else findSmaller(d, l, mid-1, res);
}

bool Enough(const ld &d)
{
     int l = -1, r = -1;
     findBigger(xi[0]+2*(d+small), 0, n-1, l);
     findSmaller(xi[n-1]-2*(d+small), 0, n-1, r);
     if (l == -1 || r == -1 || l > r || xi[r] - xi[l] <= 2*(d+small)) {
           if (l != -1 && r != -1) m = (xi[l] + xi[r]) / 2.0;
           else m = xi[0]+(d+small);
           return true;
     }
     return false;
}

void searchAns(ld l, ld r)
{
     if (l + small > r) return;
     ld mid = (l + r) / 2;
     if (Enough(mid)) {
                      ans = mid;
                      searchAns(l, mid-small);
     } else searchAns(mid+small, r);
}

int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++) cin >> xi[i];
    sort(xi, xi+n);
    searchAns(0, (xi[n-1] - xi[0]) / 6.0);
    cout << fixed << setprecision(6) << ans << endl;
    cout << fixed << setprecision(6) << ld(xi[0]) + (ans+small) << " ";
    cout << fixed << setprecision(6) << m << " ";
    cout << fixed << setprecision(6) << ld(xi[n-1]) - (ans+small) << endl;
    return 0;
}