#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<int> data;
vector<int> xxor;

long long a, b, k, n, m, tmp, ans = 0;


int getxxor(int l, int r)
{
    return ::xxor[r] - ::xxor[l];
}


int solve()
{
    cin >> n;

    ::data.resize(n);
    ::xxor.resize(n+1);
    ::xxor[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i];
        ::xxor[i+1] = ::xxor[i]^::data[i];
    }


    for(int bit = 1; bit < 2000000; bit *= 2)
    {
        for (int st = 0; st < n; ++st)
        {
            if (::data[st] & bit)
            {
                int en = st;
                for (; en < n; ++en)
                {
                    if (!(::data[en] & bit))
                        break;
                }

                map<pair<int, int>, int> pts;

                for (int i = st; i < en; ++i)
                {

                    pair<int, int> cur = {::xxor[i]/(bit*2), i % 2};
                    pair<int, int> req = {::xxor[i+1]/(bit*2), (i+1) % 2};

                    /*if (bit <= 4)
                    {
                        cout <<"bit:" << bit <<" (" << st << ", " << en << "), ("<<i << ") : req[" <<  req.first<< ", "<< req.second << "], cur[" << cur.first<< ", "<< cur.second <<"]" <<endl;
                    }*/

                    if (pts.count(req))
                        ans = max((int)ans, i - pts[req] + 1);
                    if (!pts.count(cur))
                        pts[cur] = i;
                }

                st = en;
            }
        }
    }


    cout << ans;

    return 0;
}


int main()
{
    FAST;

        solve();



    return 0;
}