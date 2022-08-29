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

template<class T> void sort(int N, T a[], void *mem = NULL){sort(a,a+N);}
template<class T1, class T2> void sort(int N, T1 a[], T2 b[], void *mem){int i;pair<T1,T2> *r=(pair<T1, T2>*)mem;rep(i,N)r[i].first=a[i],r[i].second=b[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second;}
template<class T1, class T2, class T3> void sort(int N, T1 a[], T2 b[], T3 c[], void *mem){int i;pair<T1,pair<T2,T3> > *r=(pair<T1,pair<T2,T3> >*)mem;rep(i,N)r[i].first=a[i],r[i].second.first=b[i],r[i].second.second=c[i];sort(r,r+N);rep(i,N)a[i]=r[i].first,b[i]=r[i].second.first,c[i]=r[i].second.second;}
template<class T1, class T2, class T3, class T4> void sort(int N, T1 a[], T2 b[], T3 c[], T4 d[], void *mem){int i;pair<pair<T1,T2>,pair<T3,T4> > *r=(pair<pair<T1,T2>,pair<T3,T4> >*)mem;rep(i,N)r[i].first.first=a[i],r[i].first.second=b[i],r[i].second.first=c[i],r[i].second.second=d[i];sort(r,r+N);rep(i,N)a[i]=r[i].first.first,b[i]=r[i].first.second,c[i]=r[i].second.first,d[i]=r[i].second.second;}

template<class T> void* doublingRMQBuild(T arr[], int n, int **res, void *workMemory){int i,k,h;*res=(int*)workMemory;rep(i,n)(*res)[i]=i;for(k=1;;k++){h=(1<<(k-1));if(h>=n)break;rep(i,n){(*res)[n*k+i]=(*res)[n*(k-1)+i];if(i+h<n&&arr[(*res)[n*k+i]]>arr[(*res)[n*(k-1)+i+h]])(*res)[n*k+i]=(*res)[n*(k-1)+i+h];}}return (void*)((*res)+n*k);}
template<class T> int doublingRMQQuery(T arr[], int n, int rmq[], int a, int b){int d,w=b-a+1,A,B;for(d=0;(1<<(d+1))<=w;d++);A=rmq[n*d+a];B=rmq[n*d+b-(1<<d)+1];return arr[A]>arr[B]?B:A;}

int N, Q;
int P[222222], L[222222];
int X[222222], Y[222222], ind[222222];
ll res[222222];

int go[222222]; ll cost[222222];

int reach[222222], *rmq;

ll solve(int x, int y){
  int i, j, k;
  ll tmp;
  int p;

  if(go[x] >= y) return cost[x];
  
  k = doublingRMQQuery(reach, N, rmq, x, go[x]);
  p = -reach[k];

  tmp = solve(go[x]+1, y);
  cost[x] += (P[go[x]+1] - p) + tmp;
  go[x] = go[go[x]+1];

  return cost[x];
}

int main(){
  int i, j, k;
  int x, p;
  void *mem = malloc(150000000);

  reader(&N);
  rep(i,N) reader(P+i,L+i); P[N] = 2100000000;
  reader(&Q);
  rep(i,Q) reader(X+i,Y+i), X[i]--, Y[i]--, ind[i] = i;
  sort(Q, Y, X, ind, mem);

  rep(i,N) reach[i] = -(P[i] + L[i]);
  mem = doublingRMQBuild(reach, N, &rmq, mem);
  
  rep(i,N) cost[i] = 0, go[i] = i;
  
  rep(x,N){
    p = -reach[x];
    for(;;){
      j = upper_bound(P, P+N+1, p) - P - 1;
      if(j == go[x]) break;

      go[x] = j;
      k = doublingRMQQuery(reach, N, rmq, x, go[x]);
      p = -reach[k];
    }
  }
  
  rep(i,Q){
    res[ind[i]] = solve(X[i], Y[i]);
  }
  rep(i,Q) writerLn(res[i]);

  myed;
  return 0;
}