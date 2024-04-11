#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1000000005;

vector <int> V;
ll pl, pr, vl, vr, k;
ll good;

void Gen(int lft, int num)
{
     if (!lft) V.push_back(num);
     else {
          Gen(lft - 1, 10 * num + 4);
          Gen(lft - 1, 10 * num + 7);
     }
}

ll getP(ll l, ll r)
{
    ll curl = max(l, pl), curr = min(r, pr);
    ll res = curr - curl + 1LL;
    if (res <= 0) return 0;
    return res;
}

ll getV(ll l, ll r)
{
    ll curl = max(l, vl), curr = min(r, vr);
    ll res = curr - curl + 1LL;
    if (res <= 0) return 0;
    return res;
}

int main()
{
    V.push_back(0);
    for (int i = 1; i < 10; i++)
       Gen(i, 0);
    V.push_back(Inf);
    cin >> pl >> pr >> vl >> vr >> k;
    for (int i = 1; i + k < V.size(); i++)
       if (k == 1) 
          good += getP(V[i - 1] + 1, V[i]) * getV(V[i + k - 1], V[i + k] - 1) +
                  getP(V[i + k - 1], V[i + k] - 1) * getV(V[i - 1] + 1, V[i]) -
                  getP(V[i], V[i]) * getV(V[i], V[i]);
       else good += getP(V[i - 1] + 1, V[i]) * getV(V[i + k - 1], V[i + k] - 1) +
                    getP(V[i + k - 1], V[i + k] - 1) * getV(V[i - 1] + 1, V[i]);
    cout << fixed << setprecision(20) << ld(good) / ld(ll(pr - pl + 1) * ll(vr - vl + 1)) << endl;
    return 0;
}