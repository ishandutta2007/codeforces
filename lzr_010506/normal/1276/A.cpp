#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
char a[200010];
vector<int> ans;
int main()
{
    int T = read();
    while(T --)
    {
        ans.clear();
        scanf("%s", a + 1);
        int n = strlen(a + 1);
        rep(i, 1, n)
        {
            if(a[i] == 't' && a[i + 1] == 'w' && a[i + 2] == 'o' && a[i + 3] == 'n' && a[i + 4] == 'e')
            {
                if(i + 4 > n) continue;
                ans.pb(i + 2);
                i = i + 3;
                continue;
            }
            if(a[i] == 't' && a[i + 1] == 'w' && a[i + 2] == 'o')
            {
                if(i + 2 > n) continue;
                ans.pb(i + 1);
                i = i + 1;
                continue;
            }
            if(a[i] == 'o' && a[i + 1] == 'n' && a[i +2] == 'e')
            {
                if(i + 2 > n) continue;
                ans.pb(i + 1);
                i = i + 1;
                continue;
            }
        }
        printf("%d\n", sz(ans));
        for(auto x : ans) printf("%d ", x);
        puts("");
    }
    return 0;
}