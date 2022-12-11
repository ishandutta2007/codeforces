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
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define MAXN 600013
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N, K;
bitset<MAXN> arr;
vi pos[MAXN];
vi inds[MAXN];
int dsu[3 * MAXN], siz[3 * MAXN], stor[3 * MAXN];
int ans;

int get(int u)
{
    return (u == dsu[u] ? u : dsu[u] = get(dsu[u]));
}
void merge(int a, int b)
{
    a = get(a);
    b = get(b);
    if (a == b) return;
    dsu[a] = b;
    // cerr << "siz " << b << " = " << siz[b] + siz[a] << endl;
    siz[b] += siz[a];
    siz[a] = 0;
    return;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cout << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;
    string temps; cin >> temps;
    FOR(i, 0, N)
    {
        arr[i] = (temps[i] == '1');
    }
    FOR(i, 0, 3 * K + 1)
    {
        dsu[i] = i;
        siz[i] = (i >= K);
    }
    siz[3 * K] = INF;
    FOR(i, 0, K)
    {
        int x; cin >> x; pos[i].resize(x);
        FOR(j, 0, x)
        {
            cin >> pos[i][j]; pos[i][j]--;
            inds[pos[i][j]].PB(i);
        }
    }
    //you're guaranteed that everything appears at most twice.
    //you add an edge i -> j. what's the sum of sizes of the best we can do for each of them?
    //link it with 3N if its a failure.
    FOR(i, 0, N)
    {
        // cerr << "i = " << i << endl;
        if (inds[i].empty())
        {
            cout << ans << '\n';
            continue;
        }
        if (SZ(inds[i]) == 1)
        {
            int u = inds[i][0];
            if (get(u) == get(3 * K) || get(u + K) == get(3 * K))
            {
                //no new information
                cout << ans << '\n';
                continue;
            }
            int w = get(2 * K + u);
            ans -= stor[w];
            if (arr[i])
            {
                //u must be off
                stor[w] = siz[get(u)];
                merge(u + K, 3 * K);
            }
            else
            {
                stor[w] = siz[get(u + K)];
                merge(u, 3 * K);
            }
            ans += stor[get(2 * K + u)];
        }
        if (SZ(inds[i]) == 2)
        {
            int u = inds[i][0], v = inds[i][1];
            if (get(2 * K + u) == get(2 * K + v))
            {
                //no new information
                cout << ans << '\n';
                continue;
            }
            int w = get(2 * K + u), x = get(2 * K + v);
            ans -= stor[w];
            ans -= stor[x];
            // cerr << "ans = " << ans << endl;
            if (arr[i])
            {
                //they must be equal
                merge(u, v);
                merge(u + K, v + K);
            }
            else
            {
                //they must be different
                merge(u, v + K);
                merge(u + K, v);
            }
            merge(2 * K + u, 2 * K + v);
            stor[get(2 * K + u)] = min(siz[get(u)], siz[get(u + K)]);
            ans += stor[get(2 * K + u)];
        }
        // cerr << "ANS = " << ans << endl;
        cout << ans << '\n';
    }
    return 0;
}