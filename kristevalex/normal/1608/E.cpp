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

const int INF = 1200000000;


/*

18
-373805147 -677173064 2
-555970020 -459859120 2
-151334405 -317468296 2
817749597 216460895 3
-599675516 -627128771 1
-376199103 -970471142 2
290651811 430579757 3
746448667 845576150 3
-10525220 -854747230 1
-705946666 -523852232 2
258446091 731072185 3
237368937 266312824 3
-40703862 -780344394 1
697312547 98116917 3
-989386499 -374747329 1
-238531451 -76277962 1
-72228178 -61196380 2
-229673321 -545344982 1

15
-7  -8   2
-8  -5   2
-4  -3   2
 5   2   3
 4   5   3
-1  -10  1
-9  -6   2
 2   4   3
 1   3   3
-2  -9   1
 3   1   3
-10 -4   1
-6  -2   1
-3  -1   2
-5  -7   1

6
5 5 3
6 6 3
1 4 1
4 1 1
3 2 2
2 3 2


*/


vector<vector<pii>> hor(3);
vector<vector<pii>> ver(3);

long long a, b, k, n, m, tmp, ans = 0;


inline bool Check(int sz, int restId, int xmin, int xmax, int ymin, int ymax)
{
    //cout << "rest: " << restId << ", [" << xmin << " " << xmax << "] : [" << ymin << " " << ymax << "]" << endl;




    int id1 = (restId+1)%3;
    int id2 = (restId+2)%3;

    int left1 = sz;
    int ymn = -INF;
    for (int i = 0; i < n; ++i)
    {

        if (hor[id1][i].sd >= xmin && hor[id1][i].sd <= xmax && hor[id1][i].ft >= ymin && hor[id1][i].ft <= ymax)
        {


            left1--;
            ymn = hor[id1][i].ft+1;
            if (left1 == 0)
                break;
        }
    }
    if (left1 == 0)
    {
        int left = sz;
        for (int i = 0; i < n; ++i)
        {
            if (hor[id2][i].sd >= xmin && hor[id2][i].sd <= xmax && hor[id2][i].ft >= ymin && hor[id2][i].ft <= ymax && hor[id2][i].ft >= ymn)
            {
                left--;
                if (left == 0)
                {
                    //cout << 1 << endl;
                    return true;
                }
            }
        }
    }


    left1 = sz;
    int ymx = INF;
    for (int i = n-1; i >= 0; --i)
    {
        if (hor[id1][i].sd >= xmin && hor[id1][i].sd <= xmax && hor[id1][i].ft >= ymin && hor[id1][i].ft <= ymax)
        {
            left1--;
            ymx = hor[id1][i].ft-1;
            if (left1 == 0)
                break;
        }
    }
    if (left1 == 0)
    {
        int left = sz;
        for (int i = 0; i < n; ++i)
        {
            if (hor[id2][i].sd >= xmin && hor[id2][i].sd <= xmax && hor[id2][i].ft >= ymin && hor[id2][i].ft <= ymax && hor[id2][i].ft <= ymx)
            {
                left--;
                if (left == 0)
                {
                    //cout << 2 << endl;
                    return true;
                }
            }
        }
    }


    left1 = sz;
    int xmn = -INF;
    //cout << "hi!!!!!\n";
    for (int i = 0; i < n; ++i)
    {
        if (ver[id1][i].ft >= xmin && ver[id1][i].ft <= xmax && ver[id1][i].sd >= ymin && ver[id1][i].sd <= ymax)
        {
            left1--;
            xmn = ver[id1][i].ft+1;
            if (left1 == 0)
                break;
        }
    }
    if (left1 == 0)
    {
        int left = sz;
        for (int i = 0; i < n; ++i)
        {
            if (hor[id2][i].sd >= xmin && hor[id2][i].sd <= xmax && hor[id2][i].ft >= ymin && hor[id2][i].ft <= ymax && hor[id2][i].sd >= xmn)
            {
                left--;
                if (left == 0)
                {
                    //cout << 3 << endl;
                    return true;
                }
            }
        }
    }


    left1 = sz;
    int xmx = INF;
    for (int i = n-1; i >= 0; --i)
    {
        if (ver[id1][i].ft >= xmin && ver[id1][i].ft <= xmax && ver[id1][i].sd >= ymin && ver[id1][i].sd <= ymax)
        {
            left1--;
            xmx = ver[id1][i].ft-1;
            if (left1 == 0)
                break;
        }
    }
    if (left1 == 0)
    {
        /*if (ymax == 3)
    {
        cout << "hi " << 4 << endl;
    }*/
        int left = sz;
        for (int i = 0; i < n; ++i)
        {
            if (hor[id2][i].sd >= xmin && hor[id2][i].sd <= xmax && hor[id2][i].ft >= ymin && hor[id2][i].ft <= ymax && hor[id2][i].sd <= xmx)
            {
                left--;
                if (left == 0)
                {
                    //cout << "xmx: " << xmx << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

inline bool check (int sz)
{

    //cout << "sz" << sz-1 << endl;
    for (int restId = 0; restId < 3; ++restId)
    {
        auto lt = hor[restId][sz-1];
        if (Check(sz, restId, -INF, INF, lt.ft+1, INF))
        {
            //cout << "ck1 rest id: " << restId << endl;
            return true;
        }
        lt = hor[restId][n-sz];
        if (Check(sz, restId, -INF, INF, -INF, lt.ft-1))
        {
             //cout << "ck2 rest id: " << restId << endl;
             //cout << "ymax: " << lt.ft-1 << endl;
             return true;
        }
        lt = ver[restId][n-sz];
        if (Check(sz, restId, -INF, lt.ft-1, -INF, INF))
        {
            //cout << "ck3 rest id: " << restId << endl;
            return true;
        }
        lt = ver[restId][sz-1];
        if (Check(sz, restId, lt.ft+1, INF, -INF, INF))
        {
            //cout << "ck4 rest id: " << restId << endl;
            return true;
        }
    }
    return false;
}

int solve()
{
    cin >> n;
    n /= 3;


    for (int i = 0; i < 3*n; ++i)
    {
        int x, y, tm;
        cin >> x >> y >> tm;

        --tm;
        ::ver[tm].pb({x, y});
        ::hor[tm].pb({y, x});
    }

    for (int i = 0; i < 3; ++i)
    {
        sort(all(::ver[i]));
        sort(all(::hor[i]));
    }


    int l = 0;
    int r = n+1;
    while(r-l > 1)
    {
        int mid = (l + r)/2;
        if (check(mid))
            l=mid;
        else
            r=mid;
    }


    cout << 3*l << endl;

    //cout <<endl << check(n) << endl;;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}