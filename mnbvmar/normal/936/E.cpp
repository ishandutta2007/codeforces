#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
//#define int LL
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

struct Line {
  int x, y1, y2;
  friend ostream &operator<<(ostream &os, const Line &L) {
    return os << "(" << L.x << "," << L.y1 << "," << L.y2 << ")";
  }
};

const int MaxN = 3e5 + 100;

vector<Line> Lines;

int N;
vector<PII> Points;
map<PII, int> PtToID;
map<PII, int> PtToLine;
int PtIdToLine[MaxN];
vector<int> AdjCell[MaxN];
vector<int> Adj[MaxN];
bool Forbidden[MaxN];
bool ForbiddenCell[MaxN];
int TreeSize[MaxN];
int CurID;
int Visited[MaxN];
int Dist[MaxN];
int DistWho[MaxN];

vector<tuple<int,int,int>> CentroidInfo[MaxN];

const int Infty = 1e9;

struct DistSet {
  set<pair<int, int>> Data;

  DistSet() {
    Data.emplace(-Infty, 0);
    Data.emplace(Infty, 0);
  }

  void put(int Pos, int Val) {
    auto P = make_pair(Pos, Val);
    auto Iter = Data.lower_bound(P);
    auto PIter = prev(Iter);
    if (abs(Iter->first - Pos) + Iter->second <= Val) { return; }
    if (abs(PIter->first - Pos) + PIter->second <= Val) { return; }
    auto NewIter = Data.insert(Iter, P);
    while (true) {
      auto NextIter = next(NewIter);
      if (abs(NextIter->first - Pos) + Val <= NextIter->second)
        Data.erase(NextIter);
      else
        break;
    }

    while (true) {
      auto PrevIter = prev(NewIter);
      if (abs(PrevIter->first - Pos) + Val <= PrevIter->second)
        Data.erase(PrevIter);
      else
        break;
    }
  }

  int get(int Pos) const {
    auto Iter = Data.lower_bound(make_pair(Pos, 0));
    auto PIter = prev(Iter);
    return min(abs(Iter->first - Pos) + Iter->second,
               abs(PIter->first - Pos) + PIter->second);
  }
};

DistSet DistSets[MaxN];


void dfsSizes(int v, int p) {
  TreeSize[v] = 1;
  for (int s : Adj[v]) {
    if (Forbidden[s]) { continue; }
    if (s == p) { continue; }
    dfsSizes(s, v);
    TreeSize[v] += TreeSize[s];
  }
}

int findCentroid(int v) {
  dfsSizes(v, v);
  int p = v;
  int sz = TreeSize[v];
  debug(v, sz);

  while (true) {
    bool Found = false;
    for (int s : Adj[v]) {
      if (Forbidden[s]) { continue; }
      if (s == p) { continue; }
      if (TreeSize[s] * 2 >= sz) {
        p = v;
        v = s;
        Found = true;
        break;
      }
    }

    if (!Found) { break; }
  }

  return v;
}


void runBfsLine(int v) {
  ++CurID;
  auto &L = Lines[v];
  queue<int> Q;
  int MinID = PtToID[make_pair(L.x, L.y1)];
  debug(MinID);
  for (int i = L.y1; i <= L.y2; ++i) {
    Visited[MinID] = CurID;
    Dist[MinID] = 0;
    DistWho[MinID] = i;
    Q.push(MinID++);
  }

  while (!Q.empty()) {
    int c = Q.front();
    Q.pop();
    for (int s : AdjCell[c]) {
      if (ForbiddenCell[s]) { continue; }
      if (Visited[s] == CurID) { continue; }
      Q.push(s);
      Visited[s] = CurID;
      Dist[s] = Dist[c] + 1;
      DistWho[s] = DistWho[c];
      CentroidInfo[s].emplace_back(v, Dist[s], DistWho[s]);
      debug(s, v, Dist[s], DistWho[s]);
    }
  }

}

void makeCentroids(int v) {
  int Centr = findCentroid(v);
  debug(v, Centr);

  runBfsLine(Centr);


  Forbidden[Centr] = true;
  auto &L = Lines[Centr];
  int MinID = PtToID[make_pair(L.x, L.y1)];
  for (int i = L.y1; i <= L.y2; ++i)
    ForbiddenCell[MinID++] = true;

  for (int s : Adj[Centr])
    if (!Forbidden[s])
      makeCentroids(s);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x, y;
    cin >> x >> y;
    Points.emplace_back(x, y);
  }

  sort(ALL(Points));
  debug(Points);

  int CurX = Points[0].first, CurY = Points[0].second, StartY = Points[0].second;
  for (int i = 1; i < N; ++i) {
    if (Points[i] != make_pair(CurX, CurY + 1)) {
      Lines.push_back(Line{CurX, StartY, CurY});
      StartY = Points[i].second;
    }
    CurX = Points[i].first;
    CurY = Points[i].second;
  }
  Lines.push_back(Line{CurX, StartY, CurY});

  debug(Lines);
  int PtId = 0;
  for (int i = 0; i < SZ(Lines); ++i) {
    auto &L = Lines[i];
    for (int y = L.y1; y <= L.y2; ++y) {
      PtToID[make_pair(L.x, y)] = PtId;
      PtToLine[make_pair(L.x, y)] = i;
      PtIdToLine[PtId++] = i;
    }
  }

  for (int i = 0; i < SZ(Points); ++i) {
    const int DirsX[4] = {0, 1, 0, -1};
    const int DirsY[4] = {1, 0, -1, 0};
    int x = Points[i].first, y = Points[i].second;
    for (int d = 0; d < 4; ++d) {
      int px = x + DirsX[d],
          py = y + DirsY[d];
      auto Iter = PtToLine.find(make_pair(px, py));
      if (Iter != PtToLine.end()) {
        int a = PtIdToLine[i];
        int b = Iter->second;
        if (a != b)
          Adj[a].push_back(b);
        AdjCell[i].push_back(PtToID[make_pair(px, py)]);
      }
    }
  }

  int S = SZ(Lines);
  for (int i = 0; i < S; ++i) {
    sort(ALL(Adj[i]));
    Adj[i].resize(unique(ALL(Adj[i])) - Adj[i].begin());
    debug(i, Adj[i]);
  }

  makeCentroids(0);

  int Q;
  cin >> Q;
  bool Any1 = false;
  for (int i = 0; i < Q; ++i) {
    int Type, x, y;
    cin >> Type >> x >> y;
    int CellID = PtToID[make_pair(x, y)];
    int LineID = PtToLine[make_pair(x, y)];

    if (Type == 1) {
      Any1 = true;
      DistSets[LineID].put(y, 0);
      for (auto &X : CentroidInfo[CellID]) {
        int NewLineID, LineDist, LinePos;
        tie(NewLineID, LineDist, LinePos) = X;
        DistSets[NewLineID].put(LinePos, LineDist);
      }
    } else {
      if (!Any1) {
        cout << "-1\n";
        continue;
      }
      int Result = 1e9;
      mini(Result, DistSets[LineID].get(y));
      for (auto &X : CentroidInfo[CellID]) {
        int NewLineID, LineDist, LinePos;
        tie(NewLineID, LineDist, LinePos) = X;
        mini(Result, DistSets[NewLineID].get(LinePos) + LineDist);
      }
      cout << Result << "\n";
    }
  }
}