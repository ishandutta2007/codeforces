#include<bits/stdc++.h>
#define ll long long
template<class T> inline void read(T &x){
    x=0;register char c=getchar();register bool f=0;
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
const int N=110,M=11000,P=410;
char s[N][N];
std::vector<int> G[M];
int n,m,cnt,nod,mod,fl0,fl1,res,fa[M],fl[M],vis[M],id[N][N],mat[P][P];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int finv(int x){return x<2?1:(ll)(mod-mod/x)*finv(mod%x)%mod;}
inline void add(int u,int v){
    G[u].push_back(v),G[v].push_back(u);
}
bool check(bool cur){
    std::queue<int>q;q.push(cur?2:1),vis[cur?2:1]=1;
    while(q.size()){
        int u=q.front();q.pop();
        for(int v:G[u])if(!vis[v])vis[v]=1,q.push(v);
    }
    for(int i=1;i<=cnt;i++)if(fl[i]==cur&&!vis[i])return 0;
    return 1;
}
int gauss(int a[P][P],int n){
    int res=1;
    for(int i=1,j;i<=n;i++){
        for(j=i;j<=n;j++)if(a[j][i])break;
        if(j>n)return 0;if(i!=j)res=mod-res,std::swap(a[i],a[j]);
        res=(ll)res*a[i][i]%mod;
        for(int d,j=i+1;j<=n;j++){
            d=(ll)finv(a[i][i])*(mod-a[j][i])%mod;
            for(int k=i;k<=n;k++)a[j][k]=(a[j][k]+(ll)a[i][k]*d)%mod;
        }
    }
    return res%mod;
}
int calc(int cur){
    std::map<int,int> map;nod=0;
    for(int i=1;i<=cnt;i++)if(fl[i]==cur)map[find(i)]=0;
    for(auto &it:map)it.second=++nod;
    for(int i=1;i<=nod;i++)for(int j=1;j<=nod;j++)mat[i][j]=0;
    for(int i=1;i<=cnt;i++)if(fl[i]==cur)fa[i]=map[fa[i]];
    // printf("calc %d => %d\n",cur,nod);
    // for(int i=1;i<=cnt;i++)if(fl[i]==cur)printf("%d%c",fa[i],' ');puts("");
    for(int u=1;u<=cnt;u++)if(fl[u]==cur)
        for(auto v:G[u])if(u<v&&fa[u]!=fa[v]){
            mat[fa[u]][fa[v]]--,mat[fa[v]][fa[u]]--;
            mat[fa[u]][fa[u]]++,mat[fa[v]][fa[v]]++;
        }
    // for(int i=1;i<=nod;i++)for(int j=1;j<=nod;j++)printf("%d%c",mat[i][j]," \n"[j==nod]);
    for(int i=1;i<=nod;i++)for(int j=1;j<=nod;j++)if(i!=j)mat[i][j]=mod+mat[i][j];
    return gauss(mat,nod-1);
}
int main(){
#ifdef memset0
    freopen("1.in","r",stdin);
#endif	
    scanf("%d%d%d",&n,&m,&mod);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=m+1;j++)id[i][j]=++cnt,fl[cnt]=(i+j)&1,fa[cnt]=cnt;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(s[i][j]=='*'){
                add(id[i][j],id[i+1][j+1]);
                add(id[i+1][j],id[i][j+1]);
            }else if(s[i][j]=='\\'){
                add(id[i][j],id[i+1][j+1]);
                fa[find(id[i][j])]=find(id[i+1][j+1]);
            }else if(s[i][j]=='/'){
                add(id[i+1][j],id[i][j+1]);
                fa[find(id[i+1][j])]=find(id[i][j+1]);
            }
    fl0=check(0),fl1=check(1);
    res=((fl0?calc(0):0)+(fl1?calc(1):0))%mod;
    printf("%d\n",res);
}