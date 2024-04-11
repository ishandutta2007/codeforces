#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;

const int64 oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

vi ady[MAXN];

int64 hi[MAXN];
int64 lo[MAXN];
int64 val[MAXN];
int64 tot[MAXN];
bool mk[MAXN];

void dfs(int64 s)
{
    mk[s] = true;
    tot[s] = 1;
    for (int64 i = 0; i < (int64)ady[s].size(); ++i){
        int64 nx = ady[s][i];

        if (s == lo[nx] && mk[hi[nx]]) continue;
        if (s == lo[nx]) swap(lo[nx], hi[nx]);

        int64 ll = lo[nx];

        if (!mk[ll])
        {
            dfs(ll);
            tot[s] += tot[ll];
        }
    }
}

int main()
{
    int64 n; cin >> n;

    for (int64 i = 0; i < n - 1; ++i){
        int64 a, b, w; cin >> a >> b >> w;
        a--; b--;
        hi[i] = a, lo[i] = b;
        val[i] = w;
        ady[a].push_back(i);
        ady[b].push_back(i);
    }

    dfs(0);

    double ans = 0;

    for (int64 i = 0; i < n - 1; ++i)
    {
        ans += (tot[ lo[i] ] * (n - tot[ lo[i] ])) * val[i];
    }

    double fact = (1.0 * n) * (n - 1) / (6.0);

    int64 q; cin >> q;
    cout.precision(7);
    for (int64 i = 0; i < q; ++i){
        int64 a, b; cin >> a >> b;
        a--;
        int64 dx = val[a] - b;
        val[a] = b;
        ans -= dx * (tot[ lo[a] ] * (n - tot[ lo[a] ]));
        cout << fixed << ans / (fact) << endl;
    }
}