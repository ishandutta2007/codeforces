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
  map<string,int> mp;
  map<string,int>::iterator it, jt;
  string in;

  cin >> n;
  rep(i,n){
    cin >> in >> k;
    if(mp[in] < k) mp[in] = k;
  }

  m = mp.size();
  printf("%d\n",m);
  for(it=mp.begin(); it!=mp.end(); it++){
    k = 0;
    for(jt = mp.begin(); jt!=mp.end(); jt++){
      if(it->second < jt->second) k++;
    }
    cout << it->first << " ";
         if(k * 100 > 50 * m) cout << "noob" << endl;
    else if(k * 100 > 20 * m) cout << "random" << endl;
    else if(k * 100 > 10 * m) cout << "average" << endl;
    else if(k * 100 >  1 * m) cout << "hardcore" << endl;
    else                      cout << "pro" << endl;
  }

  return 0;
}