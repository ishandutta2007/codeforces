#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define sz(s) (int)s.size()
map <vector <int>, int> mp;
bool funct(int a, int b, int c, int d, int e, int f)
{
    if(mp.count({a, b, c, d, e, f}))
    {
        return mp[{a, b, c, d, e, f}];
    }
    cout << "? " << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    int t;
    cin >> t;
    return mp[{a, b, c, d, e, f}] = t;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int n0 = n;
    int m0 = m;
    int fx = n, fy = m;
    for(int i = 2; i <= n0; i++)
    {
        while(n0 % i == 0)
        {
            bool fl = 1;
            int j = 1;
            int k = (fx / i);
            for(j = 1; j * 2 <= i; j *= 2)
            {
                if(!funct(j * k, m, 1, 1, 1 + j * k, 1))
                {
                    fl = 0;
                    break;
                }
            }
            if(fl && (j == i || funct((fx - j * k), m, 1, 1, 1 + j * k, 1)))
            {
                fx /= i;
            }
            n0 /= i;
        }
    }
    for(int i = 2; i <= m0; i++)
    {
        while(m0 % i == 0)
        {
            bool fl = 1;
            int j = 1;
            int k = (fy / i);
            for(; j * 2 <= i; j *= 2)
            {
                if(!funct(n, j * k, 1, 1, 1, j * k + 1))
                {
                    fl = 0;
                    break;
                }
            }
            if(fl && (j * k == fy || funct(n, (fy - j * k), 1, 1, 1, j * k + 1)))
            {
                fy /= i;
            }
            m0 /= i;
        }
    }
    int ansp1 = 0, ansp2 = 0;
    for(int i = 1; i <= (n / fx); i++)
    {
        if((n / fx) % i == 0)
        {
            ansp1++;
        }
    }
    for(int i = 1; i <= (m / fy); i++)
    {
        if((m / fy) % i == 0)
        {
            ansp2++;
        }
    }
 //   cout << fx << " " << fy <<"\n";
  //  cout << fx << " " << fy << "\n";
    cout << "! " << ansp1 * ansp2;
    return 0;
}