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

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

template<class T>
struct ullHash{
  ull *key; T *val; unsigned memory, size, mask;

  void clear(){memset(val,0,size*sizeof(T));}
  void clear(int sz){size=1;while(size<sz)size*=2;mask=size-1;clear();}
  void init(int mem, int sz){memory=mem;size=1;while(size<sz)size*=2;mask=size-1;if(memory<size)memory=size;key=(ull*)malloc(memory*sizeof(ull));val=(T*)malloc(memory*sizeof(T));if(size)clear();}
  int function(ull a){return (a*97531)&mask;}
  T get(ull a){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;if(key[i]!=a) return 0;return val[i];}
  void set(ull a, T v){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;val[i]=v;}
  T increase(ull a, T v = 1){int i=function(a);for(;key[i]!=a&&val[i]!=0;)i=(i+1)&mask;key[i]=a;return val[i]+=v;}
};


int N, M;
int A[111111], B[111111], C[111111];

int Q, X[111111], Y[111111], qi[111111], ign[111111];
int res[111111];

vector<int> node[111111];
int ind[111111];

int main(){
  int i, j, k;
  int a, b, x, y, s, t, q;
  int st, ed, sz;
  void *mem = malloc(77000000);
  ullHash<int> hs;

  hs.init(200000, 200000);

  if(1){
    reader(&N,&M);
    rep(i,M) reader(A+i,B+i,C+i), A[i]--, B[i]--, C[i]--;
    reader(&Q);
    rep(i,Q) reader(X+i,Y+i), X[i]--, Y[i]--;
  } else {
    N = M = 100000;
    Q = 100000;

    k = 0;
    for(a=0;k<M;a++) rep(i,99) if(k < M){
      A[k] = i;
      B[k] = i+1;
      C[k] = a;
      k++;
    }
    k = 0;
    for(i=0;k<Q;i++) if(k < Q) rep(j,i) if(k < Q){
      X[k] = i;
      Y[k] = j;
      k++;
    }
  }

  sort(M, C, A, B, mem);

  rep(i,Q) if(X[i] > Y[i]) swap(X[i], Y[i]);
  rep(i,Q) qi[i] = i;
  sort(Q, X, Y, qi, mem);

  rep(i,Q){
    ign[i] = 0;
    if(i && X[i]==X[i-1] && Y[i]==Y[i-1]) ign[i]=1;
  }
  rep(i,Q) if(!ign[i]) hs.set(X[i] * N + Y[i], i+1);

  unionInit(ind, N);
  rep(i,N) node[i].clear(), node[i].push_back(i);
  
  st = 0;
  while(st < M){
    ed = st+1;
    while(ed < M && C[st]==C[ed]) ed++;
    sz = ed - st;

    if(sz < 100){
      REP(i,st,ed){
        a = A[i]; b = B[i];
        a = unionGet(ind, A[i]);
        b = unionGet(ind, B[i]);
        if(a==b) continue;
        if(node[a].size() > node[b].size()) swap(a, b);
        unionConnect(ind, a, b);

        rep(x,node[a].size()) rep(y,node[b].size()){
          s = node[a][x];
          t = node[b][y];
          if(s > t) swap(s, t);
          q = hs.get(s*N + t) - 1;
          if(q >= 0) res[qi[q]]++;
        }
        rep(x,node[a].size()) node[b].push_back(node[a][x]);
      }
      
      REP(i,st,ed) ind[A[i]] = A[i], ind[B[i]] = B[i];
      REP(i,st,ed){
        node[A[i]].clear();
        node[A[i]].push_back(A[i]);
        node[B[i]].clear();
        node[B[i]].push_back(B[i]);
      }
    } else {
      REP(i,st,ed) unionConnect(ind, A[i], B[i]);
      rep(i,Q) if(!ign[i]) if(unionGet(ind, X[i])==unionGet(ind, Y[i])) res[qi[i]]++;
      REP(i,st,ed) ind[A[i]] = A[i], ind[B[i]] = B[i];
    }

    st = ed;
  }

  rep(i,Q) if(ign[i]) res[qi[i]] = res[qi[i-1]];
  rep(i,Q) writerLn(res[i]);

  myed;
  return 0;
}