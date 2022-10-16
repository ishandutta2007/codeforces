#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

int N, M;

struct Move {
  PII from, to;
};

vector<PII> cube_start, cube_end;
vector<Move> moves_start, moves_end, moves_mid;

vector<Move> SetMoves(PII from, PII to) {
  debug("SetMoves", from, to);
  vector<Move> nmoves;
  while (from != to) {
    if (from.st - to.st != 0) {
      int dx = to.st - from.st;
      int dir = dx / abs(dx);
      PII ncube = {from.st + dir, from.nd};
      nmoves.push_back(Move{from, ncube});
      from = ncube;
    }

    if (from.nd - to.nd != 0) {
      int dy = to.nd - from.nd;
      int dir = dy / abs(dy);
      PII ncube = {from.st, from.nd + dir};
      nmoves.push_back(Move{from, ncube});
      from = ncube;
    }
  }
  return nmoves;
}

void MakeMoves(vector<PII> cubes, vector<PII> cube_dests, vector<Move> &result) {
  debug(cubes, cube_dests);
  vector<vector<Move>> nmoves;

  for (int i = 0; i < M; ++i) {
    nmoves.push_back(SetMoves(cubes[i], cube_dests[i]));
    reverse(ALL(nmoves.back()));
  }

  vector<vector<bool>> board(N + 1, vector<bool>(N + 1));
  for (int i = 0; i < M; ++i)
    board[cubes[i].st][cubes[i].nd] = true;

  bool has_move = true;
  while (has_move) {
    has_move = false;
    for (int i = 0; i < M; ++i) {
      if (SZ(nmoves[i]) == 0) { continue; }
      has_move = true;
      auto to_move = nmoves[i].back();
      if (board[to_move.to.st][to_move.to.nd]) { continue; }
      board[to_move.from.st][to_move.from.nd] = false;
      board[to_move.to.st][to_move.to.nd] = true;
      result.push_back(to_move);
      nmoves[i].pop_back();
    }
  }
}

vector<Move> MakePerm(vector<PII> cubes, vector<PII> &end_cubes) {
  vector<Move> moves;

  vector<int> perm(M);
  iota(ALL(perm), 0);

  sort(ALL(perm), [&](int lhs, int rhs) {
        return cubes[lhs] < cubes[rhs];
      });
  vector<PII> cube_dests(M);
  for (int i = 0; i < M; ++i)
    cube_dests[perm[i]] = {i + 1, cubes[perm[i]].nd};

  MakeMoves(cubes, cube_dests, moves);
  cubes = cube_dests;

  sort(ALL(perm), [&](int lhs, int rhs) {
        return PII{cubes[lhs].nd, cubes[lhs].st} < PII{cubes[rhs].nd, cubes[rhs].st};
      });
  for (int i = 0; i < M; ++i)
    cube_dests[perm[i]] = {cubes[perm[i]].st, i + 1};

  MakeMoves(cubes, cube_dests, moves);
  end_cubes = cube_dests;
  return moves;
}

void Shuffle() {
  for (int i = 0; i < M; ++i) {
    for (auto m : SetMoves(cube_start[i],
                           PII{cube_start[i].st, cube_end[i].nd}))
      moves_mid.push_back(m);
    cube_start[i].nd = cube_end[i].nd;
  }
  for (int i = 0; i < M; ++i) {
    for (auto m : SetMoves(cube_start[i],
                           PII{cube_end[i].st, cube_start[i].nd}))
      moves_mid.push_back(m);
    cube_start[i].st = cube_end[i].st;
  }
}

bool cur_board[60][60];

void Out(const vector<Move> &m) {
  debug("Out");
  for (auto &move : m) {
    debug(move.from, move.to);
    assert(cur_board[move.from.st][move.from.nd]);
    cur_board[move.from.st][move.from.nd] = false;
    assert(!cur_board[move.to.st][move.to.nd]);
    cur_board[move.to.st][move.to.nd] = true;
    cout << move.from.st << " " << move.from.nd << " " <<
      move.to.st << " " << move.to.nd << "\n";
  }
}

void Rev(vector<Move> &m) {
  for (auto &move : m) {
    swap(move.from.st, move.to.st);
    swap(move.from.nd, move.to.nd);
  }
  reverse(ALL(m));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N >> M;
  cube_start.resize(M);
  cube_end.resize(M);

  for (auto &&[x, y] : cube_start) { cin >> x >> y; }
  for (auto &&[x, y] : cube_end) { cin >> x >> y; }

  auto real_start = cube_start;
  auto real_end = cube_end;
  for (auto &&[x, y] : real_start) { cur_board[x][y] = true; }

  {
    vector<PII> tmp;
    moves_start = MakePerm(cube_start, tmp);
    cube_start = tmp;
  }
  {
    vector<PII> tmp;
    moves_end = MakePerm(cube_end, tmp);
    cube_end = tmp;
  }

  Shuffle();

  cout << SZ(moves_start) + SZ(moves_end) + SZ(moves_mid) << "\n";
  Out(moves_start);
  Out(moves_mid);
  Rev(moves_end); Out(moves_end);

}