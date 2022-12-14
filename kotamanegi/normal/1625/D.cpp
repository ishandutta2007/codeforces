#include "bits/stdc++.h"
using namespace std;

typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a, b) for (long long(a) = 0; (a) < (b); ++(a))
#define ALL(x) (x).begin(), (x).end()

#define int long long
vector<int> judge(vector<pair<vector<int>,vector<int>>> tmps,int k,int Spos){
  int ca = -1;
  for (int i = Spos; i >= 0; --i)
  {
    vector<pair<vector<int>, vector<int>>> N;
    for (auto x : tmps)
    {
      vector<int> next_go[2][2];
      REP(t,2){
        REP(j,x.first.size()){
          ca = x.first[j];
          if (x.first[j] & (1LL << i))
          {
            next_go[t][1].push_back(x.first[j]);
          }
          else
          {
            next_go[t][0].push_back(x.first[j]);
          }
        }
        swap(x.first, x.second);
      }
      if((1 << i) & k){
        if(next_go[0][0].size() != 0 and next_go[1][1].size() != 0){
          N.push_back({next_go[0][0], next_go[1][1]});
        }
        if(next_go[1][0].size() != 0 and next_go[0][1].size() != 0){
          N.push_back({next_go[1][0], next_go[0][1]});
        }
      }else{
        if(next_go[0][0].size() != 0 and next_go[1][1].size() != 0){
          return {next_go[0][0][0], next_go[1][1][0]};
        }
        if(next_go[1][0].size() != 0 and next_go[0][1].size() != 0){
          return {next_go[1][0][0], next_go[0][1][0]};
        }
        N.push_back(x);
      }
    }
    tmps = N;
  }
  if(tmps.size() != 0){
    return {tmps[0].first[0], tmps[0].second[0]};
  }
  return {ca};
}
void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> inputs;
  map<int, int> validator;
  REP(i, n)
  {
    int a;
    cin >> a;
    if(validator[a] != 0)
      continue;
    validator[a] = i + 1;
    inputs.push_back(a);
  }
  if(k == 0){
    cout << n << endl;
    REP(i,n){
      if(i != 0)
        cout << " ";
      cout << i + 1;
    }
    cout << endl;
    return;
  }
  vector<int> ans;
  vector<vector<int>> cur;
  cur.push_back(inputs);
  for (int i = 30; i >= 0;--i){
    vector<vector<int>> nexts;
    for(auto x:cur){
      vector<int> next_go[2];
      REP(j,x.size()){
        if(x[j] & (1LL << i)){
          next_go[1].push_back(x[j]);
        }else{
          next_go[0].push_back(x[j]);
        }
      }
      if((1 << i) & k){
        if(next_go[0].size() == 0 and next_go[1].size() == 0)
          continue;
        if(next_go[0].size() == 0){
          ans.push_back(next_go[1][0]);
          continue;
        }
        if(next_go[1].size() == 0){
          ans.push_back(next_go[0][0]);
          continue;
        }
        vector<int> go = judge({{next_go[0], next_go[1]}}, k, i + 1);
        for (auto y : go)
        {
          ans.push_back(y);
        }
      }
      else
      {
        REP(j,2){
          if(next_go[j].size() != 0)
            nexts.push_back(next_go[j]);
        }
      }
    }
    cur = nexts;
  }
  REP(i,cur.size()){
    REP(q,cur[i].size()){
      ans.push_back(cur[i][q]);
    }
  }
  if(ans.size() == 1){
    cout << -1 << endl;
  }else{
    cout << ans.size() << endl;
    REP(i,ans.size()){
      if(i != 0)
        cout << " ";
      cout << validator[ans[i]];
    }
    cout << endl;
  }
}
#undef int

// generated by oj-template v4.7.2
// (https://github.com/online-judge-tools/template-generator)
int main() {
  // Fasterize input/output script
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(100);
  // scanf/printf user should delete this fasterize input/output script

  int t = 1;
  // cin >> t; // comment out if solving multi testcase
  for (int testCase = 1; testCase <= t; ++testCase) {
    solve();
  }
  return 0;
}