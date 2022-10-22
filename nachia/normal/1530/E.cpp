
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const string alp = "abcdefghijklmnopqrstuvwxyz";

string testcase(){
  string S; cin >> S;
  sort(S.begin(),S.end());
  vector<int> C(alp.size(),0);
  for(char c : S) C[alp.find(c)]++;
  vector<int> Oc;
  rep(i,C.size()) if(C[i] != 0) Oc.push_back(i);
  if(Oc.size() == 1) return S;

  rep(i,Oc.size()) if(C[Oc[i]] == 1){
    string ans;
    ans.push_back(alp[Oc[i]]);
    rep(j,Oc.size()) if(i!=j) ans += string(C[Oc[j]],alp[Oc[j]]);
    return move(ans);
  }

  if(C[Oc[0]] * 2 - 1 <= S.size()){
    string rem;
    for(int i=1; i<Oc.size(); i++) rem += string(C[Oc[i]],alp[Oc[i]]);
    string ans;
    ans.push_back(alp[Oc[0]]);
    rep(i,C[Oc[0]]-1){
      ans.push_back(alp[Oc[0]]);
      ans.push_back(rem[i]);
    }
    ans += rem.substr(C[Oc[0]]-1);
    return move(ans);
  }

  if(C[Oc[0]] * 2 - 2 == S.size()){
    string rem;
    for(int i=1; i<Oc.size(); i++) rem += string(C[Oc[i]],alp[Oc[i]]);
    string ans;
    ans.push_back(alp[Oc[0]]);
    rep(i,C[Oc[0]]-2){
      ans.push_back(alp[Oc[0]]);
      ans.push_back(rem[i]);
    }
    ans.push_back(alp[Oc[0]]);
    ans += rem.substr(C[Oc[0]]-2);
    return move(ans);
  }

  if(Oc.size() == 2){
    string ans;
    ans.push_back(alp[Oc[0]]);
    ans += string(C[Oc[1]],alp[Oc[1]]);
    ans += string(C[Oc[0]]-1,alp[Oc[0]]);
    return move(ans);
  }
  
  string ans;
  ans.push_back(alp[Oc[0]]);
  ans.push_back(alp[Oc[1]]);
  ans += string(C[Oc[0]]-1,alp[Oc[0]]);
  ans.push_back(alp[Oc[2]]);
  ans += string(C[Oc[1]]-1,alp[Oc[1]]);
  ans += string(C[Oc[2]]-1,alp[Oc[2]]);
  for(int i=3; i<Oc.size(); i++) ans += string(C[Oc[i]],alp[Oc[i]]);
  return move(ans);
}

int main() {
  int T; cin >> T;
  while(T--) cout << testcase() << "\n";
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;