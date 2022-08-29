#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
void *wmem;
char memarr[96000000];
template<class T> inline void walloc1d(T **arr, int x, void **mem = &wmem){
  static int skip[16] = {0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  (*mem) = (void*)( ((char*)(*mem)) + skip[((unsigned long long)(*mem)) & 15] );
  (*arr)=(T*)(*mem);
  (*mem)=((*arr)+x);
}
template<class T1> void sortA_L(int N, T1 a[], void *mem = wmem){
  sort(a, a+N);
}
template<class T1, class T2> void sortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  int i;
  pair<T1, T2> *arr;
  walloc1d(&arr, N, &mem);
  for(i=(0);i<(N);i++){
    arr[i].first = a[i];
    arr[i].second = b[i];
  }
  sort(arr, arr+N);
  for(i=(0);i<(N);i++){
    a[i] = arr[i].first;
    b[i] = arr[i].second;
  }
}
template<class T1> void rsortA_L(int N, T1 a[], void *mem = wmem){
  sortA_L(N, a, mem);
  reverse(a, a+N);
}
template<class T1, class T2> void rsortA_L(int N, T1 a[], T2 b[], void *mem = wmem){
  sortA_L(N, a, b, mem);
  reverse(a, a+N);
  reverse(b, b+N);
}
inline int my_getchar(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = my_getchar();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline int rd_int(void){
  int x;
  rd(x);
  return x;
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar(a);
}
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    my_putchar('-');
  }
  while(s--){
    my_putchar(f[s]+'0');
  }
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    my_putchar(c[i]);
  }
}
template <class T> struct LHeap{
  int *hp;
  int *place;
  int size;
  T *val;
  void malloc(int N){
    hp = (int*)std::malloc(N*sizeof(int));
    place=(int*)std::malloc(N*sizeof(int));
    val=(T*)std::malloc(N*sizeof(T));
  }
  void walloc(int N, void **mem=&wmem){
    walloc1d(&hp, N, mem);
    walloc1d(&place, N, mem);
    walloc1d(&val, N, mem);
  }
  void free(){
    std::free(hp);
    std::free(place);
    std::free(val);
  }
  void init(int N){
    int i;
    size=0;
    for(i=(0);i<(N);i++){
      place[i]=-1;
    }
  }
  void up(int n){
    int m;
    while(n){
      m=(n-1)/2;
      if(val[hp[m]]<=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void down(int n){
    int m;
    for(;;){
      m=2*n+1;
      if(m>=size){
        break;
      }
      if(m+1<size&&val[hp[m]]>val[hp[m+1]]){
        m++;
      }
      if(val[hp[m]]>=val[hp[n]]){
        break;
      }
      swap(hp[m],hp[n]);
      swap(place[hp[m]],place[hp[n]]);
      n=m;
    }
  }
  void change(int n, T v){
    T f = val[n];
    val[n] = v;
    if(place[n]==-1){
      place[n] = size;
      hp[size++] = n;
      up(place[n]);
    }
    else{
      if(f < v){
        down(place[n]);
      }
      else if(f > v){
        up(place[n]);
      }
    }
  }
  int pop(void){
    int res = hp[0];
    place[res] = -1;
    size--;
    if(size){
      hp[0]=hp[size];
      place[hp[0]]=0;
      down(0);
    }
    return res;
  }
}
;
int N;
int X;
int Y;
int A[100000];
int B[100000];
int cntB[100000+1];
int mch[100000+1];
int cnt[100000+1];
int ind[100000+1];
int sz;
vector<int> arr[100000+1];
int main(){
  int Lj4PdHRW;
  wmem = memarr;
  LHeap<int> hp;
  hp.walloc(100000+1);
  int KL2GvlyY = rd_int();
  for(Lj4PdHRW=(0);Lj4PdHRW<(KL2GvlyY);Lj4PdHRW++){
    int i;
    int j;
    int k;
    int kk;
    int dm;
    int knd = 0;
    int a;
    int b;
    int c;
    int aa;
    int bb;
    int cc;
    rd(N);
    rd(X);
    rd(Y);
    {
      int cTE1_r3A;
      for(cTE1_r3A=(0);cTE1_r3A<(N);cTE1_r3A++){
        rd(B[cTE1_r3A]);B[cTE1_r3A] += (-1);
      }
    }
    if(Y==N && X==Y-1){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    for(i=(0);i<(N+1);i++){
      cntB[i] = 0;
    }
    for(i=(0);i<(N);i++){
      cntB[B[i]]++;
    }
    for(i=(0);i<(N+1);i++){
      cnt[i] = 0;
    }
    for(i=(0);i<(N+1);i++){
      ind[i] = i;
    }
    for(i=(0);i<(N);i++){
      cnt[B[i]]++;
    }
    rsortA_L(N+1, cnt, ind);
    dm = ind[N];
    for(i=(0);i<(N+1);i++){
      arr[i].clear();
    }
    for(i=(0);i<(N);i++){
      A[i] = B[i];
      arr[B[i]].push_back(i);
    }
    hp.init(N+1);
    for(i=(0);i<(N+1);i++){
      if(arr[i].size()){
        hp.change(i, -((int)arr[i].size()));
      }
    }
    kk = N - Y;
    k = N - X;
    while(k >= kk){
      if(k<=1){
        break;
      }
      if(hp.size < 2){
        break;
      }
      a = hp.pop();
      b = hp.pop();
      aa = arr[a].back();
      arr[a].pop_back();
      bb = arr[b].back();
      arr[b].pop_back();
      swap(A[aa], A[bb]);
      if(k==3 && hp.size){
        c = hp.pop();
        cc = arr[c].back();
        arr[c].pop_back();
        swap(A[aa], A[cc]);
        if(arr[c].size()){
          hp.change(c, -((int)arr[c].size()));
        }
        k--;
      }
      if(arr[a].size()){
        hp.change(a, -((int)arr[a].size()));
      }
      if(arr[b].size()){
        hp.change(b, -((int)arr[b].size()));
      }
      k -= 2;
    }
    for(i=(0);i<(N);i++){
      if(k && kk && A[i]==B[i]){
        A[i] = dm;
        k--;
        kk--;
      }
    }
    for(i=(0);i<(N);i++){
      if(kk && A[i] != dm && A[i] != B[i]){
        A[i] = dm;
        kk--;
      }
    }
    if(k || kk){
      wt_L("NO");
      wt_L('\n');
      continue;
    }
    wt_L("YES");
    wt_L('\n');
    {
      int qSsg05KM;
      if(N==0){
        wt_L('\n');
      }
      else{
        for(qSsg05KM=(0);qSsg05KM<(N-1);qSsg05KM++){
          wt_L(A[qSsg05KM]+1);
          wt_L(' ');
        }
        wt_L(A[qSsg05KM]+1);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200509-1

// --- original code ---
// //no-unlocked
// int N, X, Y, A[1d5], B[1d5];
// int cntB[1d5+1], mch[1d5+1];
// int cnt[1d5+1], ind[1d5+1], sz;
// vector<int> arr[1d5+1];
// {
//   LHeap<int> hp;
//   hp.walloc(1d5+1);
//   REP(rd_int()){
//     int i, j, k, kk, dm, knd = 0;
//     int a, b, c, aa, bb, cc;
// 
//     rd(N,X,Y,(B--)(N));
//     if(Y==N && X==Y-1) wt("NO"), continue;
// 
//     rep(i,N+1) cntB[i] = 0;
//     rep(i,N) cntB[B[i]]++;
// 
//     rep(i,N+1) cnt[i] = 0;
//     rep(i,N+1) ind[i] = i;
//     rep(i,N) cnt[B[i]]++;
//     rsortA(N+1, cnt, ind);
// 
//     dm = ind[N];
// 
//     rep(i,N+1) arr[i].clear();
//     rep(i,N){
//       A[i] = B[i];
//       arr[B[i]].push_back(i);
//     }
// 
//     hp.init(N+1);
//     rep(i,N+1) if(arr[i].size()) hp.change(i, -((int)arr[i].size()));
// 
// 
//     kk = N - Y;
//     k = N - X;
//     while(k >= kk){
//       if(k<=1) break;
//       if(hp.size < 2) break;
//       a = hp.pop();
//       b = hp.pop();
//       aa = arr[a].back();
//       arr[a].pop_back();
//       bb = arr[b].back();
//       arr[b].pop_back();
//       swap(A[aa], A[bb]);
//       if(k==3 && hp.size){
//         c = hp.pop();
//         cc = arr[c].back();
//         arr[c].pop_back();
//         swap(A[aa], A[cc]);
//         if(arr[c].size()) hp.change(c, -((int)arr[c].size()));
//         k--;
//       }
//       if(arr[a].size()) hp.change(a, -((int)arr[a].size()));
//       if(arr[b].size()) hp.change(b, -((int)arr[b].size()));
//       k -= 2;
//     }
// 
// //    wt(k,kk,":",A(N)+1);
// 
//     rep(i,N) if(k && kk && A[i]==B[i]){
//       A[i] = dm;
//       k--;
//       kk--;
//     }
//     rep(i,N) if(kk && A[i] != dm && A[i] != B[i]){
//       A[i] = dm;
//       kk--;
//     }
// 
//     if(k || kk) wt("NO"), continue;
// 
//     wt("YES");
//     wt(A(N)+1);
//   }
// }