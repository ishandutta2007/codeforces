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
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
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
char ch[11], a[11];
int ans, n;

void dfs(int x)
{
    //cout << x << " ";
    if(x == 11)
    {
        int x = 0, y = 0, res = 10;
        //rep(i, 1, n) cout << a[i];
       // cout << endl;
        rep(i, 1, n)
        {
            if(a[i] == '1' && i % 2 == 1) x ++;
            if(a[i] == '1' && i % 2 == 0) y ++;
            int re = 0, rr = 0;
            rep(j, i + 1, n) 
            {
                if(ch[j] == '0' && j % 2 == 1) re ++;
                if(ch[j] == '0' && j % 2 == 0) rr ++;
            }
            if(x > y + (n - i + 1) / 2) 
            {
                res = i;
                break;
            }
            if(x + (n - i) / 2 < y)
            {
                res = i;
                break;
            }
        }
        ans = min(ans, res);
        return;
    }
    if(a[x] != '?') {dfs(x + 1); return;}
    
    a[x] = '1';
    dfs(x + 1);
    a[x] = '0';
    dfs(x + 1);
    a[x] = '?';
}

int main()
{
    int T = read();
    while(T --)
    {
        scanf("%s", ch + 1);
        ans = 10;
        n = 10;
        rep(i, 1, n) a[i] = ch[i];
        dfs(1);
        printf("%d\n", ans);
    }
}