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
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}

template<class T>
struct segtreeMinVal{
  int size, mem;
  T *val, *minVal;

  void malloc(int N){
    mem = N;
    val = (T*)std::malloc(sizeof(T)*N);
    minVal = (T*)std::malloc(sizeof(T)*N*4);
  }

  void free(void){
    mem = 0;
    std::free(val);
    std::free(minVal);
  }

  void init_sub(int node, int left, int right){
    int sz = right - left, n1 = node*2+1, n2 = node*2+2;

    if(sz==1){
      minVal[node] = val[left];
    } else {
      init_sub(n1, left, left+sz/2);
      init_sub(n2, left+sz/2, right);
      minVal[node] = minVal[n1] & minVal[n2];
    }
  }
  
  void init(int N, int zerofill = 0){
    int i;
    size = N;
    if(zerofill) rep(i,N) val[i] = 0;
    init_sub(0, 0, N);
  }

  T get_minVal_sub(int node, int left, int right, int a, int b){
    int sz = right - left, n1 = node*2+1, n2 = node*2+2;

    if(a < left) a = left;
    if(b > right) b = right;
    if(a >= b) return 2147483647;
    if(a==left && b==right) return minVal[node];

    return get_minVal_sub(n1,left,left+sz/2,a,b) & get_minVal_sub(n2,left+sz/2,right,a,b);
  }

  T get_minVal(int a, int b){
    return get_minVal_sub(0, 0, size, a, b);
  }
};


int N, M, L[200000], R[200000], Q[200000];

int arr[200000];
int bit[33][200000];

int main(){
  int i, j, k;
  segtreeMinVal<int> t;
  int dame;

  reader(&N, &M);
  rep(i,M) reader(L+i,R+i,Q+i), L[i]--;

  rep(i,M) rep(k,31) if(Q[i] & 1<<k) bit[k][L[i]]++, bit[k][R[i]]--;
  rep(k,31) REP(i,1,N+1) bit[k][i] += bit[k][i-1];

  rep(k,31) rep(i,N) if(bit[k][i]) arr[i] += (1<<k);

  dame = 0;
  t.malloc(N+10);
  rep(i,N) t.val[i] = arr[i];
  t.init(N);
  rep(i,M) if(t.get_minVal(L[i],R[i]) != Q[i]){
    dame = 1;
    break;
  }

  if(!dame){
    writer("YES\n");
    rep(i,N) writer(arr[i],i==N-1?'\n':' ');
  } else {
    writer("NO\n");
  }

  myed;
  return 0;
}