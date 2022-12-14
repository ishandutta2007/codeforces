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


vector<string> data;
vector<int> max_dn;
vector<int> add_up;
vector<vector<int>> comp;

long long a, b, k, n, m, tmp, ans = 0;

void work(int id)
{
    ::max_dn[id] = 0;
    ::add_up[id] = 0;

    for (int i = 0; i < ::data[id].size(); ++i)
    {
        if (::data[id][i] == '(')
            ::add_up[id]++;
        else
        {
            if (::add_up[id] > 0)
                ::add_up[id]--;
            else
                ::max_dn[id]++;

            if (::add_up[id] == 0 && ::max_dn[id] < ::comp[id].size())
                ::comp[id][::max_dn[id]]++;
        }

    //cout << "! " << ::max_dn[id] << " " << add_up[id] << endl;
    }

}

int solve()
{
    //cout << (1<<2) << " " << (1>>2) << endl;

    cin >> n;

    int maxMask = 1;
    for (int i = 0; i < n; ++i)
        maxMask *= 2;

    int total = 0;

    ::data.resize(n);
    ::max_dn.resize(n);
    ::add_up.resize(n);
    ::comp.resize(n);

    for (int i = 0; i < n; ++i)
        ::comp[i].assign(200010, 0);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    for (int i = 0; i < n; ++i)
    {
        work(i);

        total += ::add_up[i] - ::max_dn[i];
        /*cout << ::max_dn[i] << " "<<::add_up[i] << endl;
        for (int j = 0; j < 10; ++j)
            cout << ::comp[i][j] << " ";
        cendl;*/
    }

    vpii dp(maxMask);
    dp[0] = {0, total};

    for (int i = 1; i < maxMask; ++i)
    {
        dp[i].ft = 0;
        for (int num = 0; num < n; ++num)
        {
            int curMask = 1<<num;
            if (i&curMask)
            {
                int prevMask = i - curMask; //i^curMask;
                int diff = ::add_up[num] - ::max_dn[num];

                dp[i].sd = dp[prevMask].sd - diff;
                int dpn = 0;
                if (dp[i].sd >= 0 && dp[i].sd < comp[num].size())
                    dpn = comp[num][dp[i].sd];
                if (dp[i].sd >= ::max_dn[num])
                    dpn += dp[prevMask].ft;

                if (dpn > dp[i].ft)
                    dp[i].ft = dpn;
            }
        }
    }


    cout << dp[maxMask-1].ft << endl;


    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}