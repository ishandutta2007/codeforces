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
pair<VI,string> lis[1000];
pair<VI,string> res[1000];

int cnv[1000];
char buf[1000];
map<string,int> ind;

int main(){
  int i,j,k,l,m,n;
  string a,b;
  int s,t;

  rep(i,26){
    cnv['A'+i] = 2*i;
    cnv['a'+i] = 2*i+1+100;
  }

  scanf("%d",&n);
  rep(i,n){
    VI tmp(3,0);
    scanf("%s",buf);
    lis[i] = make_pair(tmp,(string)buf);
    ind[(string)buf] = i;
  }

  rep(l,n*(n-1)/2){
    scanf("%s %d:%d ",buf,&s,&t);
    k=0;
    a=b="";
    for(i=0;;i++){
      if(buf[i]<' ') break;
      if(buf[i]=='-'){k++; continue;}
      if(k==0) a += buf[i];
      if(k==1) b += buf[i];
      while(k>2);
    }
    while(ind.count(a)==0);
    while(ind.count(b)==0);
    i = ind[a]; j = ind[b];
    if(s==t){ lis[i].first[0] -= 1; lis[j].first[0] -= 1; }
    if(s> t){ lis[i].first[0] -= 3; lis[j].first[0] -= 0; }
    if(s< t){ lis[i].first[0] -= 0; lis[j].first[0] -= 3; }
    lis[i].first[1] -= s-t; lis[j].first[1] -= t-s;
    lis[i].first[2] -= s;   lis[j].first[2] -= t;
  }

  sort(lis,lis+n);

  rep(i,n/2){
    VI tmp;
    rep(k,lis[i].second.size()) tmp.push_back(cnv[lis[i].second[k]]);
    res[i].first  = tmp;
    res[i].second = lis[i].second;
  }

  sort(res,res+n/2);
  rep(i,n/2) printf("%s\n",res[i].second.c_str());

  return 0;
}