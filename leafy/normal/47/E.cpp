#include<bits/stdc++.h>
using namespace std;
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rec register char
#define rel register ll
#define gc getchar
#define pc putchar
#define p32 pc(' ')
#define pl puts("")

inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return 0&pc(48);
  if (x<0) x=-x,pc('-');
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
typedef double db;
const int yuzu=1e5;
const db g=9.8;

namespace gongshi{
db vxt(db v,db alp){return v*cos(alp);}
db vyt(db v,db alp,db t){return v*sin(alp)-g*t;}
db xt(db v,db alp,db t){return v*cos(alp)*t;}
db yt(db v,db alp,db t){return v*sin(alp)*t-g*t*t/2;}
db _tx(db x,db alp,db v){return x/v/cos(alp);}
db _ty(db v,db alp){return 2*v*sin(alp)/g;}
}using namespace gongshi;

struct qiang{
db x,y;
void rd(){scanf("%lf%lf",&x,&y);}
bool operator <(const qiang &b) const{
  return x!=b.x?x<b.x:y<b.y;
  }
}w[yuzu|10];

typedef pair<db,int> node;
node a[yuzu|10];

pair<db,db> llx[yuzu|10];

int main(){
int i,n=read();
db alp,v=read();
for (i=1;i<=n;++i){
  scanf("%lf",&alp);
  a[i]=node(alp,i);
  } 
sort(a+1,a+n+1);
int m=read(),r=1;
for (i=1;i<=m;++i) w[i].rd();
sort(w+1,w+m+1);
#define suan yt(v,a[i].first,_tx(w[r].x,a[i].first,v))
for (i=1;i<=n;++i){
  for (;r<=m&&suan>w[r].y;++r); 
  llx[a[i].second]=suan<=0||r>m?make_pair(xt(v,a[i].first,_ty(v,a[i].first)),0.):make_pair(w[r].x,suan); 
  }
for (i=1;i<=n;++i) printf("%.9lf %.9lf\n",llx[i].first,llx[i].second);
return 0;
}