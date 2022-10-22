
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,W;
int C[20];

void testcase(){
  scanf("%d%d",&N,&W);
  rep(d,20) C[d]=0;
  rep(i,N){ int a; scanf("%d",&a); rep(d,20) if((1<<d)==a) C[d]++; }
  int ans=0;
  while(N){
    ans++;
    int w=W;
    for(int d=19; d>=0; d--){
      int c=min(C[d],w>>d);
      N-=c; C[d]-=c; w-=(c<<d);
    }
  }
  printf("%d\n",ans);
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}