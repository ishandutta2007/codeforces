#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, g, n;
set <int> divs;
vector <int> V;

int gcd(int x, int y)
{
    if (x == 0) return y;
    else return gcd(y % x, x);
}

int main()
{
    int l, h;
    cin >> a >> b >> n;
    g = gcd(a, b);
    for (int i = 1; i <= g / i; i++)
       if (g % i == 0) {
             divs.insert(i);
             divs.insert(g/i);
       }
    for (set <int>::iterator it = divs.begin(); it != divs.end(); it++)
       V.push_back(*it);
    while (n--) {
          cin >> l >> h;
          int ind = upper_bound(V.begin(), V.end(), h) - V.begin();
          if (ind < V.size() && V[ind] >= l && V[ind] <= h) cout << V[ind] << endl;
          else {
               ind--;
               if (V[ind] >= l) cout << V[ind] << endl;
               else cout << "-1\n";
          }
    }
    return 0;
}