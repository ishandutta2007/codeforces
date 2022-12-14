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


vi data1;
vi data2;

vi used;

vi cnt;

long long a, b, k, n, m, tmp, ans = 0;


/*


4
4
1 2 3 4
1 3 4 2
6
1 2 3 4 5 6
2 3 1 5 6 4
8
1 2 3 4 5 6 7 8
2 3 1 5 6 4 7 8
5
1 2 3 4 5
2 3 1 4 5


*/

int dfs(int pos)
{
    //log(pos);
    if(used[pos] == 1)
        return 0;

    used[pos] = 1;
    //log(pos);
    if (data1[pos] == data2[pos])
        return 1;

    return 1 + dfs(cnt[data2[pos]]);
}

ll Get(ll x)
{
    ll ret = 0;
    ll cur = 1;
    for (int i = 0; i < x; ++i)
    {
        ret += cur;
        cur += 2;
    }
    return ret;
}

int solve()
{
    cin >> n;

    data1.resize(n);
    data2.resize(n);
    cnt.resize(n);
    used.assign(n, 0);

    ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += 2*abs(n+1-2*i);
    }


    for (int i = 0; i < n; ++i)
    {
        cin >> data1[i];
        --data1[i];
        cnt[data1[i]] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> data2[i];
        --data2[i];
    }

    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;

    //log(ans);

    for (int i = 0; i < n; ++i)
    {
        if (used[i] == 0)
        {

            int cur = dfs(i);
            //log(cur);
            //log(i);

            if (cur == 1)
            {
                ++sum;
                ++sum1;
                continue;
            }

            if (cur%2 == 1)
            {
                sum2++;
                sum += 2;
            }
        }
    }
    //log(ans);


    int val = (n+1)%2;
    for (int i = 0; i < sum; ++i)
    {
        //log(val);
        ans -= val;
        if (i < sum1)
            ans -= val;
        if (i%2 == (n+1)%2)
            val+= 2;
    }

    ans += 2*Get(sum2/2);
    ans += 2*Get((sum2+1)/2);

    /*int lleft = sum/2;
    int rleft = (sum+1)/2;
    if (lleft == rleft && n%2 == 1)
    {
        lleft--;
        rleft++;

        if (sum1 == 0 && lleft%2 == 1)
        {
            lleft++;
            rleft--;
        }
    }
    for (int i = 0; i < sum2; ++i)
    {
        if (rleft < lleft)
            swap(lleft, rleft);

        ans += (rleft-1)*2;
        rleft -= 2;
    }*/




//log(ans);

    cout << ans/2 << endl;

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