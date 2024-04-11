#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

bool vis[100000];
int A[100000];

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
  }
  memset(vis, 0, sizeof(vis));
  vector<vector<int> > C;
  for(int i = 0; i < N; i++) {
    if(vis[i]) continue;
    int x = i;
    vector<int> cyc;
    do {
      vis[x] = true;
      cyc.push_back(x);
      x = A[x];
    } while(x != i);
    if(cyc.size() > 1) C.push_back(cyc);
  }

  vector<vector<pair<int, int> > > S;
  for(int i = 0; i < C.size(); i++) {
    vector<int>& cyc = C[i];
    while(cyc.size() >= 4) {
      vector<pair<int, int> > s;
      if(cyc.size() <= 5) {
        for(int i = 0; i < cyc.size(); i++) {
          s.push_back(make_pair(cyc[i], cyc[(i + 1) % cyc.size()]));
        }
        cyc.resize(0);
      } else {
        for(int i = cyc.size() - 5; i + 1 < cyc.size(); i++) {
          s.push_back(make_pair(cyc[i], cyc[i + 1]));
        }
        s.push_back(make_pair(cyc[cyc.size() - 1], cyc[cyc.size() - 5]));

        cyc.resize(cyc.size() - 4);
        //cyc.back() = s.back().first;
      }
      S.push_back(s);
    }
  }

  vector<vector<int> > TWOS;
  vector<vector<int> > THREES;
  for(int i = 0; i < C.size(); i++) {
    if(C[i].size() == 2) TWOS.push_back(C[i]);
    if(C[i].size() == 3) THREES.push_back(C[i]);
  }

  {
    int i;
    for(i = 0; i < TWOS.size() && i < THREES.size(); i++) {
      vector<pair<int, int> > s;
      for(int j = 0; j < 2; j++) {
        s.push_back(make_pair(TWOS[i][j], TWOS[i][(j + 1) % 2]));
      }
      for(int j = 0; j < 3; j++) {
        s.push_back(make_pair(THREES[i][j], THREES[i][(j + 1) % 3]));
      }
      S.push_back(s);
    }

    while(i < TWOS.size()) {
      vector<pair<int, int> > s;
      for(int j = 0; j < 2; j++) {
        s.push_back(make_pair(TWOS[i][j], TWOS[i][(j + 1) % 2]));
      }
      i++;
      if(i < TWOS.size()) for(int j = 0; j < 2; j++) {
        s.push_back(make_pair(TWOS[i][j], TWOS[i][(j + 1) % 2]));
      }
      i++;
      S.push_back(s);
    }

    while(i < THREES.size()) {
      vector<pair<int, int> > s;
      for(int j = 0; j < 3; j++) {
        s.push_back(make_pair(THREES[i][j], THREES[i][(j + 1) % 3]));
      }
      i++;
      if(i + 1 < THREES.size()) {
        vector<pair<int, int> > s2;
        for(int j = 0; j < 3; j++) {
          s2.push_back(make_pair(THREES[i][j], THREES[i][(j + 1) % 3]));
        }
        i++;
        s2.push_back(make_pair(THREES[i][1], THREES[i][2]));
        s2.push_back(make_pair(THREES[i][2], THREES[i][1]));
        s.push_back(make_pair(THREES[i][0], THREES[i][1]));
        s.push_back(make_pair(THREES[i][1], THREES[i][0]));
        i++;
        S.push_back(s2);
      }
      S.push_back(s);
    }
  }

  printf("%d\n", S.size());
  for(int i = 0; i < S.size(); i++) {
    vector<pair<int, int> >& s = S[i];
    printf("%d\n", s.size());
    for(int j = 0; j < s.size(); j++) {
      if(j) printf(" ");
      printf("%d", s[j].first + 1);
    }
    printf("\n");
    for(int j = 0; j < s.size(); j++) {
      if(j) printf(" ");
      printf("%d", s[j].second + 1);
    }
    printf("\n");
  }
}