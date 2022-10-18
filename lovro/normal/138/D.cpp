#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tr1/unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define foreach(i,c) for ( typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i )
#define debug(x) cerr << #x << " = " << (x) << endl;

struct State {
  signed char Lmin, Lmax, Rmin, Rmax;

  friend bool operator==(const State &s1, const State &s2) {
    return memcmp(&s1, &s2, sizeof s1) == 0;
  }
  friend bool operator!=(const State &s1, const State &s2) {
    return memcmp(&s1, &s2, sizeof s1) != 0;
  }

  State& setLmin(int L) { Lmin = L; return *this; }
  State& setLmax(int L) { Lmax = L; return *this; }
  State& setRmin(int R) { Rmin = R; return *this; }
  State& setRmax(int R) { Rmax = R; return *this; }
};

struct StateHasher {
  unsigned operator()(const State &S) const {
    unsigned res = 0;
    res |= (unsigned char)S.Lmin; res <<= 8;
    res |= (unsigned char)S.Lmax; res <<= 8;
    res |= (unsigned char)S.Rmin; res <<= 8;
    res |= (unsigned char)S.Rmax;
    return res;
  }
};

int R, C;
char board[20][21];
typedef tr1::unordered_map<State, int, StateHasher> MemoMap;
MemoMap memo[2];

inline int getL(int x, int y) { return x+y; }
inline int getR(int x, int y) { return x-y; }

vector<char> seen_stack[128];

int calc(int mod, const State &state, int depth) {
  pair<MemoMap::iterator, bool> insert_res = memo[mod].insert(make_pair(state, 0));
  int &ret = insert_res.first->second;
  if (!insert_res.second) {
    return ret;
  }

  vector<char> &seen = seen_stack[depth]; seen.clear();
  for (int y=0; y<R; ++y) {
    for (int x=0; x<C; ++x) {
      if ((x+y) % 2 != mod) {
        continue;
      }

      int L = getL(x, y), R = getR(x, y);

      if (L < state.Lmin || L > state.Lmax ||
          R < state.Rmin || R > state.Rmax) {
        continue;
      }

      int sg;
      if (board[y][x] == 'L') {
        sg =
          calc(mod, State(state).setLmin(L+1), depth+1) ^
          calc(mod, State(state).setLmax(L-1), depth+1);
      } else if (board[y][x] == 'R') {
        sg =
          calc(mod, State(state).setRmin(R+1), depth+1) ^
          calc(mod, State(state).setRmax(R-1), depth+1);
      } else {
        sg =
          calc(mod, State(state).setLmin(L+1).setRmin(R+1), depth+1) ^
          calc(mod, State(state).setLmax(L-1).setRmin(R+1), depth+1) ^
          calc(mod, State(state).setLmin(L+1).setRmax(R-1), depth+1) ^
          calc(mod, State(state).setLmax(L-1).setRmax(R-1), depth+1);
      } 

      if (sg >= (int)seen.size()) {
        seen.resize(sg+1, 0);
      }
      seen[sg] = 1;
    }
  }

  for (ret=0; ret<(int)seen.size() && seen[ret]; ++ret) ;
  return ret;
}

int main() {
  cin.sync_with_stdio(0);

  cin >> R >> C;
  for (int i=0; i<R; ++i) {
    cin >> board[i];
  }

  State S;
  S.Lmin = getL(0, 0);
  S.Lmax = getL(C-1, R-1);
  S.Rmin = getR(0, R-1);
  S.Rmax = getR(C-1, 0);

  cout << (calc(0, S, 0) ^ calc(1, S, 0) ? "WIN\n" : "LOSE\n");
}