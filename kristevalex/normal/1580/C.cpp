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


vector<pii> data;

vvi lefts;

long long a, b, n, m, tmp, ans = 0;


void update(int x, int y, int st, int diff)
{
    //cout << x << " " << y << " " << st << " " << diff << " ^" << endl;
    int sum = x + y;
    st += x;
    st %= sum;
    for (int i = st; i < st + y; ++i)
    {
        ::lefts[sum][i%sum] += diff;
    }
    /*cout << "/ ";
    for (int i = 0; i < sum; ++i)
    {
        cout << ::lefts[sum][i] << " ";
    }

    cout << "/" << endl;*/
}

int getvl(int pos)
{
    int ret = 0;
    for (int i = 1; i < lefts.size(); ++i)
    {
        ret += lefts[i][pos%i];
    }
    return ret;
}


int solve()
{
    cin >> n >> m;

    ::data.resize(n);

    vi prefans (m, 0);
    vi prevval (n, 0);
    vi smalans (m, 0);

    vvi typesm (n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i].ft >> ::data[i].sd;

    int op;
    int sqrtm = sqrt(m);
    ::lefts.resize(sqrtm+1);
    for (int i = 0; i < lefts.size(); ++i)
    {
        ::lefts[i].assign(i, 0);
    }

    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> op >> k;
        --k;
        if (psum(::data[k]) > sqrtm)
        {
            typesm[k].pb(i);
        }
        else
        {
            int diff = -op * 2 + 3;

            update(::data[k].ft, ::data[k].sd, (diff == 1)? i : prevval[k], diff);

            prevval[k] = i;
        }

        smalans[i] = getvl(i);
    }

    for (int i = 0; i < n; ++i)
    {
        if (typesm[i].size()%2 == 1)
            typesm[i].pb(m+1);
        for (int j = 0; j < typesm[i].size(); j += 2)
        {
            for (int k = 0; k < m; ++k)
            {
                int st = k * psum(::data[i]) + typesm[i][j] + ::data[i].ft;

                if (st >= typesm[i][j+1])
                    break;

                if (st < m)
                    {
                        prefans[st]++;
                        //cout << "!" << st  << "(" << i+1 << ")"<< endl;
                    }
                else
                    break;

                if (st + ::data[i].sd >= typesm[i][j+1])
                {
                    if (typesm[i][j+1] < m)
                        prefans[typesm[i][j+1]]--;
                    break;
                }

                if (st + ::data[i].sd < m)
                    prefans[st + ::data[i].sd]--;
                else
                    break;


            }
        }
    }

    int cur_ans = 0;
    for (int i = 0; i < m; ++i)
    {
        cur_ans += prefans[i];
        cout << cur_ans + smalans[i] << " ";
    }

    cendl;


    //cout << ans << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}