#include <iostream>
#include <map>
#define N 300

using namespace std;

map<int, int> m;

template<typename _EuclideanRingElement>
_EuclideanRingElement
__gcd(_EuclideanRingElement __m, _EuclideanRingElement __n)
{
  while (__n != 0)
{
  _EuclideanRingElement __t = __m % __n;
  __m = __n;
  __n = __t;
}
  return __m;
}

void inline mini(int &a, int b)
{
    if (a > b || !a)
        a = b;
}

int l[N], c[N];

int main()
{
    int ans = 0, n, cd, cc;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int s = 0; s < n; ++s)
        mini(m[l[s]], c[s]);
    auto t = m.end();
    do
    {
        --t;
        cd = t->first;
        cc = t->second;
        for (int i = 0; i < n; ++i)
            mini(m[__gcd(cd, l[i])], cc + c[i]);
    }
    while (t = m.lower_bound(cd), t != m.begin());
    if (m[1] == 0)
    {
        cout << -1;
        return 0;
    }
    cout << m[1];
    return 0;
}