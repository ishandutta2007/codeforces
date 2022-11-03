#include <bits/stdc++.h>
using namespace std;
const int maxn=205;
const int maxv=maxn*2;
const int maxm=maxn*maxn*4;
const int maxe=maxm*2+maxn*2;
const int maxsz=30;
char s[maxm];
int l,n,m,p[maxm][2],suf[maxsz][2];
int tot,he[maxv],ne[maxe],to[maxe],dfn[maxv],low[maxv],clk,sc[maxv],sta[maxv],top;
bool ty[maxsz],ok[maxn][2],t[maxm][2],ins[maxv];
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++/*,printf("add edge (%d,%d) (%d,%d)\n",u>>1,u&1,v>>1,v&1)*/; }
void dfs(int u)
{
    int i;
    dfn[u]=low[u]=clk++,sta[++top]=u,ins[u]=1;
    for(i=he[u];~i;i=ne[i])
        if(dfn[to[i]]==-1) dfs(to[i]),low[u]=min(low[u],low[to[i]]);
        else if(ins[to[i]]) low[u]=min(low[u],dfn[to[i]]);
    if(dfn[u]==low[u])
    {
        do sc[sta[top]]=tot,ins[sta[top]]=0,top--; while(sta[top+1]!=u);
        tot++;
    }
}
inline bool check()
{
    int i;
    for(i=0,tot=0;i<(n<<1);i++) he[i]=-1,dfn[i]=-1,ins[i]=0;
    for(i=0;i<n;i++)
    {
        if(!ok[i][0] || suf[0][0]==-1) add_edge(i<<1,(i<<1)|1);
        if(!ok[i][1] || suf[0][1]==-1) add_edge((i<<1)|1,i<<1);
    }
    for(i=0;i<m;i++)
    {
        add_edge((p[i][0]<<1)|t[i][0],(p[i][1]<<1)|t[i][1]);
        add_edge((p[i][1]<<1)|(t[i][1]^1),(p[i][0]<<1)|(t[i][0]^1));
    }
    for(tot=0,clk=0,i=0,top=-1;i<(n<<1);i++)
        if(dfn[i]==-1)
            dfs(i);
    for(i=0;i<(n<<1);i+=2)
        if(sc[i]==sc[i|1])
            return 0;
    return 1;
}
int main()
{
    int i,j;
    scanf("%s%d%d",s,&n,&m),l=strlen(s);
    for(i=0;i<l;i++) ty[i]=(s[i]=='V');
    for(suf[l][0]=suf[l][1]=-1,i=l-1;i>=0;i--)
        suf[i][ty[i]]=i,suf[i][ty[i]^1]=suf[i+1][ty[i]^1];
    for(i=0;i<m;i++)
    {
        scanf("%d%s",&p[i][0],s),t[i][0]=(s[0]=='V'),p[i][0]--;
        scanf("%d%s",&p[i][1],s),t[i][1]=(s[0]=='V'),p[i][1]--;
    }
    scanf("%s",s);
    for(i=n;i>=0;i--)
    {
        for(j=0;j<n;j++)
            if(j<i) ok[j][ty[s[j]-'a']^1]=0,ok[j][ty[s[j]-'a']]=1;//add_edge((j<<1)|(ty[j]^1),(j<<1)|ty[j]);
//            else
//                if(suf[0][(j==i+1)?s[j]-'a'+1:0]==-1) add_edge(j<<1,(j<<1)|1);
//                if(suf[1][(j==i+1)?s[j]-'a'+1:0]==-1) add_edge((j<<1)|1,j<<1);
//            ok[j][0]=(suf[0][(j==i+1)?s[j]-'a'+1:0]>=0),ok[j][1]=(suf[1][(j==i+1)?s[j]-'a'+1:0]>=0)
            else if(j==i) ok[j][0]=(suf[s[j]-'a'+1][0]>=0),ok[j][1]=(suf[s[j]-'a'+1][1]>=0);
            else ok[j][0]=ok[j][1]=1;
        if(check()) break;
    }
    if(i<0) { printf("-1\n"); return 0; }
    for(j=0;j<i;j++) printf("%c",s[j]);
    for(j=i;j<n;j++) ok[j][0]=ok[j][1]=1;
    for(j=i;i<n;i++)
    {
        ok[i][ty[(i==j)?s[j]-'a'+1:0]^1]=0;
        if(check()) printf("%c",(i==j)?s[j]+1:'a');
        else
        {
            ok[i][ty[(i==j)?s[j]-'a'+1:0]^1]=1,ok[i][ty[(i==j)?s[j]-'a'+1:0]]=0;
            printf("%c",suf[(i==j)?s[j]-'a'+1:0][ty[(i==j)?s[j]-'a'+1:0]^1]+'a');
        }
    }
    printf("\n");
    return 0;
}