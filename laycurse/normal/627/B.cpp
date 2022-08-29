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

char memarr[77000000]; void *mem = memarr;
#define MD 1000000007

template<class T>
struct fenwick{
  int size, memory; T *data;
  void malloc(int mem){memory=mem;data=(T*)std::malloc(sizeof(T)*mem);}
  void *malloc(int mem, void *workMemory){memory=mem;data=(T*)workMemory;return (void*)(data+mem);}
  void free(void){memory=0;free(data);}
  void init(int N){size=N;memset(data,0,sizeof(T)*N);}
  void add(int k, T val){while(k<size)data[k]+=val,k|=k+1;}
  T get(int k){T res=0;while(k>=0)res+=data[k],k=(k&(k+1))-1;return res;}
  T range(int a, int b){if(b==-1)b=size-1;return get(b)-get(a-1);}
  int kth(T k){int i=0,j=size,c;T v;while(i<j){c=(i+j)/2;v=get(c);if(v<=k)i=c+1;else j=c;}return i==size?-1:i;}
};

int N, K, A, B, Q;
int MODE, D, V, P;

int arr1[210000], arr2[210000];

int main(){
  int i, j, k, nx;
  fenwick<int> t1, t2;
  int res;

  reader(&N,&K);
  reader(&A,&B,&Q);

  mem = t1.malloc(N+1, mem);
  mem = t2.malloc(N+1, mem);
  t1.init(N+1);
  t2.init(N+1);

  while(Q--){
    reader(&MODE);
    if(MODE==1){
      reader(&D,&V); D--;

      nx = min(B, arr1[D]+V);
      t1.add(D, nx-arr1[D]);
      arr1[D] = nx;

      nx = min(A, arr2[D]+V);
      t2.add(D, nx-arr2[D]);
      arr2[D] = nx;
    } else {
      reader(&P); P--;
      res = t1.get(P-1) + t2.range(P+K, N);
      writerLn(res);
    }
  }

  return 0;
}