#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar()
#define mypc(c) putchar(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}


template<class T> void* setUndirectEdge(int N, int M, int A[], int B[], T C[], int **es, int ***edge, T ***cost, void *workMemory){int i;*es=(int*)workMemory;*edge=(int**)((*es)+N);(*edge)[0]=(int*)((*edge)+N);rep(i,N)(*es)[i]=0;rep(i,M)(*es)[A[i]]++,(*es)[B[i]]++;REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];(*cost)=(T**)((*edge)[N-1]+(*es)[N-1]);(*cost)[0]=(T*)((*cost)+N);REP(i,1,N)(*cost)[i]=(*cost)[i-1]+(*es)[i-1];workMemory=(void*)((*cost)[N-1]+(*es)[N-1]);rep(i,N)(*es)[i]=0;rep(i,M)(*edge)[A[i]][(*es)[A[i]]]=B[i],(*cost)[A[i]][(*es)[A[i]]++]=C[i],(*edge)[B[i]][(*es)[B[i]]]=A[i],(*cost)[B[i]][(*es)[B[i]]++]=C[i];return workMemory;}
void getDist(int N, int root, int *es, int **edge, int dist[], void *mem){int i,j,k,*q,s,z;q=(int*)mem;rep(i,N)dist[i]=-1;dist[root]=0;s=0;z=1;q[0]=root;while(z){i=q[s++];z--;rep(j,es[i]){k=edge[i][j];if(dist[k]>=0)continue;dist[k]=dist[i]+1;q[s+z++]=k;}}}

template<class T> void doublingRMQBuild(T arr[], int n, int res[]){int i,k,h;rep(i,n)res[i]=i;for(k=1;;k++){h=(1<<(k-1));if(h>=n)break;rep(i,n){res[n*k+i]=res[n*(k-1)+i];if(i+h<n&&arr[res[n*k+i]]>arr[res[n*(k-1)+i+h]])res[n*k+i]=res[n*(k-1)+i+h];}}}
template<class T> void* doublingRMQBuild(T arr[], int n, int **res, void *workMemory){int i,k,h;*res=(int*)workMemory;rep(i,n)(*res)[i]=i;for(k=1;;k++){h=(1<<(k-1));if(h>=n)break;rep(i,n){(*res)[n*k+i]=(*res)[n*(k-1)+i];if(i+h<n&&arr[(*res)[n*k+i]]>arr[(*res)[n*(k-1)+i+h]])(*res)[n*k+i]=(*res)[n*(k-1)+i+h];}}return (void*)((*res)+n*k);}
template<class T> int doublingRMQQuery(T arr[], int n, int rmq[], int a, int b){int d,w=b-a+1,A,B;for(d=0;(1<<(d+1))<=w;d++);A=rmq[n*d+a];B=rmq[n*d+b-(1<<d)+1];return arr[A]>arr[B]?B:A;}
struct LCA{
  int *depth, *vs, *id, *rmq, N, *es, **edge;
  void dfs(int node, int bef, int dep, int *num){int i,k;id[node]=*num;vs[*num]=node;depth[(*num)++]=dep;rep(i,es[node]){k=edge[node][i];if(k==bef)continue;dfs(k,node,dep+1,num);vs[*num]=node;depth[(*num)++]=dep;}}
  void* init(int N_, int root, int *es_, int **edge_, void *workMemory){int m=0;N=N_;es=es_;edge=edge_;depth=(int*)workMemory;vs=depth+2*N-1;id=vs+2*N-1;dfs(root,-1,0,&m);return doublingRMQBuild(depth,2*N-1,&rmq,(void*)(id+N));}
  int get(int a, int b){return vs[doublingRMQQuery(depth,2*N-1,rmq,min(id[a],id[b]),max(id[a],id[b]))];}
  int getDepth(int a, int b){return depth[doublingRMQQuery(depth,2*N-1,rmq,min(id[a],id[b]),max(id[a],id[b]))];}
};

template<class T>
struct ullHash{
  ull *key; T *val; unsigned memory, size, mask;

  void clear(){memset(val,0,size*sizeof(T));}
  void clear(int sz){size=1;while(size<sz)size*=2;mask=size-1;clear();}
  void init(int mem, int sz){memory=mem;size=1;while(size<sz)size*=2;mask=size-1;if(memory<size)memory=size;key=(ull*)malloc(memory*sizeof(ull));val=(T*)malloc(memory*sizeof(T));if(size)clear();}
  int function(ull a){return (((a*123456789789ULL)>>32)*987654321321ULL)&mask;}
  T get(ull a){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;if(key[i]!=a) return 0;return val[i];}
  void set(ull a, T v){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;val[i]=v;}
  T increase(ull a, T v = 1){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;return val[i]+=v;}
};


char memarr[137000000]; void *mem = memarr;
#define MD 1000000007

int N, Q;
int A[110000], B[110000], C[110000];
int up2[20][110000];

int *es, **edge, **dp;
int depth[110000];

int dfs(int now, int bef){
  int i, j, k, ind;
  int sum = 1;
  int up = N-1;

  up2[0][now] = bef;
  REP(i,1,20){
    if(up2[i-1][now]==-1){ up2[i][now] = -1; continue; }
    up2[i][now] = up2[i-1][up2[i-1][now]];
  }

  rep(i,es[now]){
    k = edge[now][i];
    if(k==bef){ ind = i; continue; }
    sum += dp[now][i] = dfs(k, now);
  }
  if(bef != -1){
    dp[now][ind] = N - sum;
  }
  return sum;
}

int get_up(int a, int n){
  int i, j, k;
  rep(i,20) if(n&(1<<i)){
    a = up2[i][a];
  }
  return a;
}

int main(){
  int i, j, k;
  int x, y, z, d1, d2, dis;
  int cen, e1, e2;
  int res;
  LCA lca;
  ullHash<int> hash;

  hash.init(150000, 150000);

  reader(&N);
  rep(i,N-1) reader(A+i,B+i), A[i]--, B[i]--;

  mem = setUndirectEdge(N,N-1,A,B,C,&es,&edge,&dp,mem);
  mem = lca.init(N, 0, es, edge, mem);
  getDist(N, 0, es, edge, depth, mem);
  dfs(0,-1);

  rep(i,N) rep(j,es[i]){
    hash.set((ll)i*N + edge[i][j], j+1);
  }

  reader(&Q);
  while(Q--){
    reader(&x, &y); x--; y--;
    if(x==y){ writerLn(N); continue; }
    z = lca.get(x,y);
    d1 = depth[x] - depth[z];
    d2 = depth[y] - depth[z];

    if( (d1+d2)%2==1 ){ writerLn(0); continue; }
    dis = (d1+d2) / 2;
    
    if(d1==d2){
      cen = z;
      e1 = get_up(x,dis-1);
      e2 = get_up(y,dis-1);
    } else if(d1 > d2){
      cen = get_up(x, dis);
      e1 = get_up(x, dis-1);
      e2 = get_up(x, dis+1);
    } else {
      cen = get_up(y, dis);
      e1 = get_up(y, dis-1);
      e2 = get_up(y, dis+1);
    }

    res = N;
    i = hash.get((ll)cen*N+e1)-1;
    res -= dp[cen][i];
    i = hash.get((ll)cen*N+e2)-1;
    res -= dp[cen][i];
    writerLn(res);
  }

  return 0;
}