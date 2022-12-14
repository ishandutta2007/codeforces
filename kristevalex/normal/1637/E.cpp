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

#include <vector>
#include <algorithm>

inline std::vector<int> Compress(const std::vector<int>& arr)
{
    const int arraySize = arr.size();
    std::vector<std::pair<int, int>> indexedArr(arraySize);
    std::vector<int> ret(arraySize);

    for (int i = 0; i < arraySize; ++i)
        indexedArr[i] = {arr[i], i};
    sort(indexedArr.begin(), indexedArr.end());

    int curId = 0;
    for (int i = 0; i < arraySize; ++i)
    {
        ret[indexedArr[i].second] = curId;
        if (i+1 < arraySize && indexedArr[i].first != indexedArr[i+1].first)
            ++curId;
    }

    return ret;
}



int solve()
{
    cin >> n >> m;

    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    sort(all(data));

    vi datac = Compress(data);

    vi values;
    vi cnts;

    //map<int, int> mp;

    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || data[i] != data[i-1])
        {
           // mp[data[i]] = datac[i];
            values.pb(data[i]);
            cnts.pb(1);
        }
        else
            cnts[cnts.size()-1]++;
    }

    set<pii> st;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        //u = mp[u];
        //v = mp[v];
        st.insert({min(u, v), max(u, v)});

    }


    ans = 0;

    vector<pii> cnt_val(cnts.size());
    for (int i = 0; i < cnts.size(); ++i)
    {
        cnt_val[i] = {cnts[i], values[i]};
    }
    sort(all(cnt_val));

    vector<pair<int, vi>> cnt_vals;
    for (int i = 0; i < cnt_val.size(); ++i)
    {
        if (i == 0 || cnt_val[i].ft != cnt_val[i-1].ft)
        {
            cnt_vals.pb({cnt_val[i].ft, {cnt_val[i].sd}});
        }
        else
            cnt_vals[cnt_vals.size()-1].sd.pb(cnt_val[i].sd);
    }

    /*for (int i = 0; i < cnt_vals.size(); ++i)
    {
        log(i);
        log(cnt_vals[i].ft);
        for (int j = 0; j < cnt_vals[i].sd.size(); ++j)
        {
            cout << cnt_vals[i].sd[j] << " ";
        }
        cendl;
        cendl;
    }*/
ans = 0;


    for (int id = 0; id < cnt_vals.size(); ++id)
    {
        for (int jd = id; jd < cnt_vals.size(); ++jd)
        {
            ll cntsum = cnt_vals[id].ft + cnt_vals[jd].ft;
            ll maxvals = 0;
            ll maxover = cnt_vals[id].sd[cnt_vals[id].sd.size()-1];
            //log(maxover);

            if (id != jd)
            {
                for (int i = cnt_vals[jd].sd.size()-1; i >= 0; --i)
                {
                    int curvl = cnt_vals[jd].sd[i];
                    if (curvl + maxvals <= maxvals)
                        break;

                    for (int j = cnt_vals[id].sd.size()-1; j >= 0; --j)
                    {
                        int curvl2 = cnt_vals[id].sd[j];
                        if (curvl + curvl2 <= maxvals)
                            break;

                        if (st.count({min(curvl, curvl2), max(curvl, curvl2)}) == 0)
                        {
                            maxvals = curvl2 + curvl;
                            break;
                        }
                    }
                }
            }
            else
            {
                for (int i = cnt_vals[jd].sd.size()-1; i >= 0; --i)
                {
                    int curvl = cnt_vals[jd].sd[i];
                    if (curvl + maxvals <= maxvals)
                        break;

                    for (int j = i-1; j >= 0; --j)
                    {
                        int curvl2 = cnt_vals[id].sd[j];
                        if (curvl + curvl2 <= maxvals)
                            break;

                        if (st.count({min(curvl, curvl2), max(curvl, curvl2)}) == 0)
                        {
                            maxvals = curvl2 + curvl;
                            break;
                        }
                    }
                }
            }

            //log(cntsum);
            //log(maxvals);
            ans = max(ans, cntsum*maxvals);
        }
    }





    cout << ans << '\n';

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