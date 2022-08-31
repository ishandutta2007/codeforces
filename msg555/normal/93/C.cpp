#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
map<vector<int>, vector<int> > parent;
map<vector<int>, string> parentcmd;
set<vector<int> > vis;
queue<vector<int> > q;
vector<int> result;

void tryAdd(const vector<int>& V, int m, const string cmd) {
  if(m > N || m <= V.back()) return;

  vector<int> NV = V;
  NV.push_back(m);
  if(vis.insert(NV).second) {
    q.push(NV);
    parent[NV] = V;
    parentcmd[NV] = cmd;
    if(m == N) result = NV;
  }
}

string getreg(int ind) {
  char buf[8];
  sprintf(buf, "e%cx", 'a' + ind);
  return buf;
}

int main() {
  cin >> N;
  if(N == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector<int> rt(1, 1);
  vis.insert(rt);
  q.push(rt);

  string num[4] = {"1", "2", "4", "8"};
  while(result.empty()) {
    vector<int> V = q.front(); q.pop();
    for(int i = 0; i < V.size(); i++) {
      for(int j = 1; j < 4; j++) {
        tryAdd(V, V[i] * (1 << j),
               getreg(V.size()) + ", [" + num[j] + "*" + getreg(i) + "]");
      }
      for(int j = 0; j < V.size(); j++) {
        for(int k = 0; k < 4; k++) {
          tryAdd(V, V[i] + V[j] * (1 << k),
                 getreg(V.size()) + ", [" + getreg(i) + " + " +
                        num[k] + "*" + getreg(j) + "]");
        }
      }
    }
  }

  vector<string> ret;
  for(vector<int> v = result; !parentcmd[v].empty(); v = parent[v]) {
    ret.push_back(parentcmd[v]);
  }
  cout << ret.size() << endl;
  for(int i = ret.size() - 1; i >= 0; i--) {
    cout << "lea " << ret[i] << endl;
  }
}