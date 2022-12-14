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
#define cyes cout << "YES\n"
#define cno cout << "NO\n"
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl



long long a, b, k, n, m, tmp;



int solve()
{
    cin >> n;
    m = 0;

    vi data(n);

    int l1 = -1, r1 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
        m ^= data[i];
        if (l1 == -1 && data[i])
        {
            l1 = i;
            r1 = i;
        }
    }
    if (m)
    {
        cno;
        return 0;
    }

    vi ans;

    if (l1 != -1)
    {
        for (int i = l1; i < n; ++i)
        {
            //log(i);
            //log(l1);
            //log(r1);
            if (data[i])
            {
                if (r1 == i)
                {
                    r1 = i+1;

                    if (l1 > 0 && r1 - l1 > 1)
                    {
                        ans.pb(l1-1);
                        data[l1-1] = 0;
                        data[l1] = 0;
                        data[l1+1] = 0;
                        l1 += 2;
                    }
                }
                else
                {
                    //log(i+0);
                    for (int j = i-2; j >= l1; j -= 2)
                    {
                        ans.pb(j);
                        data[j] = 0;
                        data[j+1] = 0;
                        data[j+2] = 0;
                    }

                    l1 = i+1;
                    r1 = i+1;
                }
            }
            else
            {
                if (l1 == i)
                {
                    //log('1');
                    l1 = i+1;
                    r1 = i+1;
                }
                else if (r1 == i)
                {
                    //log('2');
                    if ((r1 - l1) % 2 == 0)
                    {
                        for (int j = i-2; j >= l1; j -= 2)
                        {
                            ans.pb(j);
                            data[j] = 0;
                            data[j+1] = 0;
                            data[j+2] = 0;
                        }

                        l1 = i+1;
                        r1 = i+1;
                    }

                }
                else if (r1 == i-1)
                {
                    //log('3');
                    ans.pb(r1-1);
                    data[r1-1] = 1;
                    data[r1] = 1;
                    data[r1+1] = 1;

                    r1 = i+1;

                    if (l1 > 0)
                    {
                        ans.pb(l1-1);
                        data[l1-1] = 0;
                        data[l1] = 0;
                        data[l1+1] = 0;
                        l1 += 2;
                    }

                }
                else break;
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
        if (data[i])
            ok = false;
    }

    if (ok)
    {
        cyes;
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans[i]+1 << ' ';
        }
        cout << '\n';
        return 0;
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