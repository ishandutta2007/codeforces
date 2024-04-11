#include<iostream>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<cmath>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<cstdio>
#include<bitset>
#include<chrono>
#include<random>

/* ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
*/

#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const ll oo = 1e18;
int n, m;
int f[maxN];
inline void FastInput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
void ReadInput()
{
    cin >> n >> m;
}
void Solve()
{
    //  fill(f + 1, f + m + 1, 0);
    char a[n + 2][m + 2];
    for(int i=0; i<=n+1; i++)
        for(int j=0; j<=m+1; j++)
            a[i][j] = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> a[i][j];
    vector<int> vc;
    for(int j=1; j<=m; j++)
    {
        bool chk = false;
        for(int i=1; i<=n; i++)
        {
            if(a[i][j - 1] == 'X' && a[i - 1][j] == 'X') chk = true;
        }
        if(chk) vc.pb(j - 1);
    }
    vc.pb(m + 10);
    int q, l, r;
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        if(l == r)
        {
            cout << "YES" << '\n';
            continue;
        }
        int t = *lower_bound(vc.begin(), vc.end(), l);
        cout << (t < r ? "NO" : "YES") << '\n';
    }
}
int main()
{
    //freopen("x.inp", "r", stdin);
    FastInput();
    ReadInput();
    Solve();
}