#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define makel(A) scanf("%I64d",&A)
#define pl(A) printf("%I64d ",A)
#define MAX 100005
#define INF 1000000000
int n,tt,l[MAX],p[MAX],h[MAX],sor[MAX],wyn[MAX];
struct co{
 int nr;
 bool cz;
 bool operator<(const co pom)const{
  return (cz==0?l[nr]:p[nr]) < (pom.cz==0?l[pom.nr]:p[pom.nr]);;
 }
}t[MAX*2];
bool qq(int a,int b){
 return h[a]>h[b];
}
map< PI ,int> pocz;
vector<PI> d[MAX];
set<PI> s;
set<PI>::iterator xxx;
void add(int a,int b,int c){
 if(c==min(p[a],p[b]) - max( l[a] ,l[b]))
  d[a].PB(MP(b,c));
}
main(){
 make(n);
 make(tt);
 R(i,n){
  make(h[i]);
  make(l[i]);
  make(p[i]);
  t[i*2].nr=i;
  t[i*2].cz=0;
  t[i*2+1].nr=i;
  t[i*2+1].cz=1;
 }
 h[n]=0;
 l[n]=-INF;
 p[n]=INF;
 h[n+1]=tt;
 l[n+1]=-INF;
 p[n+1]=INF;
 s.insert( MP(0,n) );
 s.insert( MP(tt,n+1) );
 sort(t,t+2*n);
 R(i,n*2){
  int nr=t[i].nr;
  int g=(t[i].cz==0?l[t[i].nr]:p[t[i].nr]);
  if(t[i].cz==0){
   xxx=s.lower_bound(MP(h[nr],nr));
   int a=(*xxx).SE;
   xxx--;
   int b=(*xxx).SE;
   add(a,b,g-pocz[ MP(a,b)] );
   s.insert(MP(h[nr],nr));
   pocz[MP(a,nr)]=g;
   pocz[MP(nr,b)]=g;
  }else{
   s.erase(MP(h[nr],nr));
   xxx=s.lower_bound(MP(h[nr],nr));
   int a=(*xxx).SE;
   xxx--;
   int b=(*xxx).SE;
   add(a,nr,g-pocz[MP(a,nr)]);
   add(nr,b,g-pocz[MP(nr,b)]);
   pocz[MP(a,b)]=g;
  }
 }
 R(i,n+2)
  sor[i]=i;
 sort(sor,sor+n+2,qq);
 wyn[n+1]=INF*2;
 R(i,n+2){
  int nr=sor[i];
  R(j,d[nr].size()){
   int kt=d[nr][j].FI;
   if(kt+nr==2*n+1)continue;
   int pom=d[nr][j].SE;
   int wyn2=min(wyn[nr],pom);
   if(wyn[kt]<wyn2)
   wyn[kt]=wyn2;
  }
 }
 printf("%d\n",wyn[n]);
}