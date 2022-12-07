/*****************************
Author : lizi
Email  : zyli@smail.nju.edu.cn
*****************************/

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=3.1415926535897932384626;
const double eln=2.718284590452353602874;
#define IN freopen("tmp.in", "r", stdin);
#define OU freopen("tmp.ou", "w", stdout);
#define mp make_pair
#define pb push_back
#define pr1(x) printf("Case %d: ", x);
#define pn1(x) printf("Case %d:\n",x);
#define pr2(x) printf("Case #%d: ", x);
#define pn2(x) printf("Case #%d:\n",x);
#define sqr(x) (x)*(x)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=100005;
vi g[maxn];
int n,m,ans[maxn];
bool t[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].pb(y);g[y].pb(x);
    }
    int a = -1, b = 0;
    for(int i=1;i<=n;i++)
    {
        sort(g[i].begin(),g[i].end());
        if(g[i].size() >= n - 1) continue;
        a = i;
        for(int j = 1; j<=n;j++)t[i] = false;
        for(int j : g[i])t[j]=true;
        t[i]=true;
        for(int j=1;j<=n;j++)
            if(!t[j]){b=j;break;}
        break;
    }
    if(a == -1){puts("NO");return 0;}
    puts("YES");int cnt = 0;
    ans[a] = n - 1; ans[b] = n;
    for(int i=1;i<=n;i++)
        if(ans[i] == 0) ans[i] = ++cnt;
    for(int i=1;i<=n;i++)printf("%d%c",ans[i], i==n?'\n':' ');
    ans[a] = n;
    for(int i=1;i<=n;i++)printf("%d%c",ans[i], i==n?'\n':' ');
    return 0;
}