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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ft first
#define sd second
#define cendl cout << endl


template<int m>
struct modint
    {
    long long x;

    modint() :
        x(0) {}

    modint(long long arg)
        {
        arg%= m;
        if (arg < 0) x = arg + m;
        else x = arg;
        }

    modint& operator+= (const modint& other)
        {
        x+= other.x;
        if (x >= m) x-= m;

        return *this;
        }

    modint& operator*= (const modint& other)
        {
        x = (x * 1ll * other.x) % m;
        return *this;
        }

    modint& operator-= (const modint& other)
        {
        x+= m - other.x;
        if (x >= m) x-= m;

        return *this;
        }

    modint operator+ (const modint& other) const
        {
        modint tmp = *this;
        tmp+= other;
        return tmp;
        }

    modint operator- (const modint& other) const
        {
        modint tmp = *this;
        tmp-= other;
        return tmp;
        }

    modint operator* (const modint& other) const
        {
        modint tmp = *this;
        tmp*= other;
        return tmp;
        }

    explicit operator int () const
        {
        return x;
        }

    modint& operator++ ()
        {
        ++x;
        if (x == m) x = 0;

        return *this;
        }

    modint& operator-- ()
        {
        if (x == 0) x = m-1;
        else --x;

        return *this;
        }

    modint operator++ (int)
        {
        modint tmp = *this;
        ++*this;

        return tmp;
        }

    modint operator-- (int)
        {
        modint tmp = *this;
        --*this;

        return tmp;
        }

    bool operator== (const modint& other) const
        {
        return x == other.x;
        }

    bool operator!= (const modint& other) const
        {
        return x != other.x;
        }

    template<class T>
    modint operator^ (T arg) const
        {
        if (arg == 0) return 1;
        if (arg == 1) return x;

        auto t = *this ^ (arg >> 1);
        t*= t;

        if (arg & 1) t*= *this;

        return t;
        }

    modint inv() const // works clearly only when 'm' is prime number
        {
        return *this ^ (m-2);
        }
};

const int MOD = 1000000007;
typedef modint<MOD> mint;

vector<vector<mint>> data(65, vector<mint>(6));

vector<pair<ll, pll>> picked;

long long a, b, k, n, m, tmp, ans = 0;

map<ll, int> pickedids;


vvi possible(6, vi(4));


ll n_2[64] = {};


bool is_free(ll cur)
{

    //cout << "is_fre" << cur<< endl;

    ll l_ = cur;
    ll r_ = cur;

    while(l_ < n_2[n])
    {
        l_*=2;
        r_*=2;
        r_++;
    }

    l_/=2;
    r_/=2;

    if (cur == 4)
    {
        //cout << l_ << " " << r_ <<"!" << endl;
    }
    int l = -1;
    int r = picked.size();
    while(r-l > 1)
    {
        int mid = (l+r)/2;
        if (picked[mid].ft >= l_)
            r = mid;
        else
            l = mid;
    }

    if (cur == 4)
    {
        //cout << l << " " << r <<"!!" << endl;
    }

    if (l == -1)
        {


            l++;
        }

        for (int i = l; i < picked.size(); ++i)
        {
            if (picked[i].ft > r_)
                break;

            if (picked[i].ft >= l_)
            {
                if (picked[i].sd.ft >= cur)
                    return false;
            }
        }



    return true;

}

vector<mint> get_ans(ll cur, int layers_left)
{
    if (is_free(cur))
        {
            /*cout << "getans" << cur<< " " << layers_left << endl;

        for (int i = 0; i < 6; ++i)
        {
            cout << ::data[layers_left][i].x << "! " ;
        }


    cendl;*/

            return ::data[layers_left];
        }

    if (layers_left == 1)
    {
        vector<mint> ret (6, mint(0));
        for (int i = 0; i < 6; ++i)
        {
            if (i == pickedids[cur])
                ret[i] = mint(1);
        }

        /*cout << "getans" << cur<< " " << layers_left << endl;

        for (int i = 0; i < 6; ++i)
        {
            cout << ::data[layers_left][i].x << "! " ;
        }


    cendl;*/

        return ret;
    }

    vector<mint> ret (6, mint(0));

    vector<mint> a1 = get_ans(2*cur, layers_left-1);
    vector<mint> a2 = get_ans(2*cur + 1, layers_left-1);

    for (int i = 0; i < 6; ++i)
    {
        mint ansa1(0);
        for (int j = 0; j < 4; ++j)
        {
            ansa1 += a1[possible[i][j]];
        }
        mint ansa2(0);
        for (int j = 0; j < 4; ++j)
        {
            ansa2 += a2[possible[i][j]];
        }

        ret[i] = ansa1 * ansa2;
    }

    //cout << "getans" << cur<< " " << layers_left << endl;
    if (pickedids.count(cur))
    {
        for (int i = 0; i < 6; ++i)
        {
            if (i != pickedids[cur])
                ret[i] = mint(0);

            //cout << ret[i].x << " " ;
        }
    }
    //for (int i = 0; i < 6; ++i)
        //{
            //cout << ret[i].x << " " ;
        //}


   // cendl;

    return ret;
}




int main()
{
    FAST;
//{
    possible[0][0] = 2;
    possible[0][1] = 3;
    possible[0][2] = 4;
    possible[0][3] = 5;

    possible[1][0] = 2;
    possible[1][1] = 3;
    possible[1][2] = 4;
    possible[1][3] = 5;

    possible[2][0] = 0;
    possible[2][1] = 1;
    possible[2][2] = 4;
    possible[2][3] = 5;

    possible[3][0] = 0;
    possible[3][1] = 1;
    possible[3][2] = 4;
    possible[3][3] = 5;

    possible[4][0] = 0;
    possible[4][1] = 1;
    possible[4][2] = 2;
    possible[4][3] = 3;

    possible[5][0] = 0;
    possible[5][1] = 1;
    possible[5][2] = 2;
    possible[5][3] = 3;
//}
    mint x(6);

    mint _3(3);
    mint _6(6);
    mint _8(8);

    mint inv3 = _3.inv();
    mint inv6 = _6.inv();

    for (int j = 0; j < 6; ++j)
    {
        ::data[0][j] = x*inv6;
    }



    //cout << "h" << endl;

    for (int i = 1; i < 63; ++i)
    {
    //cout << "h" << i << endl;
        for (int j = 0; j < 6; ++j)
        {
            ::data[i][j] = x*inv6;
        }


        x*=x;
        x*=_8;

        x*=inv3;
    }

    //cout << "h" << endl;

    n_2[0] = 1;
    for (int i = 1; i < 62; ++i)
    {
        n_2[i] = n_2[i-1]*2;
    }


    cin >> n >> m;
    picked.resize(m);
    for (int i = 0; i < m; ++i)
    {
        ll tm;
        string info;
        cin >> tm >> info;
        int id = 0;
        if (info[0] == 'y')
            id = 1;
        if (info[0] == 'g')
            id = 2;
        if (info[0] == 'b')
            id = 3;
        if (info[0] == 'r')
            id = 4;
        if (info[0] == 'o')
            id = 5;

        ll lower_val = tm;
        while(lower_val < n_2[n])
            lower_val*= 2;

        lower_val /= 2;

        picked[i] = {lower_val, {tm, id}};
        pickedids[tm] = id;
    }
    sort(all(picked));


    vector<mint> ass = get_ans(1, n);

    mint asss(0);

    for (int i = 0; i < 6; ++i)
    {
        asss+=ass[i];
    }


    cout << asss.x << endl;

    return 0;
}