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

#define VI vector<int> 

int main(){
  int i,j,k,l,m,n,q,size;
  string in; char buf[1000];
  map<string,int> ind;
  pair<VI,string> s1[1200];
  pair<VI,string> s2[1200];
  int score[51]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

  VI empty(55);

  rep(i,1200) s1[i]=s2[i]=make_pair(empty,(string)"");

  scanf("%d",&q);
  size=0;
  while(q--){
    scanf("%d",&n);
    rep(i,n){
      scanf("%s",buf); in=buf;
      if(ind.count(in)==0) ind[in]=size++;
      k = ind[in];
      s1[k].second = in;
      s2[k].second = in;

      s1[k].first[0] -= score[i];
      s2[k].first[1] -= score[i];

      if(i==0){
        s1[k].first[1]--;
        s2[k].first[0]--;
      } else {
        s1[k].first[i+1]--;
        s2[k].first[i+1]--;
      }
    }
  }

  sort(s1,s1+size);
  sort(s2,s2+size);
  printf("%s\n%s\n",s1[0].second.c_str(),s2[0].second.c_str());

  return 0;
}