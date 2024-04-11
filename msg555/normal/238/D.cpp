#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

string S;
int SKP[100010][2];

int next_char(int cp, int dp) {
  if(cp == -1 || cp == S.size() || S[cp]) return cp;
  return (SKP[cp][dp == 1 ? 1 : 0] = next_char(SKP[cp][dp == 1 ? 1 : 0], dp));
}

void delete_char(int cp) {
  S[cp] = 0;
}

int main() {
  int N, M; cin >> N >> M;
  cin >> S;
  S = string("0") + S + "0";

  for(int i = 0; i < S.size(); i++) {
    SKP[i][0] = i - 1;
    SKP[i][1] = i + 1;
  }

  vector<int> epos(M, -1);
  vector<int> ipos(M, -1);
  vector<vector<int> > ireg(M);
  vector<vector<int> > ereg(M);

  set<int> starts;
  map<int, vector<int> > enter;
  map<int, set<int> > exit;
  for(int i = 0; i < M; i++) {
    cin >> ipos[i] >> epos[i]; epos[i]++;
    starts.insert(ipos[i]);
    enter[ipos[i]].push_back(i);
  }
  
  vector<int> regs(10, 0);
  while(!starts.empty()) {
    int strt = *starts.begin();
    int cp = strt;
    int dp = 1;

    while(strt <= cp) {
      vector<int>& V = enter[cp];
      for(int i = 0; i < V.size(); i++) {
        ireg[V[i]] = regs;
        exit[epos[V[i]]].insert(V[i]);
        exit[next_char(ipos[V[i]] - 1, -1)].insert(V[i]);
      }
      V.clear();
      starts.erase(cp);

      if('0' <= S[cp] && S[cp] <= '9') {
        regs[S[cp] - '0']++;
        if(S[cp]-- == '0') {
          delete_char(cp);
        }
        cp = next_char(cp + dp, dp);
      } else if(S[cp] == '<' || S[cp] == '>') {
        dp = S[cp] == '<' ? -1 : 1;
        int ncp = next_char(cp + dp, dp);
        if(S[ncp] == '<' || S[ncp] == '>') {
          delete_char(cp);
        }
        cp = ncp;
      }

      if(cp == S.size()) break;

      set<int>& st = exit[cp];
      while(!st.empty()) {
        int ind = *st.begin();
        ereg[ind] = regs;
        exit[epos[ind]].erase(ind);
        exit[next_char(ipos[ind] - 1, -1)].erase(ind);
      }
    }
  }

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < 10; j++) {
      if(j) cout << ' ';
      cout << ereg[i][j] - ireg[i][j];
    }
    cout << endl;
  }
  return 0;
}