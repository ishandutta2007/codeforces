#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int n,root,Cnt,ccnt,ans;
int t[6001][256],id[6001],du[6001],f[6001];
char s1[31],s2[31];

int cnt,next[20001],son[20001],ed[20001];

int l,r,q[10001];

void add(int x,int y)
{
//  printf("%d %d\n",x,y);
    next[++cnt]=son[x]; son[x]=cnt; ed[cnt]=y; du[y]++;
}

int get(char s[])
{
    int len=strlen(s+1);
    int now=root;
    for (int i=1;i<=len;i++)
        if (s[i]>='A'&&s[i]<='Z') s[i]+='a'-'A';
    for (int i=1;i<=len;i++)
    {
        int key=s[i];
        if (!t[now][key]) t[now][key]=++ccnt;
        now=t[now][key];
    }
    if (!id[now]) id[now]=++Cnt;
    return id[now];
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        scanf("%s",s2+1);
        int x=get(s1); int y=get(s2);
        add(y,x);
    }
    for (int i=1;i<=Cnt;i++)
        if (!du[i]) q[++r]=i,f[i]=1;
    while (l!=r)
    {
        int u=q[++l];
        for (int j=son[u];j;j=next[j])
        {
            int v=ed[j];
            f[v]=max(f[v],f[u]+1);
            du[v]--;
            if (!du[v])
            {
                q[++r]=v;
            }
        }
    }
    for (int i=1;i<=Cnt;i++) 
    {
        if (f[i]>ans) ans=f[i];
//      printf("%d\n",f[i]);
    }
    printf("%d\n",ans);
}