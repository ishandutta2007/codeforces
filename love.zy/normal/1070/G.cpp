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

const int maxn=105;
int ishero[maxn];
bool walked[maxn];
int a[maxn];
int n,m;
vi ans;

bool canwalk(int bg,int ed)
{
    if(bg==ed || walked[bg])return true;
    int dir=1;
    if(bg>ed)dir=-1;
    int hp=a[bg];
    bool f=false;
    while(!f)
    {
        if(bg==ed)f=true;
        if(walked[bg])
        {
            bg+=dir;
            continue;
        }
        if(!walked[bg] && !ishero[bg])hp+=a[bg];
        if(hp<0)return false;
        bg+=dir;
    }
    return true;
}

bool solve1(int pos)
{
    ans.clear();
    int last;
    last=pos;
    for(int i=1;i<=n;i++)walked[i]=false;
    for(int i=pos;i>=1;i--)
        if(ishero[i] && canwalk(i,pos))
        {
            for(int p=i;p<=last;p++)
            {
                if(ishero[p] && !walked[p])ans.pb(ishero[p]);
                walked[p]=true;
            }
            last=i;
        }
    for(int i=pos;i>=1;i--) if(!walked[i] && ishero[i]) return false;
    last=pos;
    //for(int i=1;i<=n;i++)walked[i]=false;
    for(int i=pos;i<=n;i++)
        if(ishero[i] && canwalk(i,pos))
        {
            for(int p=i;p>=last;p--)
            {
                if(ishero[p] && !walked[p])ans.pb(ishero[p]);
                walked[p]=true;
            }
            last=i;
        }
    for(int i=pos;i<=n;i++) if(!walked[i] && ishero[i]) return false;
    return true;
}

bool solve2(int pos)
{
    ans.clear();
    int last;
    last=pos;
    for(int i=1;i<=n;i++)walked[i]=false;
    for(int i=pos;i<=n;i++)
        if(ishero[i] && canwalk(i,pos))
        {
            for(int p=i;p>=last;p--)
            {
                if(ishero[p] && !walked[p])ans.pb(ishero[p]);
                walked[p]=true;
            }
            last=i;
        }
    for(int i=pos;i<=n;i++) if(!walked[i] && ishero[i]) return false;
    last=pos;
    //for(int i=1;i<=n;i++)walked[i]=false;
    for(int i=pos;i>=1;i--)
        if(ishero[i] && canwalk(i,pos))
        {
            for(int p=i;p<=last;p++)
            {
                if(ishero[p] && !walked[p])ans.pb(ishero[p]);
                walked[p]=true;
            }
            last=i;
        }
    for(int i=pos;i>=1;i--) if(!walked[i] && ishero[i]) return false;
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ishero[x]=i;
        a[x]=y;
    }
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(!ishero[i])a[i]=x;
    }
    for(int pos=1;pos<=n;pos++)
    {
        if(solve1(pos))
        {
            printf("%d\n",pos);
            for(int i=0;i<ans.size();i++)
            {
                printf("%d",ans[i]);
                if(i+1<ans.size())putchar(' ');else puts("");
            }
            return 0;
        }
        if(solve2(pos))
        {
            printf("%d\n",pos);
            for(int i=0;i<ans.size();i++)
            {
                printf("%d",ans[i]);
                if(i+1<ans.size())putchar(' ');else puts("");
            }
            return 0;
        }
    }
    puts("-1");
    return 0;
}