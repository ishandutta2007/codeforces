#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int query(const vector<int>& l, const vector<int>& r){
  printf("? %d %d\n",(int)l.size(),(int)r.size());
  rep(i,l.size()){ if(i) printf(" "); printf("%d",l[i]+1); } printf("\n");
  rep(i,r.size()){ if(i) printf(" "); printf("%d",r[i]+1); } printf("\n");
  fflush(stdout);
  int res; scanf("%d",&res);
  return res;
}

void answer(const vector<int>& ans){
  printf("! %d ",(int)ans.size());
  rep(i,ans.size()){ if(i) printf(" "); printf("%d",ans[i]+1); } printf("\n");
  fflush(stdout);
}

void testcase(){
  int N; scanf("%d",&N);
  vector<int> st={0};
  vector<int> magnetized={};
  for(int i=1; i<N; i++){
    int res=query(st,{i});
    if(res!=0){ magnetized.push_back(i); }
    else{ st.push_back(i); }
  }
  int l=0, r=st.size();
  while(r-l>1){
    int m=(l+r)/2;
    vector<int> q; for(int i=l; i<m; i++) q.push_back(st[i]);
    int res=query(q,{magnetized[0]});
    if(res!=0) r=m; else l=m;
  }
  magnetized.push_back(st[l]);
  swap(st[l],st.back()); st.pop_back();
  answer(st);
}

int main(){ int t; scanf("%d",&t); while(t--) testcase(); return 0; }