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

#define MD 1000000007

void mul(double a[], double b[], double res[]){
  int i, j, k;
  double tmp;
  rep(i,4) rep(j,4){
    tmp = 0;
    rep(k,4) tmp += b[i*4+k] * a[k*4+j];
    res[i*4+j] = tmp;
  }
}

double pi;

struct segtree{
  int N;
  double (*data)[16];

  void malloc(int maxN){
    int i;
    for(i=1;i<maxN;i*=2);
    data = (double(*)[16])std::malloc(sizeof(double[16])*2*i);
  }

  double* operator[](int i){
    return data[N+i];
  }

  void setN(int n){
    int i;
    for(i=1;i<n;i*=2);
    N = i;
  }

  void build(void){
    int i;
    for(i=N-1;i;i--){
      mul(data[2*i], data[2*i+1], data[i]);
    }
  }

  void setInit(int ind, int val){
    int i, j;
    ind += N;
    rep(i,16) data[ind][i] = 0;
    rep(i,4) data[ind][i*4+i] = 1;
    data[ind][2*4+0] = val;
    data[ind][3*4+1] = val;
  }

  void set1(int ind, int val){
    int i, j;
    ind += N;
    data[ind][2*4+0] += val;
    data[ind][3*4+1] += val;
  }

  void set2(int ind, int val){
    double th = val * pi / 180;
    ind += N;
    data[ind][0*4+0] = cos(th);
    data[ind][0*4+1] = -sin(th);
    data[ind][1*4+0] = sin(th);
    data[ind][1*4+1] = cos(th);
  }

  inline void change(int ind){
    int i, j;
    ind += N;
    while(ind > 1){
      if(ind < (ind^1)) mul(data[ind], data[ind^1], data[ind/2]);
      else              mul(data[ind^1], data[ind], data[ind/2]);
      ind /= 2;
    }
  }
};

int N, Q;
int rot_sum[300001];

int main(){
  int i, j, k;
  double rx, ry;
  segtree t;

  reader(&N,&Q);

  pi = acos(0) * 2;

  t.malloc(N+1);
  t.setN(N+1);
  t.setInit(0, 0);
  REP(i,1,N+1) t.setInit(i, 1);
  REP(i,N+1,t.N) t.setInit(i, 0);
  
  t.build();

//  REP(k,1,t.N+t.N){
//    printf("\n%d\n",k);
//    rep(i,4){ rep(j,4) printf("%f ",t.data[k][i*4+j]); puts(""); } puts("");
//  }

  while(Q--){
    reader(&i,&j,&k);

    if(i==1){
      t.set1(j, k);
      t.change(j);
    } else {
      rot_sum[j] = (rot_sum[j] + k) % 360;
      t.set2(j-1, rot_sum[j]);
      t.change(j-1);
    }

//    rep(i,4){ rep(j,4) printf("%f ",t.data[1][i*4+j]); puts(""); } puts("");

    rx = t.data[1][2*4+0];
    ry = t.data[1][2*4+1];
    writerLn(rx,ry);
  }

  return 0;
}