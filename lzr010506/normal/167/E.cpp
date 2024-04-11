#include <bits/stdc++.h>
#define vi vector<int>
#define N 610
#define pb push_back
using namespace std;
typedef long long ll;

int P, n;
vi g[N], A, B;
int In[N], Out[N], dp[N];

int dfs(int u)
{
    if (dp[u] != -1) return dp[u];
    int ans = 0;
    for(int i = 0; i < g[u].size(); i ++)
    {
        ans += dfs(g[u][i]);
        if(ans >= P) ans -= P;
    }
    return dp[u] = ans;
}

int D;
ll a[N][N];

inline ll Pow(ll x, ll n)
{
    if (n == 0) return 1;
    ll ans = Pow(x, n >> 1);
    ans = ans * ans % P;
    if (n & 1) ans = ans * x % P;
    return ans;
}

ll calc()
{
    bool flag = false;
    for(int j = 0; j < D; j ++)
    {
        int i;
        for(i = j; i < D; i ++)
            if(a[i][j]) break;
        if(i == D) return 0;
        if(i != j)
        {
            flag = !flag;
            for(int k = 0; k < D; k ++)
                swap(a[i][k], a[j][k]);
        }
        for(i = j + 1; i < D; i ++)
        {
            ll F = (P - a[i][j]) * Pow(a[j][j], P - 2) % P;
            for(int k = j; k < D; k ++) 
                a[i][k] = (a[i][k] + a[j][k] * F) % P;
        }
    }
    ll ans = (flag ? (P - 1) : 1);
    for(int i = 0; i < D; i ++)
        ans = ans * a[i][i] % P;
    return ans;
}

int main()
{
    int M;
    cin >> n >> M >> P;
    for(int i = 0; i < M; i ++)
    {
        int x,y;
        cin >> x >> y;
        x --;
        y --;
        In[y] ++;
        Out[x] ++;
        g[y].pb(x);
    }
    
    for(int i = 0; i < n; i ++)
    {
        if(In[i] > 0 && Out[i] == 0) B.pb(i);
        if(In[i] == 0 && Out[i] > 0) A.pb(i);
    }
    
    D = B.size();
    for(int i = 0; i < D; i ++)
    {
        memset(dp, -1, sizeof(dp));
        dp[A[i]] = 1;
        for(int j = 0; j < D; j ++)
            a[i][j] = dfs(B[j]);
    }
    
    ll ans = calc();
    bool flag = false;
    for(int i = 0; i < n; i ++)
        if(In[i] == 0 && Out[i]==0)
        {
            int cnt1 = 0,cnt2=0;
            for(int j = 0; j < D; j ++)
            {
                if(B[j] < i) cnt1 ++;
                if(A[j] < i) cnt2 ++;
            }
            if((cnt1 & 1) != (cnt2 & 1)) 
                flag = !flag;
        }
    if(flag) ans = (P - ans) % P;
    cout << ans << endl;
    return 0;
}