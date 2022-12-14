#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;
    ans = 0;

    vvi data(n, vi(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> data[i][j];
        }
    }

    if (n == 2)
    {
        cout << (data[0][0] ^ data[0][1]) << endl;
        return 0;
    }

    int sti = n/2-2;
    int stj = n/2-2;


    if (stj%2 == 1)
    {
        ++sti;
        ++stj;
    }

    int ldsti = sti-2;
    int ldstj = stj+1;
    int ldstn = 1;

    int udsti = sti-2;
    int udstj = stj-2;
    int udstn = 2;

    int rdsti = sti+5;
    int rdstj = stj-1;
    int rdstn = 2;

    int ddsti = sti-2;
    int ddstj = stj+5;
    int ddstn = 2;




    ans ^= data[sti][stj];
    ans ^= data[sti+1][stj];

    ans ^= data[sti][stj+3];
    ans ^= data[sti+1][stj+3];

    ans ^= data[sti+3][stj+1];
    ans ^= data[sti+3][stj+2];

    for (int i = 0; i < n-4; ++i)
    {
        if (i%4 == 0)
        {
            for (int j = 0; j < 4*ldstn; j += 4)
            {
                ans ^= data[ldsti][ldstj+j];
                ans ^= data[ldsti][ldstj+j+1];
            }

            ldsti -= 2;
            ldstj -= 2;
            ldstn++;
        }
        else if (i%4 == 1)
        {
            for (int j = 0; j < 4*udstn; j += 4)
            {
                ans ^= data[udsti+j][udstj];
                ans ^= data[udsti+j+1][udstj];
            }

            udsti -= 2;
            udstj -= 2;
            udstn++;
        }
        else if (i%4 == 2)
        {
            for (int j = 0; j < 4*ddstn; j += 4)
            {
                ans ^= data[ddsti+j][ddstj];
                ans ^= data[ddsti+j+1][ddstj];
            }

            ddsti -= 2;
            ddstj += 2;
            ddstn++;
        }
        else
        {
            for (int j = 0; j < 4*rdstn; j += 4)
            {
                ans ^= data[rdsti][rdstj+j];
                ans ^= data[rdsti][rdstj+j+1];

                //log (rdsti);
                //log (rdstj+j);
                //log (data[rdsti][rdstj+j]);
                //log (rdsti);
                //log (rdstj+j+1);
                //log (data[rdsti][rdstj+j+1]);
            }

            rdsti += 2;
            rdstj -= 2;
            rdstn++;
        }
    }


    cout << ans << endl;

    return 0;
}

/*

2
6
0 2 0 0 0 0
6 0 0 0 0 0
0 4 0 0 0 2
4 0 0 0 2 0
0 0 0 0 0 2
0 0 0 0 0 0


2
8
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0
0 0 0 0 1 0 1 0
0 0 0 0 0 1 0 0

12
0 4 0 0 0 8 0 8 0 0 0 0
4 0 0 0 0 0 8 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 16
0 0 0 0 0 0 0 0 0 0 16 0
32 0 0 0 0 2 0 0 0 0 0 16
0 32 0 0 2 0 2 0 0 0 0 0
32 0 0 0 0 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0

*/


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}