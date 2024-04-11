#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  double mul;

  while(scanf("%d%d%lf",&n,&m,&mul)==3){
    map<string,int> res;
    map<string,int>::iterator it;

    while(n--){
      string in; int ex;
      cin >> in >> ex;
      ex = (int)(ex*mul + 1e-10);
      if(ex < 100) continue;
      res[in] += ex;
    }

    while(m--){
      string in;
      cin >> in;
      res[in] += 0;
    }

    printf("%d\n",(int)res.size());
    for(it=res.begin(); it!=res.end(); it++)
      printf("%s %d\n",it->first.c_str(), it->second);
  }

  return 0;
}