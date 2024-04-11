#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void loop(){
 LL p,f; cin>>p>>f;
 LL cs,cw; cin>>cs>>cw;
 LL s,w; cin>>s>>w;
 if(s>w){ swap(s,w); swap(cs,cw); }
 LL ans=0;
 rep(i,cs+1){
  if(p/s < i) break;
  LL p_s = i;
  LL p_w = (p-p_s*s)/w;
  LL f_s = min(cs-p_s,f/s);
  LL f_w = min(cw-p_w,(f-f_s*s)/w);
  ans = max(ans,p_s+p_w+f_s+f_w);
 }
 cout << ans << endl;
}

int main() {
 int T; scanf("%d",&T);
 while(T--) loop();
 return 0;
}