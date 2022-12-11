#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 1e5 + 13;

int TC, N;
int arr[MAXN];
vi edge[MAXN];
priority_queue<int> pq;
ll ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    while(TC--)
    {
        ans = 0;
        cin >> N;
        FOR(i, 0, N)
        {
            cin >> arr[i];
            edge[i].clear();
        }
        FOR(i, 0, N - 1)
        {
            int u, v;
            cin >> u >> v; u--; v--;
            edge[u].PB(v);
            edge[v].PB(u);
        }
        FOR(i, 0, N)
        {
            FOR(j, 0, SZ(edge[i]) - 1)
            {
                pq.push(arr[i]);
            }
            ans += arr[i];
        }
        cout << ans;
        while(!pq.empty())
        {
            int u = pq.top(); pq.pop();
            ans += u;
            cout << ' ' << ans;
        }
        cout << '\n';
    }
    return 0;
}