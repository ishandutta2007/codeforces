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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


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


    multiset<int> a_;
    multiset<pair<int, pii>> sum_ab;
    multiset<pair<int, pii>> b_ab;

void Pull (int val)
{
    while(!sum_ab.empty())
    {
        auto it = sum_ab.begin();
        //log(it->ft);
        //log(it->sd);
        //log(k);
        if (-it->ft < val)
            break;

        b_ab.insert({it->sd.ft-it->sd.sd, it->sd});
        sum_ab.erase(it);
    }
}


/*

1
4 16
15 1
5 3
8 12
10 7

*/



int solve()
{
    cin >> n >> k;

    vi da(n);
    vi db(n);



    a_.clear();
    sum_ab.clear();
    b_ab.clear();

    for (int i = 0; i < n; ++i)
    {
        cin >> da[i] >> db[i];

        if (i == 0)
        {

        }
        else
        {

            a_.insert(da[i]);

            sum_ab.insert({-da[i]-db[i], {da[i], db[i]}});
        }
    }

    if (da[0] >= k)
    {
        cyes;
        return 0;
    }
    if (da[0] + db[0] < k)
    {
        cno;
        return 0;
    }
    k -= db[0];

    Pull(k);




    while(!b_ab.empty())
    {
        auto sit = a_.end();
        --sit;
        if (*sit >= k)
        {
            cyes;
            return 0;
        }

        //log(k);
        //log(*sit);


        auto it = b_ab.begin();
        //log(*it);
        k -= it->sd.sd;
        int ca = it->sd.ft;
        b_ab.erase(it);
        a_.erase(a_.find(ca));

        Pull(k);
    }




    cno;

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