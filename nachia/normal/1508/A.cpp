#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


void testcase(){
  int N;
  string S[3];
  int cnt[3][2] = {};
  scanf("%d",&N);
  rep(t,3){ S[t].resize(2*N+1); scanf("%s",S[t].data()); S[t][2*N]='\0'; }
  rep(t,3) rep(i,2*N) cnt[t][S[t][i]-'0']++;
  rep(a,3) rep(b,3){
    if(a==b) continue;
    char tg = ' ';
    if(cnt[a][0]>=N && cnt[b][0]>=N) tg = '0';
    else if(cnt[a][1]>=N && cnt[b][1]>=N) tg = '1';
    else continue;
    string ans;
    int pa=0, pb=0;
    while(pa+pb<4*N){
      if(pa==2*N){
        ans.push_back(S[b][pb++]);
        continue;
      }
      if(pb==2*N){
        ans.push_back(S[a][pa++]);
        continue;
      }
      if(S[a][pa]!=tg){
        ans.push_back(S[a][pa++]);
        continue;
      }
      if(S[b][pb]!=tg){
        ans.push_back(S[b][pb++]);
        continue;
      }
      ans.push_back(tg);
      pa++; pb++;
    }
    printf("%s\n",ans.c_str());
    return;
  }
}

int main(){
  int T; scanf("%d",&T);
  while(T--) testcase();
  return 0;
}