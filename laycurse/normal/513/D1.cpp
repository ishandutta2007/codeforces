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

template<class T>
struct segtreeMinVal{
  int size, mem; T *val, *minVal;

  void malloc(int N){mem=N;val=(T*)std::malloc(sizeof(T)*N);minVal=(T*)std::malloc(sizeof(T)*N*4);}
  void free(void){mem=0;std::free(val);std::free(minVal);}
  void init_sub(int node, int left, int right){int sz=right-left,n1=node*2+1,n2=node*2+2;if(sz==1)minVal[node]=val[left];else {init_sub(n1,left,left+sz/2);init_sub(n2,left+sz/2,right);minVal[node]=min(minVal[n1], minVal[n2]);}}
  void init(int N, int zerofill = 0){int i;size=N;if(zerofill)rep(i,N)val[i]=0;init_sub(0,0,N);}
  void change_sub(int node, int left, int right, int n){int sz=right-left,n1=node*2+1,n2=node*2+2;if(n<left||n>=right)return;if(sz==1)minVal[node]=val[left];else {change_sub(n1,left,left+sz/2,n);change_sub(n2,left+sz/2,right,n);minVal[node]=min(minVal[n1],minVal[n2]);}}
  void change(int n, T v){if(val[n]==v)return;val[n]=v;change_sub(0,0,size,n);}
  T get_minVal_sub(int node, int left, int right, int a, int b){int sz=right-left,n1=node*2+1,n2=node*2+2;if(a<left)a=left;if(b>right)b=right;if(a>=b)return numeric_limits<T>::max();if(a==left&&b==right)return minVal[node];return min(get_minVal_sub(n1,left,left+sz/2,a,b), get_minVal_sub(n2,left+sz/2,right,a,b));}
  T get_minVal(int a, int b){return get_minVal_sub(0,0,size,a,b);}
};

char memarr[17000000]; void *mem = memarr;
#define MD 1000000007

int N, C;
vector< pair<int,int> > edge[1100000];

int mx[1100000];
int lef[1100000], rig[1100000];
int res[1100000], ress;
segtreeMinVal<int> t;

int solve(int st, int ed){
  int i, j, k, m;

  if(st==ed){
    if(edge[st].size()) return 0;
    lef[st] = rig[st] = -1;
    return 1;
  }

  if(edge[st].size()==0){
    lef[st] = -1;
    rig[st] = st+1;
    return solve(st+1,ed);
  }

  if(edge[st][0].second==1){
    lef[st] = -1;
    rig[st] = st+1;
    return solve(st+1,ed);
  }

  if(edge[st][edge[st].size()-1].second==-1){
    lef[st] = st+1;
    rig[st] = -1;
    return solve(st+1,ed);
  }

  m = -1;
  rep(i,edge[st].size()){
    if(edge[st][i].second==1){
      m = -t.get_minVal(st+1, edge[st][i-1].first+1);
      if(m >= edge[st][i].first || m >= ed) return 0;
      if(!solve(st+1,m)) return 0;
      if(!solve(m+1,ed)) return 0;
      lef[st] = st+1;
      rig[st] = m+1;
      return 1;
    }
  }

  assert(0);
  return 0;
}

void print(int st){
  if(lef[st]>=0) print(lef[st]);
  res[ress++]=st+1;
  if(rig[st]>=0) print(rig[st]);
}

int main(){
  int i, j, k;
  int A, B; char buf[100];
  int x, y;
  int dame = 0;

  reader(&N,&C);
  rep(i,C){
    reader(&A,&B,buf);
    A--; B--;
    if(A >= B) dame = 1;
    edge[A].push_back( make_pair(B,buf[0]=='L'?-1:1) );
  }

  rep(i,N){
    sort(edge[i].begin(), edge[i].end());
    REP(j,1,edge[i].size()) if(edge[i][j].second < edge[i][j-1].second) dame = 1;
  }

  if(dame){ writerLn("IMPOSSIBLE"); return 0; }

  t.malloc(N+1);
  t.init(N+1,1);
  for(i=N-1;i>=0;i--){
    if(edge[i].size()==0){
      mx[i] = i;
    } else {
      mx[i] = edge[i][edge[i].size()-1].first;
      mx[i] = max(mx[i], -t.get_minVal(i+1, mx[i]+1));
    }
    t.change(i, -mx[i]);
  }

  if(!solve(0,N-1)) dame = 1;
  if(dame){ writerLn("IMPOSSIBLE"); return 0; }

  print(0);
  writerArr(res,ress);

  return 0;
}