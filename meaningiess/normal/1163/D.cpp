#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 1505
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-'a',ch=getchar();
    return t?-x:x;
}
struct Node{int son[30],ff,s;int w;}t[MAX];
int tot;
void Insert(char *s,int val)
{
    int l=strlen(s+1),u=0;
    for(int i=1;i<=l;++i)
    {
        int c=s[i]-'a';
        if(!t[u].son[c])t[u].son[c]=++tot;
        u=t[u].son[c];
    }
    t[u].w=val;t[u].s+=1;
}
int Q[MAX],L,R;
void BuildFail()
{
    L=1;
    for(int i=0;i<26;++i)if(t[0].son[i])Q[++R]=t[0].son[i];
    while(L<=R)
    {
        int u=Q[L++];t[u].w+=t[t[u].ff].w;t[u].s+=t[t[u].ff].s;
        for(int i=0;i<26;++i)
            if(t[u].son[i])t[t[u].son[i]].ff=t[t[u].ff].son[i],Q[++R]=t[u].son[i];
            else t[u].son[i]=t[t[u].ff].son[i];
    }
}
char T[MAX],S[MAX];int n,m;
int f[MAX][MAX];int g1[MAX][MAX],g2[MAX][MAX];
void Tr(int i,int j,int k)
{
    int v=t[j].son[k];
    if(f[i][v]<f[i-1][j]+t[v].w)
    {
        f[i][v]=f[i-1][j]+t[v].w;
        g1[i][v]=j;g2[i][v]=k;
    }
}
int check(int K)
{
    for(int i=0;i<=tot;++i)t[i].w-=K*t[i].s;
    int len=strlen(T+1);
    for(int i=0;i<=len;++i)
        for(int j=0;j<=tot;++j)f[i][j]=-12345;
    f[0][0]=0;
    for(int i=1;i<=len;++i)
        for(int j=0;j<=tot;++j)
        {
        	if(T[i]=='*')for(int k=0;k<26;++k)Tr(i,j,k);
                else Tr(i,j,T[i]-'a');
		}
                
    int ans=-12345;
    for(int i=0;i<=tot;++i)ans=max(ans,f[len][i]);
    return ans;
}
int main()
{
    m=2;
    scanf("%s",T+1);n=strlen(T+1);
    scanf("%s",S+1),Insert(S,1);
    scanf("%s",S+1),Insert(S,-1);
    BuildFail();
    cout<<check(0);
    return 0;
}