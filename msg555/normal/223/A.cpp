#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int P[100010];
char STK[100010];
int CNT[100010];

int main() {
  int fl = -1;
  memset(P, -1, sizeof(P));

  int dep = 0;
  string S; cin >> S;
  vector<pair<int, pair<int, int> > > sol;
  sol.push_back(make_pair(0, make_pair(0, 0)));
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '[' || S[i] == '(') {
      STK[dep] = S[i];
      if(P[dep] <= fl) P[dep] = i;
      dep++;
    } else {
      if(dep == 0 || (S[i] == ')') != (STK[dep - 1] == '(')) {
        fl = i;
        dep = 0;
        continue;
      }
      P[dep] = -1;
      sol.push_back(make_pair(0, make_pair(P[--dep], i + 1)));
    }
  }

  for(int i = CNT[0] = 0; i < S.size(); i++) {
    CNT[i + 1] = CNT[i] + (S[i] == '[');
  }
  for(int i = 0; i < sol.size(); i++) {
    sol[i].first = CNT[sol[i].second.second] - CNT[sol[i].second.first];
  }
  sort(sol.begin(), sol.end());

  pair<int, int> res = sol.back().second;
  cout << sol.back().first << endl;
  //if(res.second)
    cout << S.substr(res.first, res.second - res.first) << endl;
  
  return 0;
}