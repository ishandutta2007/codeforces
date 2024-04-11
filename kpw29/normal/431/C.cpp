#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n, k, d;
ll tab[1010][2];
int main()
{
    cin >> n >> k >> d;
    tab[0][0] = 1;
    for (int i=1; i<=n; ++i)
    {               //weight
      for (int j=1; j<=k; ++j)
    {
        int ff = 0;
        if (j >= d) ff = 1;
        if (i >= j)
        {
            tab[i][ff] += tab[i-j][0];
            tab[i][1] += tab[i-j][1];
        }
    }
        tab[i][1] %= mod;
        tab[i][0] %= mod;
    }
    //for (int i=1; i<=n; ++i) cout << tab[i][0] << ' ' << tab[i][1] << endl;
    cout << tab[n][1] % mod;
}