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

long long a, b, k, n, m, tmp;



int solve()
{
    cin >> n >> k;

    vi prev(n+1, -1);

    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i <= k; ++i)
        {
            if (i > cur)
                continue;
            if (cur + k - i > n)
                continue;

            int next = cur - i + k - i;

            if (prev[next] == -1)
            {
                //cout << cur << " -> " << next << endl;

                prev[next] = cur;
                q.push(next);
            }
        }
    }

    vi ans;
    if (prev[n] == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    int tm = n;
    while(tm > 0)
    {
        ans.pb(tm);
        tm = prev[tm];
    }

    ll resxor = 0;
    vi cnt(n, 0);


    int cur = 0;
    int next = 0;
    for (int id = ans.size()-1; id >= 0; --id)
    {
        cur = next;
        next = ans[id];
        int diff = next - cur;
        int com = (k - diff)/2;
        int rest = k - com;
        cout << "? ";

        for (int i = 0; i < n; ++i)
        {
            if (cnt[i] == 0)
            {
                if (rest > 0)
                {
                    --rest;
                    cnt[i] = 1;
                    cout << i+1 << " ";
                }
            }
            else
            {
                if (com > 0)
                {
                    --com;
                    cnt[i] = 0;
                    cout << i+1 << " ";
                }
            }
        }

        cout << endl;
        cin >> tmp;
        resxor ^= tmp;
    }

    cout << "! " << resxor << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}