

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct Point{ int x,y; };

int N;

int phase=0;
vector<Point> S[2];

int main(){
  scanf("%d",&N);
  rep(y,N) rep(x,N) S[(x+y)&1].push_back({y+1,x+1});
  rep(i,N*N){
    int a; scanf("%d",&a);
    if(phase==0){
      if(a==1 || a==3){
        auto p = S[1].back(); S[1].pop_back();
        printf("2 %d %d\n",p.y,p.x); fflush(stdout);
      }
      if(a==2){
        auto p = S[0].back(); S[0].pop_back();
        printf("1 %d %d\n",p.y,p.x); fflush(stdout);
      }
      rep(t,2) if(S[t].empty()) phase=1;
    }
    else if(phase==1){
      int c=0;
      rep(t,2) if(S[t].size()) c=t;
      auto p = S[c].back(); S[c].pop_back();
      if(a==c+1){
        printf("3 %d %d\n",p.y,p.x); fflush(stdout);
      }
      else{
        printf("%d %d %d\n",c+1,p.y,p.x); fflush(stdout);
      }
    }
  }
  return 0;
}