#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
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

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream &os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ", "; return os << "]";
}
template<class A, class B, class C> ostream &operator<<(ostream &os, tuple<A,B,C> T) {
  return os << "(" << get<0>(T) << ", " << get<1>(T) << ", " << get<2>(T) << ")";
}
template<class A, class B> ostream &operator<<(ostream &os, pair<A, B> T) {
  return os << "(" << T.first << ", " << T.second << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(CC) {cerr<<#CC<<"=";for(auto&cc:CC)cerr<<cc<<",";cerr<<endl;}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(CC) {}
#define cerr if(0)cout
#endif


const int Mod = 1e9 + 7;

vector<vector<int>> treeAdj;
vector<vector<int>> treeDecomposition;
map<vector<int>, int> kTuples;
int N, K;

int addToDecomp(const vector<int>& node, int parent) {
  int id = (int)treeDecomposition.size();
  treeDecomposition.push_back(node);

  treeAdj.emplace_back();
  if (parent >= 0) {
    treeAdj[parent].push_back(id);
    treeAdj[id].push_back(parent);
  }

  /* Add all K-tuples to the map. */
  for (int mask = 0; mask < (1 << (int)node.size()); mask++) {
    if (__builtin_popcount(mask) == K) {
      vector<int> nTuple;
      for (int i = 0; i < (int)node.size(); i++) {
        if (mask & (1 << i)) { nTuple.push_back(node[i]); }
      }
      kTuples[nTuple] = id;
    }
  }

  return id;
}


void readAndMakeDecomposition() {
  cin >> N >> K;
  /* Start with singleton set and a K-clique. */
  addToDecomp(vector<int>(1, 1), -1);
  vector<int> firstNode(K);
  iota(ALL(firstNode), 1);
  addToDecomp(firstNode, 0);

  /* Read vertices. We know we connect to the clique, so it
   * should be among the K-tuples. */
  for (int vert = K + 1; vert <= N; vert++) {
    vector<int> connection(K);
    for (int i = 0; i < K; i++) { cin >> connection[i]; }
    sort(ALL(connection));

    auto iter = kTuples.find(connection);
    assert(iter != kTuples.end());
    int id = iter->second;

    /* Add new node, connected with the one containing the clique. */
    vector<int> newNode(connection);
    newNode.push_back(vert);
    addToDecomp(newNode, id);
  }
}


/*****************************************************************************/
vector<vector<int>> allOrderedParts;
map<vector<int>, int> orderedParts;
/* (i, j, k): ordered part. of type 'i', when merged with type 'j', gives us
 * type 'k'. */
vector<tuple<int, int, int>> mergeInfo;
/* (i, j) -> k: insert 'j'-th element in 'i'-th partition, what do we get? */
vector<vector<int>> insertInfo;
/* j -> (i, k, x): remove element from 'j'-th position in 'i'-th partition, possibly
 *                 joining with some parts before; we can get partition id 'k';
 *                 we needed at least 'x' elements before. */
vector<vector<tuple<int, int, int>>> removeInfo;


/* Normalize a vector so that first occurence of 'i' is increasing in 'i'. */
void normalize(vector<int> &partition) {
  int values[10], cnt = 0;
  for (int i = 0; i < 10; i++) { values[i] = -1; }
  for (int &v : partition) {
    if (values[v] == -1) { values[v] = cnt++; }
    v = values[v];
  }
}

inline bool tryConnect(vector<int> &partition, int va, int vb) {
  if (va == vb) { return false; }
  for (int &v : partition) {
    if (v == va) { v = vb; }
  }
  return true;
}

bool tryMerge(vector<int> &merged, vector<int> merger) {
  assert(merged.size() == merger.size());
  int S = (int)merger.size();

  vector<bool> isMerged(S, false);
  for (int i = 0; i < S; i++) {
    if (isMerged[i]) { continue; }
    for (int j = i + 1; j < S; j++) {
      if (merger[i] == merger[j]) {
        isMerged[j] = true;
        if (!tryConnect(merged, merged[j], merged[i])) { return false; }
      }
    }
  }

  normalize(merged);
  return true;
}

/* Get all ordered partitions and compositions of them. */
void createPartitions() {
  function<void(vector<int>)> recurse;

  recurse = [&](vector<int> vec) {
    if ((int)vec.size() == K + 1) {
      normalize(vec);
      if (!orderedParts.count(vec)) {
        int S = (int)orderedParts.size();
        orderedParts[vec] = S;
        allOrderedParts.push_back(vec);
      }
      return;
    }

    int S = (int)vec.size();
    vec.push_back(0);
    for (int i = 0; i <= S; i++) {
      vec.back() = i;
      recurse(vec);
    }
  };

  recurse(vector<int>());
}


void createPartitionMerges() {
  int nParts = (int)orderedParts.size();
  cerr << nParts << endl;

  for (int i = 0; i < nParts; i++) {
    for (int j = 0; j < nParts; j++) {
      vector<int> partI = allOrderedParts[i];
      if (tryMerge(partI, allOrderedParts[j])) {
        mergeInfo.emplace_back(i, j, orderedParts[partI]);
      }
    }
  }

  cerr << mergeInfo.size() << endl;
}


void createPartitionInsertions() {
  int nParts = (int)orderedParts.size();
  insertInfo.resize(nParts, vector<int>(K + 1, -1));

  for (int i = 0; i < nParts; i++) {
    vector<int> data = allOrderedParts[i];
    /* Last one should be non-existent. */
    if (count(ALL(data), data.back()) != 1) { continue; }

    for (int pos = 0; pos <= K; pos++) {
      vector<int> ndata(data);
      ndata.insert(ndata.begin() + pos, 9);
      ndata.pop_back();
      normalize(ndata);

      insertInfo[i][pos] = orderedParts[ndata];
    }
  }
}


void createPartitionRemovals() {
  int nParts = (int)orderedParts.size();
  removeInfo.resize(K + 1);

  for (int i = 0; i < nParts; i++) {
    vector<int> data = allOrderedParts[i];

    for (int pos = 0; pos <= K; pos++) {
      /* Try to remove elem at Kth position. Try all mergers. */
      for (int mask = 0; mask < (1 << (K + 1)); mask++) {
        if (mask & (1 << pos)) { continue; }
        vector<int> ndata(data);
        bool fail = false;

        int maxJ = -1;

        for (int j = 0; j <= K; j++) {
          if (mask & (1 << j)) {
            maxJ = max(maxJ, j);
            if (!tryConnect(ndata, ndata[j], ndata[pos])) {
              fail = true;
              break;
            }
          }
        }

        /* Not done correctly? Cannot continue. */
        if (fail) { continue; }

        /* Removed element should not be alone. */
        if (count(ALL(ndata), ndata[pos]) == 1) { continue; }

        ndata.erase(ndata.begin() + pos);
        ndata.push_back(9);
        normalize(ndata);

        removeInfo[pos].emplace_back(i, orderedParts[ndata], maxJ + 1);
      }
    }
  }
}


void getAllBells() {
  createPartitions();
  createPartitionMerges();
  createPartitionRemovals();
  createPartitionInsertions();
}

using DPType = vector<int>;
vector<DPType> result;
vector<bool> visited;
int AllAloneId;

void runDp(int vert) {
  visited[vert] = true;

  vector<int> thisNode = treeDecomposition[vert];
  result[vert][AllAloneId] = 1;

  for (int child : treeAdj[vert]) {
    if (visited[child]) { continue; }

    runDp(child);
    vector<int> childNode = treeDecomposition[child];
    DPType childRes = result[child];

    debug(vert, child, childNode, childRes);

    /* Remove until becomes a subset. */
    bool changed;
    do {
      changed = false;
      for (int i = 0; i < SZ(childNode); i++) {
        int v = childNode[i];
        if (count(ALL(thisNode), v) != 0) { continue; }
        changed = true;
        DPType tmpRes = childRes;
        fill(ALL(childRes), 0);

        for (auto conv : removeInfo[i]) {
          int from, to, needElems;
          tie(from, to, needElems) = conv;
          if (SZ(childNode) < needElems) { continue; }
          childRes[to] = (childRes[to] + tmpRes[from]) % Mod;
        }

        childNode.erase(childNode.begin() + i);
        break;
      }
      debug("removals", childNode, childRes);
    } while (changed);


    /* Insert until becomes thisNode. */
    while (childNode != thisNode) {
      int pos = 0;
      while (pos < SZ(childNode) && childNode[pos] == thisNode[pos]) { pos++; }
      DPType tmpRes = childRes;
      fill(ALL(childRes), 0);
      for (int from = 0; from < SZ(tmpRes); from++) {
        int to = insertInfo[from][pos];
        childRes[to] = (childRes[to] + tmpRes[from]) % Mod;
      }

      childNode.insert(childNode.begin() + pos, thisNode[pos]);
    }

    debug("insertions", childNode, childRes);

    /* Merge with current node. */
    DPType tmpMerge = result[vert];
    fill(ALL(result[vert]), 0);

    for (auto data : mergeInfo) {
      int from1, from2, to;
      tie(from1, from2, to) = data;
      result[vert][to] = (result[vert][to] + (LL)tmpMerge[from1] * childRes[from2]) % Mod;
    }
  }

  debug(vert, result[vert]);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);

  readAndMakeDecomposition();
  getAllBells();

  debug(allOrderedParts);
  debug(mergeInfo);
  debug(removeInfo);
  debug(insertInfo);

  vector<int> V(K + 1);
  iota(ALL(V), 0);
  AllAloneId = orderedParts[V];

  result.resize(treeAdj.size(), DPType(allOrderedParts.size()));
  visited.resize(treeAdj.size());
  runDp(0);
  cout << result[0][AllAloneId] << "\n";
}