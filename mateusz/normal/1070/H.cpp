#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,0,(int)(n)-1)
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
  vector<string> files(n);
  map<string, int> co;
  map<string, string> example;
  REP(i, n){
    cin>>files[i];
    set<string> done;
    REP(x, SZ(files[i])){
      REP(j, SZ(files[i])){
        if(j + x >= SZ(files[i])){
          break;
        }
        string tmp = files[i].substr(j, x + 1);
        if(!done.count(tmp)){
          done.insert(tmp);
          co[tmp]++;
          example[tmp] = files[i];
        }
      }
    }
  }

  int q;
  cin>>q;
  REP(_, q){
    string ts;
    cin>>ts;
    if(!co.count(ts)){
      cout<<"0 -";
    } else{
      cout<<co[ts]<<" "<<example[ts];
    }
    cout<<"\n";
  }
}