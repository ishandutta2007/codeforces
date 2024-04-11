#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  pair<int,string> in[60];
  char buf[10000];

  while(scanf("%d",&n)==1){
    rep(i,n){
      scanf("%s",buf);
      in[i].first = 0;
      in[i].second = buf;

      scanf("%d",&k); in[i].first -= k*100;
      scanf("%d",&k); in[i].first += k*50;
      rep(m,5){ scanf("%d",&k); in[i].first -= k; }
    }

    sort(in,in+n);
    printf("%s\n",in[0].second.c_str());
  }

  return 0;
}