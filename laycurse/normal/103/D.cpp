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

#define ll long long
#define N 300100

ll in[N];
ll res[N];
vector<int> q[N]; /* b, a mod b, -a, ind */

int main(){
  int i,j,k,l,m,n,qs;
  ll now;

  while(scanf("%d",&n)==1){
    rep(i,n){
      scanf("%d",&k);
      in[i] = k;
    }

    scanf("%d",&qs);
    rep(i,qs){
      scanf("%d%d",&j,&k); j--;
      q[i].clear();
      q[i].push_back(k);
      q[i].push_back(j%k);
      q[i].push_back(-j);
      q[i].push_back(i);
    }

    sort(q,q+qs);
    rep(i,qs){
      if(i && q[i-1][0]==q[i][0] && q[i-1][1]==q[i][1]){
        now = res[q[i-1][3]];
        for(j=-q[i][2]; j<-q[i-1][2]; j+=q[i][0]) now += in[j];
      } else {
        now = 0;
        for(j=-q[i][2]; j<n; j+=q[i][0]) now += in[j];
      }
      res[q[i][3]] = now;
    }

    rep(i,qs) printf("%I64d\n",res[i]);
  }


  return 0;
}