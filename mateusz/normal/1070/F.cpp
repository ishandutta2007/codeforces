#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a) ; i<= (b); i++)
#define REP(i, n) FOR(i,0,(int)(n) - 1)
#define st first
#define nd second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define VI vector<int>
#define PII pair<int,int>

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  map<string, VI> mapka;
  REP(i, n){
    string s;
    cin>>s;
    int a;
    cin>>a;
    mapka[s].PB(a);
  }
  for(auto & it: mapka){
    sort(ALL(it.nd));
  }
  int totalInf = 0;
  int ppl = 0;
  int x, y;
  x = y = 0;
  for(int a: mapka["11"]){
    totalInf += a;
    ppl++;
    x++;
    y++;
  }
  sort(ALL(mapka["01"]));
  sort(ALL(mapka["10"]));
  while(mapka["01"].size() && mapka["10"].size()){
    int t1 = mapka["01"].back();
    int t2 = mapka["10"].back();
    totalInf += t1;
    totalInf += t2;
    ppl += 2;
    x++;
    y++;
    mapka["01"].pop_back();
    mapka["10"].pop_back();
  }
  VI everyone;
  for(auto v: {"00", "01", "10"}){
    for(int a: mapka[v]){
      everyone.push_back(a);
    }
  }
  sort(ALL(everyone));
  while(everyone.size()){
    ppl++;
    if(x < (ppl + 1) / 2  || y < (ppl + 1) / 2){
      break;
    }
    int t = everyone.back();
    everyone.pop_back();
    totalInf += t;
  }
  cout<<totalInf<<"\n";
}