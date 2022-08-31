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
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

#define MD 1000000007

void* setDirectEdge(int N, int M, int A[], int B[], int **es, int ***edge, void *workMemory){int i;*es=(int*)workMemory;*edge=(int**)((*es)+N);(*edge)[0]=(int*)((*edge)+N);rep(i,N)(*es)[i]=0;rep(i,M)(*es)[A[i]]++;REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];workMemory=(void*)((*edge)[N-1]+(*es)[N-1]);rep(i,N)(*es)[i]=0;rep(i,M)(*edge)[A[i]][(*es)[A[i]]++]=B[i];return workMemory;}
void* getReverseGraph(int N, int *es, int **edge, int **r_es, int ***r_edge, void *workMemory){int i,j,k;*r_es=(int*)workMemory;*r_edge=(int**)((*r_es)+N);(*r_edge)[0]=(int*)((*r_edge)+N);rep(i,N)(*r_es)[i] = 0;rep(i,N)rep(j,es[i])(*r_es)[edge[i][j]]++;REP(i,1,N)(*r_edge)[i]=(*r_edge)[i-1]+(*r_es)[i-1];workMemory=(void*)((*r_edge)[N-1]+(*r_es)[N-1]);rep(i,N)(*r_es)[i]=0;rep(i,N)rep(j,es[i])k=edge[i][j],(*r_edge)[k][(*r_es)[k]++]=i;return workMemory;}

int StronglyConnectedComponentsDFS(int *es, int **edge, int num[], int st, int mx){int i,j;num[st]=-2;rep(i,es[st]){j=edge[st][i];if(num[j]==-1)mx=StronglyConnectedComponentsDFS(es,edge,num,j,mx);}num[st]=mx;return mx+1;}
int StronglyConnectedComponents(int N, int *es, int **edge, int res[], void *workMemory){int i,j,k,t=0,*s,**e,*q,z,*n,*r;workMemory=getReverseGraph(N,es,edge,&s,&e,workMemory);q=(int*)workMemory;n=q+N;r=n+N;rep(i,N)res[i]=n[i]=-1;k=0;rep(i,N)if(n[i]==-1)k=StronglyConnectedComponentsDFS(es,edge,n,i,k);rep(i,N)r[n[i]]=i;for(k=N-1;k>=0;k--){i=r[k];if(res[i]>=0)continue;res[i]=t;z=0;q[z++]=i;while(z){i=q[--z];rep(j,s[i])if(res[e[i][j]]==-1)res[e[i][j]]=t,q[z++]=e[i][j];}t++;}return t;}

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}


int N, M;
int A[111111], B[111111];
int *es, **edge;
int cp[111111], nn;
int sz[111111];

int ind[111111];
int tot[111111], mxsz[111111];

int main(){
  int i, j, k, con;
  int res = 0;
  void *mem = malloc(117000000);

  reader(&N,&M);
  rep(i,M) reader(A+i,B+i), A[i]--, B[i]--;

  mem = setDirectEdge(N, M, A, B, &es, &edge, mem);
  nn = StronglyConnectedComponents(N, es, edge, cp, mem);

  unionInit(ind, nn);
  con = nn;
  
  rep(i,N) sz[cp[i]]++;
  rep(i,M){
    A[i] = cp[A[i]];
    B[i] = cp[B[i]];
    if(A[i]==B[i]) continue;
    unionConnect(ind, A[i], B[i]);
  }

  rep(i,nn){
    k = unionGet(ind, i);
    tot[k] += sz[i];
    mxsz[k] = max(mxsz[k], sz[i]);
  }

  rep(i,nn) if(tot[i]){
    res += tot[i];
    if(mxsz[i]==1) res--;
  }

  writerLn(res);

  myed;
  return 0;
}