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

template <class T>
struct heapEx {
  int *hp, *place, size; T *val;

  void malloc(int N){hp=(int*)std::malloc(N*sizeof(int));place=(int*)std::malloc(N*sizeof(int));val=(T*)std::malloc(N*sizeof(T));}
  void free(){free(hp);free(place);free(val);}
  void* malloc(int N, void *workMemory){hp=(int*)workMemory;workMemory=(void*)(hp+N);place=(int*)workMemory;workMemory=(void*)(place+N);val=(T*)workMemory;workMemory=(void*)(val+N);return workMemory;}
  void init(int N){int i;size=0;rep(i,N)place[i]=-1;}
  void up(int n){int m;while(n){m=(n-1)/2;if(val[hp[m]]<=val[hp[n]])break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void down(int n){int m;for(;;){m=2*n+1;if(m>=size)break;if(m+1<size&&val[hp[m]]>val[hp[m+1]])m++;if(val[hp[m]]>=val[hp[n]])break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void change(int n, T v){T f=val[n];val[n]=v;if(place[n]==-1){place[n] = size;hp[size++] = n;up(place[n]);}else{if(f < v) down(place[n]); else if(f > v) up(place[n]);}}
  int pop(void){int res=hp[0];place[res]=-1;size--;if(size)hp[0]=hp[size],place[hp[0]]=0,down(0);return res;}
};

int N, T, Q;
int P[300000], L[300000];
int bet[300000];
heapEx<double> hp1, hp2;

inline void heap_update(int i){
  double val = min(0.5, (bet[i]+1) / (double)(L[i]+bet[i]+1)) - min(0.5, bet[i] / (double)(L[i]+bet[i]));
  hp1.change(i, -P[i]*val);
  if(bet[i]){
    val = min(0.5, (bet[i]-1) / (double)(L[i]+bet[i]-1)) - min(0.5, bet[i] / (double)(L[i]+bet[i]));
  } else {
    val = -1e100;
  }
  hp2.change(i, -P[i]*val);
}

int main(){
  int i, j, k;
  int x, y;
  double res = 0;

  reader(&N,&T,&Q);
  rep(i,N) reader(P+i);
  rep(i,N) reader(L+i);

  mem = hp1.malloc(N, mem);
  mem = hp2.malloc(N, mem);
  hp1.init(N);
  hp2.init(N);

  rep(i,N) heap_update(i);
  rep(i,T){
    k = hp1.hp[0];
    bet[k]++;
    res += -hp1.val[k];
    heap_update(k);
  }

  while(Q--){
    reader(&x,&y); y--;
    if(bet[y]) res -= P[y] * min(0.5, bet[y] / (double)(L[y]+bet[y]));
    if(x==1) L[y]++;
    if(x==2) L[y]--;
    if(bet[y]) res += P[y] * min(0.5, bet[y] / (double)(L[y]+bet[y]));

    heap_update(y);

    for(;;){
      if(hp2.size==0) break;
      i = hp1.hp[0];
      j = hp2.hp[0];

//      printf("---- "); writerLn(i,j);
//      printf("---- "); writerLn(-hp1.val[i],hp2.val[j]);
      
      if(i != j && -hp1.val[i] > hp2.val[j]+1e-10){
        bet[i]++;
        bet[j]--;

        res += -hp1.val[i];
        res -= hp2.val[j];

        heap_update(i);
        heap_update(j);
      } else {
        break;
      }
    }
    
    writerLn(res);
  }

  return 0;
}