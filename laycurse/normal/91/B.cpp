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

int in[120000], res[120000];
pair<int,int> s[120000];

int main(){
  int i,j,k,l,m,n;
  int mx;

  while(scanf("%d",&n)==1){
    rep(i,n) scanf("%d",in+i);
    rep(i,n) s[i].first = in[i], s[i].second = i;
    sort(s,s+n);

    mx = -1;
    rep(i,n){
      if(mx < s[i].second) mx = s[i].second;
      res[s[i].second] = mx - s[i].second - 1;
    }

    rep(i,n){
      if(i) putchar(' ');
      printf("%d",res[i]);
    }
    puts("");
  }

  return 0;
}