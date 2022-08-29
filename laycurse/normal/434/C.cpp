#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define READER_BUF_SIZE 1048576
#define WRITER_BUF_SIZE 1048576
int reader_pt=READER_BUF_SIZE,reader_last;char reader_buf[READER_BUF_SIZE];
int writer_pt=0;char writer_buf[WRITER_BUF_SIZE];
#define mygc(c) {if(reader_pt==READER_BUF_SIZE)reader_pt=0,reader_last=fread(reader_buf,sizeof(char),READER_BUF_SIZE,stdin);(c)=reader_buf[reader_pt++];}
#define mypc(c) {if(writer_pt==WRITER_BUF_SIZE)writer_pt=0,fwrite(writer_buf,sizeof(char),WRITER_BUF_SIZE,stdout);writer_buf[writer_pt++]=(c);}
#define myed {fwrite(writer_buf,sizeof(char),writer_pt,stdout);writer_pt=0;}

#define ll long long
#define MD 1000000007

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(ll x, char c){int i,sz=0,m=0;char buf[20];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

int M, N, K;
int Ls, L[210];
int Rs, R[210];
int V[210], Ss[210], S[210][210];

int node;
int st1[400], st2[400];
int edge[400][210], cost[400][210];

ll dp[400][2][501], nx[400][2][501];

int solve(int n, int A[]){
  int i, j, k, d, z;
  ll res = 0;

  rep(i,node) rep(j,2) rep(k,K+1) dp[i][j][k] = 0;
  dp[0][1][0] = 1;

  rep(d,n){
    rep(i,node) rep(j,2) rep(k,K+1) nx[i][j][k] = 0;

    rep(i,node) rep(k,K+1) if(dp[i][0][k]){
      rep(z,M) if(k+cost[i][z]<=K) nx[edge[i][z]][0][k+cost[i][z]] += dp[i][0][k];
    }
    
    rep(i,node) rep(k,K+1) if(dp[i][1][k]){
      rep(z,A[d]) if(k+cost[i][z]<=K) nx[edge[i][z]][0][k+cost[i][z]] += dp[i][1][k];
      if(k+cost[i][z]<=K) nx[edge[i][z]][1][k+cost[i][z]] += dp[i][1][k];
    }
    
    rep(i,node) rep(j,2) rep(k,K+1){
      dp[i][j][k] = nx[i][j][k];
      if(dp[i][j][k] >= MD) dp[i][j][k] %= MD;
    }
  }

  rep(i,node) rep(j,2) rep(k,K+1) res += dp[i][j][k];
  res %= MD;
  return res;
}

int get_node(int s1, int s2){
  int i;
  REP(i,1,node) if(s1==st1[i] && s2==st2[i]) return i;
  st1[node] = s1;
  st2[node] = s2;
  return node++;
}

int main(){
  int i, j, k;
  int x, y, mx, my;
  int arr[210];
  ll res;

  reader(&N, &M, &K);
  reader(&Ls); rep(i,Ls) reader(L+i);
  reader(&Rs); rep(i,Rs) reader(R+i);
  rep(i,N){
    reader(Ss+i);
    rep(j,Ss[i]) reader(S[i]+j);
    reader(V+i);
  }

  node = 2;
  st1[0] = st2[0] = 0;
  st1[1] = st2[1] = 0;
  rep(k,node){
    rep(i,st2[k]) arr[i] = S[st1[k]][i];
    rep(i,M){
      
      if(i==0 && k==0){
        edge[k][i] = 0;
        cost[k][i] = 0;
        continue;
      }
      cost[k][i] = 0;
      arr[st2[k]] = i;
      mx = my = 0;
      rep(x,N){
        for(y=min(st2[k]+1, Ss[x]);y;y--){
          if(y!=Ss[x] && y<=my) continue;

          rep(j,y) if(S[x][j]!=arr[st2[k]-y+1+j]) break;
          if(j != y) continue;
          if(y==Ss[x]){ cost[k][i]+=V[x]; continue; }
          if(y > my){
            mx = x; my = y;
            break;
          }
        }
      }
      edge[k][i] = get_node(mx, my);
    }
  }

//  printf("%d\n",node);
//  rep(i,node){ rep(j,M) printf("%d -> %d (str %d, cost %d)\n",i,edge[i][j],j,cost[i][j]); }

  L[Ls-1]--;
  for(i=Ls-1;i;i--) if(L[i]<0){
    L[i] += M;
    L[i-1]--;
  }

//  printf("%d %d\n",solve(Rs, R),solve(Ls, L)); return 0;
  res = solve(Rs, R) - solve(Ls, L);
  res %= MD;
  if(res < 0) res += MD;
  writer((int)res,'\n');
  
  myed;
  return 0;
}