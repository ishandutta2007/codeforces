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



long long a, b, k, n, m, tmp, ans = 0;

/*


5
10 0
4 4 5 5 6 6 1 1 0 0
10 1
4 4 5 5 6 6 1 1 0 0
10 2
4 4 5 5 3 3 1 1 0 0
2 2
10 10
2 1
10 10

8
3 0
0 10 111
3 0
0 111 111
3 0
1 111 111
3 1
1 111 111
3 1
1 101 111
2 1
100 101
2 0
100 101
2 2
100 101

4
1 1
1
1 0
1
1 1
0
1 0
0


6
6 0
1 1 0 3 4 7
1 0
666
1 0
0
2 0
1 2
2 0
1 0
2 0
0 4


8
7 0
104 101 102 102 1000 1000 1000
7 1
104 101 102 102 1000 1000 1000
7 2
104 101 102 102 1000 1000 1000
7 3
104 101 102 102 1000 1000 1000
7 4
104 101 102 102 1000 1000 1000
7 5
104 101 102 102 1000 1000 1000
7 6
104 101 102 102 1000 1000 1000
7 7
104 101 102 102 1000 1000 1000

6
5 0
1 0 1 4 6
5 1
1 0 1 4 6
5 2
1 0 1 4 6
5 3
1 0 1 4 6
5 4
1 0 1 4 6
5 5
1 0 1 4 6

1
3 1
1 1 1

*/



int solve()
{
    cin >> n >> k;

    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    vpii cnt;

    sort(all(data));
    int cur = data[0];
    int num_ = 0;
    for (int i = 0; i < n; ++i)
    {
        if (data[i] == cur)
        {
            ++num_;
        }
        else
        {
            cnt.pb({cur, num_});
            cur = data[i];
            num_ = 1;
        }
    }
    cnt.pb({cur, num_});

    m = cnt.size();

    vi req(m+1, 0);
    vi res(m+1, 0);

    set<pii> st;
    ll sum = 0;
    ll num = 0;
    pii last = {-1, -1};

    if (k >= n)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        res[i] = cnt[i-1].ft + 1;
        req[i] = cnt[i-1].ft - i + 1;
        //log(i);
        //log(req[i]);
    }
    if (k == 0)
    {
        for (int i = 0; i < m; ++i)
        {
            if (cnt[i].ft != i)
            {
                cout << m - i << endl;
                return 0;
            }
        }

        cout << 0 << endl;
        return 0;
    }
    if (cnt[m-1].ft == m-1)
    {
        cout << 0 << endl;
        return 0;
    }




    ans = 1e17;

    for (int i = m; i >= 0; --i)
    {
        if (i < m) {
            pii curpush = {cnt[i].sd, cnt[i].ft};
            st.insert(curpush);
            //log("insert");
            //cendl;
            if (curpush < last)
            {
                //log(sum);
                //log(last.ft);
                //log(curpush.ft);
                sum -= last.ft;
                sum += curpush.ft;
                //log(sum);
                //cendl;
                auto it = st.find(last);
                --it;
                last = *it;
                //log(last.ft);
                //log(last.sd);
            }

            while(sum < k)
            {
                auto it = st.upper_bound(last);
                if (it == st.end())
                    break;

                //log(sum);
                sum += it->ft;

                //log(it->ft);
                //log(sum);
                //cendl;
                ++num;

                last = *it;
            }
        }

        ll actual = min(k, sum);

        if (i > 0)
        {
            //log(cnt[0].ft);
            //log(cnt[0].sd);
            actual += cnt[i-1].sd-1;
            //log(cnt[i-1].sd-1);
        }
        //log(actual);


        actual = min(k, actual);
        //log(i);
        //log(actual);
        //log(req[i]);
        //cendl;

        if (actual >= req[i])
        {
            ll actnum = num;
            if (sum > k)
                actnum--;

            ////log(i);
            //log(actnum);
            //log(st.size());
            //log(sum);
            //log(actual);
            //log(req[i]);
            //log(st.size() - actnum);
            //cendl;

            ans = min(ans, st.size() - actnum);
        }
    }




    cout << ans << endl;

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