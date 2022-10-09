#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18+3;
int tests, n, m, a, b, c, d,k;
#define maxn 1000100
bool odw[maxn];
vector <int> v[maxn];
int cats[maxn];

int wyn = 0;
int leaves;
void dfs(int x, int num)
{
    odw[x] = true;
    if (num >= 0) {
    if (cats[x]) ++num;
    else num = 0;
    }
    if (num > k || num < 0) num = -inf;
    //cout << x << ' ' << num <<endl;
    bool czy = true;
    for (auto u:v[x])
    {
        if (!odw[u])
        {
            czy = false;
            dfs(u, num);
        }
    }
    if (czy && num < 0) ++wyn;
    if (czy) ++leaves;
}
int main()
{
    boost;
    cin >> n >> k;
    for (int i=1; i<=n; ++i) cin >> cats[i];
    for (int i=1; i<n; ++i) 
    {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, 0);

    cout << leaves - wyn;
}