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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    ::data.resize(n);


    vpii m1(n);
    vi m1_(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        m1[i] = {tmp, i};
        m1_[i] = tmp;
    }
    vpii m2(n);
    vi m2_(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        m2[i] = {tmp, i};
        m2_[i] = tmp;
    }


    sort(all(m1));
    sort(all(m2));

    int id1 = n-1;
    int id2 = n-1;


    int min1 = m1[n-1].ft;
    int min2 = m2[n-1].ft;

    vi as(n, 0);

    while(true)
    {
        int diff = 0;

        while(id1 >= 0)
        {
            if (m1[id1].ft >= min1)
            {
                diff = 1;
                min2 = min(min2, m2_[m1[id1].sd]);
                as[m1[id1].sd] = 1;
                --id1;
            }
            else break;
        }

        while(id2 >= 0)
        {
            if (m2[id2].ft >= min2)
            {
                diff = 1;
                min1 = min(min1, m1_[m2[id2].sd]);
                as[m2[id2].sd] = 1;
                --id2;
            }
            else break;
        }


        if (diff == 0)
            break;
    }


for (int i = 0; i < n; ++i)
{
    cout << as[i];
}
cendl;

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}