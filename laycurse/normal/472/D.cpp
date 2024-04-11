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
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(int *x, int *y){reader(x);reader(y);}
void reader(int *x, int *y, int *z){reader(x);reader(y);reader(z);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int N;
int dist[2001][2001];
ll val[2700000];

int ind[2001];
int edge[2001][2001], cost[2001][2001], es[2001];


ll d[2001];
void dfs(int node, int bef, ll dis){
  int i, j, k;

  d[node] = dis;

  rep(k,es[node]){
    i = edge[node][k];
    if(i==bef) continue;
    dfs(i, node, dis + cost[node][k]);
  }
}

int solve(void){
  int i, j, k;
  int a, b, c;

  rep(i,N) if(dist[i][i] != 0) return 0;
  rep(i,N) REP(j,i+1,N){
    if(dist[i][j] != dist[j][i]) return 0;
    if(dist[i][j]==0) return 0;
  }

  k = 0;
  rep(i,N) REP(j,i+1,N){
    val[k++] = (((ll)dist[i][j]) << 32) + i * N + j;
  }
  sort(val, val+k);

  unionInit(ind, N);
  
  rep(i,N) es[i] = 0;
  rep(i,k){
    c = val[i] >> 32;
    val[i] -= ((ll)c) << 32;
    a = val[i] / N;
    b = val[i] % N;

    if(unionConnect(ind,a,b)==1){
      edge[a][es[a]] = b; cost[a][es[a]++] = c;
      edge[b][es[b]] = a; cost[b][es[b]++] = c;
    }
  }

  rep(i,N){
    dfs(i, -1, 0);
    rep(j,N) if(d[j] != dist[i][j]) return 0;
  }

  return 1;
}

int main(){
  int i, j, k;

  reader(&N);
  rep(i,N) rep(j,N) reader(dist[i]+j);

  if(solve()) writer("YES\n"); else writer("NO\n");

  myed;
  return 0;
}