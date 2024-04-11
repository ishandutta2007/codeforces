#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
#include<ctime>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

#define mygc(c) (c)=_getchar_nolock()
#define mypc(c) _putchar_nolock(c)

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void writer(int x, char c){int i,sz=0,m=0;char buf[10];if(x<0)m=1,x=-x;while(x)buf[sz++]=x%10,x/=10;if(!sz)buf[sz++]=0;if(m)mypc('-');while(sz--)mypc(buf[sz]+'0');mypc(c);}

int N, M, S, E, A[110000], B[110000];

vector<int> place[110000];
int pt[110000], nx[110000];

int main(){
  int i, j, k, mn, ok;
  int res;

  reader(&N);
  reader(&M);
  reader(&S);
  reader(&E);
  rep(i,N) reader(A+i);
  rep(i,M) reader(B+i);

  rep(i,M) place[B[i]].push_back(i);

  rep(i,N) pt[i] = -1;
  for(res=0;;res++){
    mn = INF; if(res==0) mn = -1;
    ok = 0;
    rep(i,N){
      k = lower_bound(place[A[i]].begin(), place[A[i]].end(), mn+1) - place[A[i]].begin();
      mn = min(mn, pt[i]);
      if(k == place[A[i]].size()){ nx[i]=INF; continue; }
      nx[i] = place[A[i]][k];
      if(S - E*(res+1) - (i+1) - (nx[i]+1) >= 0) ok = 1;
    }

    if(!ok) break;
    rep(i,N) pt[i] = nx[i];
  }
  writer(res, '\n');

  return 0;
}