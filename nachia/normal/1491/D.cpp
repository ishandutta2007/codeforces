#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int Q;

int main(){
  scanf("%d",&Q);
  while(Q--){
    int u,v;
    scanf("%d%d",&u,&v);
    vector<int> U; rep(d,30) if(u&(1<<d)) U.push_back(d);
    vector<int> V; rep(d,30) if(v&(1<<d)) V.push_back(d);
    bool ok=true;
    if(u>v) ok=false;
    if(U.size()<V.size()) ok=false;
    else rep(i,V.size()) if(U[i]>V[i]) ok=false;
    printf(ok?"YES\n":"NO\n");
  }
  return 0;
}