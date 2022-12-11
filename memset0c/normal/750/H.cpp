#include<bits/stdc++.h>
const int N=1e3+10,mov[8][2]={{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{-1,0},{0,1},{0,-1}};
int n,m,q,k,cnt,flag,x[10],y[10],f[10],tanc[100],anc[N*N];
char str[N];
bool a[N][N];
std::set<int> pre[N*N];
std::map<int,int> map;
inline int id(int i,int j){return i*(m+2)+j;}
inline int find(int x){return anc[x]==x?x:anc[x]=find(anc[x]);}
inline int findt(int x){return tanc[x]==x?x:tanc[x]=findt(tanc[x]);}
inline void merge(int u,int v){anc[find(u)]=find(v);}
inline void merget(int u,int v){tanc[findt(u)]=findt(v);}
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&q);
  for(int i=1;i<=n;i++){
    scanf("%s",str+1);
    for(int j=1;j<=m;j++)a[i][j]=str[j]=='#';
  }
  for(int i=0;i<=n+1;i++)
    for(int j=0;j<=m+1;j++)
      anc[id(i,j)]=id(i,j);
  anc[id(0,1)]=anc[id(n,m+1)]=-1;
  anc[id(1,0)]=anc[id(n+1,m)]=-1;
  anc[id(0,0)]=anc[id(n+1,m+1)]=-1;
  a[n+1][0]=a[0][m+1]=true;
  for(int i=2;i<=n;i++)a[i][0]=true,merge(id(i,0),id(i+1,0));
  for(int i=1;i<n;i++)a[i][m+1]=true,merge(id(i,m+1),id(i-1,m+1));
  for(int i=2;i<=m;i++)a[0][i]=true,merge(id(0,i),id(0,i+1));
  for(int i=1;i<m;i++)a[n+1][i]=true,merge(id(n+1,i),id(n+1,i-1));
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)if(a[i][j])
      for(int k=0;k<8;k++)if(a[i+mov[k][0]][j+mov[k][1]])
        merge(id(i,j),id(i+mov[k][0],j+mov[k][1]));
  for(int i=0;i<=n+1;i++)
    for(int j=0;j<=m+1;j++)if(~anc[id(i,j)]){
      find(id(i,j));
      // printf("anc[%d,%d] = %d\n",i,j,anc[id(i,j)]);
    }
  int S=anc[id(0,2)],T=anc[id(2,0)];
  auto solve=[&]{
    if(S==T)return true;
    for(int i=0;i<=n+1;i++)
      for(int j=0;j<=m+1;j++)if(anc[id(i,j)]==S||anc[id(i,j)]==T){
        for(int p=0;p<8;p++){
          if(i+mov[p][0]==1&&j+mov[p][1]==1)continue;
          if(i+mov[p][0]==n&&j+mov[p][1]==m)continue;
          for(int q=0;q<8;q++){
            int u=i+mov[p][0]+mov[q][0];
            int v=j+mov[p][1]+mov[q][1];
            if(u<0||v<0||u>n+1||v>m+1)continue;
            if(anc[id(i,j)]==S&&anc[id(u,v)]==T)return true;
            if(anc[id(i,j)]==T&&anc[id(u,v)]==S)return true;
          }
        }
      }
    return false;
  };
  if(solve()){
    fprintf(stderr,"no solution at all!\n");
    flag=true;
  }else{
    for(int i=0;i<=n+1;i++)
      for(int j=0;j<=m+1;j++)if(~anc[id(i,j)]&&a[i][j]){
        for(int p=0;p<8;p++){
          if(i+mov[p][0]==1&&j+mov[p][1]==1)continue;
          if(i+mov[p][0]==n&&j+mov[p][1]==m)continue;
          for(int q=0;q<8;q++){
            int u=i+mov[p][0]+mov[q][0];
            int v=j+mov[p][1]+mov[q][1];
            if(u<0||v<0||u>n+1||v>m+1)continue;
            if(~anc[id(u,v)]&&a[u][v]){
              if(anc[id(i,j)]!=anc[id(u,v)])pre[anc[id(i,j)]].insert(anc[id(u,v)]);
            }
          }
        }
      }
  }
  for(int i=1;i<=q;i++){
    scanf("%d",&k);
    for(int i=0;i<k;i++)scanf("%d%d",&x[i],&y[i]);
    auto solve=[&]{
      if(flag)return true;
      map.clear(),cnt=0;
      map[S]=map[T]=true;
      for(int i=0;i<k;i++){
        a[x[i]][y[i]]=true;
        map[anc[id(x[i],y[i])]]=true;
        for(int k=0;k<8;k++)if(a[x[i]+mov[k][0]][y[i]+mov[k][1]])
          map[anc[id(x[i]+mov[k][0],y[i]+mov[k][1])]]=true;
      }
      for(auto &it:map)it.second=cnt++;
      assert(cnt<100);
      for(int i=0;i<cnt;i++)tanc[i]=i;
      for(int i=0;i<k;i++)
        for(int k=0;k<8;k++)if(a[x[i]+mov[k][0]][y[i]+mov[k][1]])
          merget(map[anc[id(x[i],y[i])]],map[anc[id(x[i]+mov[k][0],y[i]+mov[k][1])]]);
      int s=findt(map[S]),t=findt(map[T]);
      if(s==t)return true;
      for(int i=0;i<k;i++)f[i]=findt(map[anc[id(x[i],y[i])]]);
      for(int i=0;i<k;i++)if(f[i]==s||f[i]==t){
        for(int p=0;p<8;p++){
          if(x[i]+mov[p][0]==1&&y[i]+mov[p][1]==1)continue;
          if(x[i]+mov[p][0]==n&&y[i]+mov[p][1]==m)continue;
          for(int q=0;q<8;q++){
            int u=x[i]+mov[p][0]+mov[q][0];
            int v=y[i]+mov[p][1]+mov[q][1];
            if(u<0||v<0||u>n+1||v>m+1||!~anc[id(u,v)]||!a[u][v])continue;
            int p=anc[id(u,v)];
            if(f[i]==s&&(p==T||(map.count(p)&&t==findt(map[p]))))return true;
            if(f[i]==t&&(p==S||(map.count(p)&&s==findt(map[p]))))return true;
          }
        }
      }
      for(const auto &x:map)if(findt(x.second)==s)
        for(const auto &y:map)if(findt(y.second)==t)
          if(pre[x.first].count(y.first)){
            return true;
          }
      return false;
    };
    puts(solve()?"NO":"YES"),fflush(stdout);
    for(int i=0;i<k;i++)a[x[i]][y[i]]=false;
  }
}