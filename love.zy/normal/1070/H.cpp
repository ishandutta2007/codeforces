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

map<string,int> m;
set<string> se;
vector<int> g[1000005];
int cou[1000005];

inline int convert(char c)
{
    if(c<='9')return c-47;
    if(c=='.')return 11;
    return c-85;
}

int n,cnt;
char s[10005][10];

void solve(char *ss,int id)
{
    int len=strlen(ss+1);
    for(int i=1;i<=len;i++)
    {
        string sum="";
        for(int j=i;j<=len;j++)
        {
            sum+=ss[j];
            se.insert(sum);
            if(m[sum]==0)m[sum]=++cnt;
        }
    }
    for(auto p : se)
    {
        int iid=m[p];
        cou[iid]++;
        g[iid].pb(id);
    }
    se.clear();
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        solve(s[i], i);
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s[0]+1);
        int len=strlen(s[0]+1);
        string sum="";
        for(int i=1;i<=len;i++)
        {
            //int tmp=1ll*bs*convert(s[0][i])%mod;
            //sum=(sum+tmp)%mod;
            //bs=1ll*bs*base%mod;
            sum+=s[0][i];
        }
        if(m[sum]==0)puts("0 -");
        else
        {
            printf("%d ",cou[m[sum]]);
            printf("%s\n",s[g[m[sum]][0]]+1);
        }
    }
    return 0;
}