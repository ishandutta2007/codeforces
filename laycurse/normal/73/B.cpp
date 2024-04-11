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

int n;
pair<int,string> in[110000], mydata;
string my; int place;
int gain[110000];

int used[110000];

int main(){
  int i,j,k,l,m;
  int res1, res2;
  int a,b,c,fg;
  char buf[10000];
  multiset<int> gat;
  multiset<int>::iterator it;

  while(scanf("%d",&n)==1){
    rep(i,n){
      scanf("%s%d",buf,&k);
      in[i] = make_pair(-k, (string)buf);
    }
    scanf("%d",&k);
    rep(i,n) gain[i]=0;
    rep(i,k) scanf("%d",gain+i);

    scanf("%s",buf); my = buf;

    sort(in, in+n);
    rep(i,n) if(in[i].second == my) place = i;

    rep(i,n) used[i] = 0;

    res1 = res2 = 0;
    
    gat.clear();
    rep(j,n) gat.insert(gain[j]);

    it = gat.end(); it--;
    mydata = in[place];
    mydata.first -= (*it);
    gat.erase(it);
    
    rep(i,n) if(i!=place){
      a = (-mydata.first) - (-in[i].first);
      in[i].first -= a; fg=0;
      if(in[i] < mydata) fg=1;
      in[i].first += a;
      a -= fg;

      it = gat.upper_bound(a);
      if(it == gat.begin()) continue;
      it--;
      if( (*it) > a ) continue;
      res1++; gat.erase(it);
    }


    gat.clear();
    rep(j,n) gat.insert(gain[j]);

    it = gat.begin();
    mydata = in[place];
    mydata.first -= (*it);
    gat.erase(it);
    
    rep(i,n) if(i!=place){
      a = (-mydata.first) - (-in[i].first);
      in[i].first -= a; fg=0;
      if(in[i] > mydata) fg=1;
      in[i].first += a;
      a += fg;

      it = gat.lower_bound(a);
      if(it == gat.end()) continue;

      res2++; gat.erase(it);
    }


    res1 = n-res1;
    res2++;

    printf("%d %d\n",res1,res2);
  }

  return 0;
}