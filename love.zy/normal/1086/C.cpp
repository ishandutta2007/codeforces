/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=1000005;
char s[maxn],a[maxn],b[maxn];
int n,k,T;
int vis[27],ans[27];

void op()
{
    puts("YES");
    int p=1;
    for(int i=1;i<=k;i++)
    {
        if(ans[i]>0){putchar(96+ans[i]);continue;}
        while(vis[p] > 0) p++;
        vis[p]=i;ans[i]=p;
        putchar(96+ans[i]);
    }
    puts("");
}

bool solvea(int pos)
{
    int ansa[27], visa[27];
    for(int i=1;i<=k;i++)ansa[i]=ans[i], visa[i]=vis[i];
    ansa[s[pos]-96] = a[pos]-96;
    visa[a[pos]-96] = s[pos]-96;
    for(int i=pos+1;i<=n;i++)
    {
        int si = s[i] - 96;
        int ai = a[i] - 96;
        if(ansa[si] > 0)
        {
            if(ansa[si] > ai) break;
            if(ansa[si] < ai) return false;
        }else
        {
            bool flag = false;
            for(int j=ai+1;j<=k;j++)
                if(visa[j]==0) {flag = true; visa[j] = si; ansa[si] = j; break;}
            if(flag) break;
            if(visa[ai] > 0) return false;
            ansa[si] = ai;
            visa[ai] = si;
        }
    }
    for(int i=1;i<=k;i++)ans[i]=ansa[i], vis[i]=visa[i];
    return true;
}

bool solveb(int pos)
{
    int ansb[27], visb[27];
    for(int i=1;i<=k;i++)ansb[i]=ans[i], visb[i]=vis[i];
    ansb[s[pos]-96] = b[pos]-96;
    visb[b[pos]-96] = s[pos]-96;
    for(int i=pos+1;i<=n;i++)
    {
        int si = s[i] - 96;
        int bi = b[i] - 96;
        if(ansb[si] > 0)
        {
            if(ansb[si] < bi) break;
            if(ansb[si] > bi) return false;
        }else
        {
            bool flag = false;
            for(int j=1;j<bi;j++)
                if(visb[j]==0) {flag = true; visb[j] = si; ansb[si] = j; break;}
            if(flag) break;
            if(visb[bi] > 0) return false;
            ansb[si] = bi;
            visb[bi] = si;
        }
    }
    for(int i=1;i<=k;i++)ans[i]=ansb[i], vis[i]=visb[i];
    return true;
}

bool solve()
{
    for(int i=1;i<=k;i++)ans[i]=vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        int si = s[i] - 96;
        int ai = a[i] - 96;
        int bi = b[i] - 96;
        //printf("111 %d %d %d %d\n",i,si,ai,bi);
        if(ai > bi) return false;
        if(ans[si] > 0 && (ans[si] < ai || ans[si] > bi)) return false;
        if(ai == bi && ans[si] == ai) continue;
        if(ai == bi)
        {
            if(vis[ai]>0)return false;
            ans[si] = ai; vis[ai] = si;
            continue;
        }
        if(ans[si] == 0)
        {   
            for(int j=ai+1;j<=bi-1;j++)
            {
                if(!vis[j])
                {
                    ans[si]=j;
                    vis[j]=si;
                    return true;
                }
            }
            if(vis[ai] == 0 && solvea(i)) return true;
            if(vis[bi] == 0 && solveb(i)) return true;
            return false;
        }else
        {
            if(ans[si] > ai && ans[si] < bi) return true;
            if(ans[si] == ai) return solvea(i);
            if(ans[si] == bi) return solveb(i);
            return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        scanf("%s",s+1);
        scanf("%s",a+1);
        scanf("%s",b+1);
        n = strlen(s+1);
        if(solve()) op();else puts("NO");
    }
    return 0;
}