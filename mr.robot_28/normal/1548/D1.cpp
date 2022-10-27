#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 4e4 + 100;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int> > x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i].X >> x[i].Y;
    }
    vector <vector <int> > mat(n, vector <int> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = (__gcd(abs(x[i].X - x[j].X), abs(x[i].Y  - x[j].Y)) / 2) % 2;
        }
    }
    ll a = 0, b = 0, c = 1LL * n * (n - 1) * (n - 2) / 6;
    for(int i = 0; i < n; i++)
    {
        int c1 = 0;
        for(int j = 0; j < n; j++)
        {
            if(j == i)
            {
                continue;
            }
            if(mat[i][j] == 1)
            {
                c1++;
            }
            else
            {
                b += (n - 2);
            }
        }
        a += c1 * (c1 - 1) / 2;
    }
    b /= 2;
   // cout << a << " " << b << " " << c << "\n";
    ll xx = 3 * c - (a + b);
    ll yy = (b - xx) / 3;
    cout << xx + yy;
    return 0;
}