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

const int maxn = 100005;
vi g[maxn];
int cnt;
map< pair<string, int> ,int> m;

char s1[1000005],s2[1000005];
int base1 = 19260817, mod1 = 1e9+9;
int base2 = 47, mod2 = 1e9+7;

pair<string, int> judge()
{
    scanf("%s %s",s1+1, s2+1);
    int mask=0;
    int l1 = strlen(s1+1), l2 = strlen(s2+1);
    for(int i=1;i<=l2;i++)
    {
        int u = s2[i]-97;
        mask |= (1<<u);
    }
    int sum1 = 0, sum2 = 0;
    while(l1>0)
    {
        int u = s1[l1] - 97;
        if((mask>>u)&1) {l1--;continue;}
        break;
    }
    string ret="";
    for(int i=1;i<=l1;i++)ret+=s1[i];
    return mp(ret, mask);
}

int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        pair<string ,int> now = judge();
        if(m[now]==0)m[now]=++cnt;
        g[m[now]].pb(i);
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("%d",(int)g[i].size());
        for(int p : g[i]) printf(" %d",p);
        puts("");
    }
    return 0;
}