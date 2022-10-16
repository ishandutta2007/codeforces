#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).begin())

/////////////////////////////////////////////////////////

const int MaxItems = 15005,
          MaxK = 1005,
          MaxQueries = 30005,
          Base = (1<<15),
          TreeSize = (1<<16),
          P = (int)(1e7+19),
          Q = (int)(1e9+7);

int N, K;
vector<int> addQueries[TreeSize];
int itemFrom[MaxItems], itemTo[MaxItems], itemCost[MaxItems], itemMass[MaxItems];
int result[TreeSize][MaxK];


void input(){
  ios_base::sync_with_stdio(0);
  cin >> N >> K;
  for(int i = 1; i <= N; i++){
    cin >> itemCost[i] >> itemMass[i];
    itemFrom[i] = 1;
  }
}


void add_tree(int id, int from, int to){
  from += Base; to += Base;
  addQueries[from].push_back(id);
  if(from != to) addQueries[to].push_back(id);
  while(from/2 != to/2){
    if(from % 2 == 0) addQueries[from+1].push_back(id);
    if(to % 2 == 1) addQueries[to-1].push_back(id);
    from /= 2; to /= 2;
  }
}


void traverse_tree(int v){
  for(int i = 0; i <= K; i++){
    result[v][i] = result[v/2][i];
  }

  for(int item : addQueries[v]){
    debug(v, item);
    int cost = itemCost[item],
        mass = itemMass[item];

    for(int i = K; i >= mass; i--){
      result[v][i] = max(result[v][i], result[v][i-mass] + cost);
    }
  }

  if(v < Base){
    traverse_tree(v * 2);
    traverse_tree(v * 2 + 1);
  }
}


int main(){
  input();

  int numCheck = 0;
  int Qrs;
  cin >> Qrs;
  fill(itemTo, itemTo+MaxItems, -1);

  for(int query = 1; query <= Qrs; query++){
    int type;
    cin >> type;
    debug(type);
    if(type == 1){
      N++;
      cin >> itemCost[N] >> itemMass[N];
      itemFrom[N] = numCheck+1;
    } else if(type == 2){
      int who;
      cin >> who;
      itemTo[who] = numCheck;
    } else {
      numCheck++;
    }
  }

  for(int item = 1; item <= N; item++){
    if(itemTo[item] == -1) itemTo[item] = numCheck;
    if(itemFrom[item] > itemTo[item]) continue;
    add_tree(item, itemFrom[item], itemTo[item]);
  }

  traverse_tree(1);

  for(int query = 1; query <= numCheck; query++){
    int total = 0, pwr = 1;
    for(int i = 1; i <= K; i++){
      total = (int)((total + (LL)result[query+Base][i] * pwr) % Q);
      pwr = (int)(((LL)pwr * P) % Q);
    }
    cout << total << "\n";
  }

}