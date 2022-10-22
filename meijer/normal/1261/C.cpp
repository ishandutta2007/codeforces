#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const ll MX=2e6+1e4, MOD=1e9+7;
int n, m;
char gr[MX], ans[MX];
int cnt[MX], Fill[MX];

inline int id(int r, int c) {
  return r+c*(n+1);
}
inline int countX(int br, int bc, int er, int ec) {
  er++; ec++;
  return cnt[id(er,ec)] - cnt[id(br,ec)] - cnt[id(er,bc)] + cnt[id(br,bc)];
}
inline bool allX(int br, int bc, int er, int ec) {
  return countX(br, bc, er, ec) == ((er-br+1)*(ec-bc+1));
}
inline void addRegion(int br, int bc, int er, int ec) {
  er++; ec++;
  Fill[id(er,ec)]++;
  Fill[id(br,bc)]++;
  Fill[id(br,ec)]--;
  Fill[id(er,bc)]--;
}
bool isPossible(int x) {
  RE(i,n+1) RE(j,m+1) Fill[id(i,j)] = 0;
  REP(i,x,n-x) REP(j,x,m-x) {
    int br=i-x, bc=j-x, er=i+x, ec=j+x;
    if(allX(br,bc,er,ec))
      addRegion(br,bc,er,ec);
  }
  RE(i,n) RE(j,m) {
    if(i != 0)            Fill[id(i,j)] += Fill[id(i-1,j  )];
    if(j != 0)            Fill[id(i,j)] += Fill[id(i  ,j-1)];
    if(i != 0 && j != 0)  Fill[id(i,j)] -= Fill[id(i-1,j-1)];
  }
  RE(i,n) RE(j,m)
    if(gr[id(i,j)] == 'X' && Fill[id(i,j)] == 0)
      return 0;
  return 1;
}

int main() {
  scanf("%d %d\n", &n, &m);
  RE(i,n) {
    RE(j,m) scanf("%c", &gr[id(i,j)]);
    scanf("\n");
  }
  RE(i,n+1) cnt[id(i,0)]=0;
  RE(i,m+1) cnt[id(0,i)]=0;
  RE(i,n) RE(j,m)
    cnt[id(i+1,j+1)] = cnt[id(i,j+1)] + cnt[id(i+1,j)] - cnt[id(i,j)] + (gr[id(i,j)]=='X'?1:0);
  int lb=0, ub=min(n-1, m-1)/2;
  while(lb != ub) {
    int mid=(lb+ub+1)/2;
    if(isPossible(mid)) lb=mid;
    else ub=mid-1;
  }
  int x = lb;
  cout<<x<<endl;
  RE(i,n) RE(j,m) ans[id(i,j)] = '.';
  REP(i,x,n-x) REP(j,x,m-x) {
    if(allX(i-x,j-x,i+x,j+x)) ans[id(i,j)] = 'X';
  }
  RE(i,n) {
    RE(j,m) printf("%c", ans[id(i,j)]);
    printf("\n");
  }
}