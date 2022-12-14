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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vector<int> xxor(10000, -1);
    vvi xorsToCheck(5001);

    xxor[0] = true;
    for (int i = 0; i < xorsToCheck.size(); ++i)
    {
        xorsToCheck[i].pb(0);
    }

    int x;
    for (int ix = 0; ix < n; ++ix)
    {
        cin >> x;


    /*for (int i = 0; i < xxor.size(); ++i)
    {
        if (xxor[i]) ++ans;
    }
    cout << ans << endl;
    ans = 0;

    for (int i = 0; i < xxor.size(); ++i)
    {
        if (xxor[i]) cout << i << " ";
    }
    cendl;*/

        for (int i = 0; i < xorsToCheck[x].size(); ++i)
        {

            //cout << " xor for("<<x<<") to check: " << xorsToCheck[x][i] << " {" <<(xorsToCheck[x][i]^x)<< "}" << endl;
            int next = xorsToCheck[x][i]^x;
            if (xxor[next] == -1 || xxor[next] > x+1)
            {
                if (xxor[next] == -1)
                    xxor[next] = xorsToCheck.size();
                for (int j = x+1; j < xxor[next]; ++j)
                {
                    if (j == x) continue;
                    xorsToCheck[j].pb(next);
                }
                xxor[next] = x+1;
            }
        }
        xorsToCheck[x].clear();
    }



    for (int i = 0; i < xxor.size(); ++i)
    {
        if (xxor[i] != -1) ++ans;
    }
    cout << ans << endl;

    for (int i = 0; i < xxor.size(); ++i)
    {
        if (xxor[i] != -1) cout << i << " ";
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