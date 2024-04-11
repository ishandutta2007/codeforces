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


struct tmm
{
    ull mask_pos;
    ull mask_fixed;
    int num;

    bool operator< (tmm other) const
    {
        if (mask_pos != other.mask_pos)
            return mask_pos < other.mask_pos;
        if (mask_fixed != other.mask_fixed)
            return mask_fixed < other.mask_fixed;
        return num < other.num;
    }
};


vector<ull> data;

long long a, b, k, n, m, tmp;

ull ans = 0;
int anslen = 0;

int solve()
{
    cin >> n >> m >> k;

    const int iters = 12;

    ::data.resize(n);

    priority_queue<tmm> q;

    vi nums(m, 0);

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        ull val = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            val *= 2;
            nums[i]++;
            val += s[i] - '0';
        }

        ::data[i] = val;
    }

    for (int id = 0; id < iters; ++id)
    {
        int rnd = (rand()+1000ll*rand())%n;
        //log(rnd);

        ull mask = ::data[rnd];

        for (int i = 0; i < n; ++i)
        {
            ull tmm = ::data[i] & mask;
            q.push({tmm, tmm, 1});
        }

        int bit = 61;
        while(!q.empty())
        {
            tmm cur = q.top();
            q.pop();
            while(!q.empty())
            {
                tmm next = q.top();
                if (next.mask_pos != cur.mask_pos || next.mask_fixed != cur.mask_fixed)
                    break;

                cur.num += q.top().num;
                q.pop();
            }


            //cendl;
            //log(cur.ft.ft);
            //log(cur.ft.sd);
            //log(cur.sd);

            int lencur = __builtin_popcountll(cur.mask_fixed);

            //log(lencur);

            if (lencur <= anslen)
                continue;

            if (cur.num*2 >= n)
            {
                anslen = lencur;
                ans = cur.mask_fixed;
                continue;
            }

            if (cur.mask_pos == 0)
                continue;

            ull bitt = (1ll<<bit);

            while((bitt & cur.mask_pos) == 0)
            {
                --bit;
                bitt = (1ll<<bit);

               // log(bit);
                //log(bitt);
            }

            //log(bit);
            //log(bitt);

            cur.mask_pos ^= bitt;
            q.push(cur);
            cur.mask_fixed ^= bitt;
            q.push(cur);
        }
    }





    vi as(m);
    int id = 0;
    while(ans > 0)
    {
        as[id] = ans % 2;
        ans /= 2;
        ++id;
    }
    //cendl;
    for (int i = m-1; i >= 0; --i)
    {
        cout << as[i];
    }
    cendl;





    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}