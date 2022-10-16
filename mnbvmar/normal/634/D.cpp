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
#define SZ(x) ((int)(x).size())

/////////////////////////////////////////////////////////

const int MaxM = 200005;

int D, N, M;
int position[MaxM], dist[MaxM], cost[MaxM], numLeft[MaxM];

void input(){
  cin >> D >> N >> M;

  vector<pair<int,int>> V(M);
  for (int i = 0; i < M; i++) {
    cin >> V[i].first >> V[i].second;
    //cin >> position[i] >> cost[i];
  }

  sort(ALL(V));
  for (int i = 1; i <= M; i++) {
    position[i] = V[i - 1].first;
    cost[i]     = V[i - 1].second;
    dist[i - 1] = position[i - 1] - position[i];
  }

  dist[M] = D - position[M];
  position[M + 1] = D;

  fill(numLeft, numLeft + M + 1, N);
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  input();

  int cheapestPtr = 0;
  set<pair<int,int>> statOrder;
  LL total = 0;

  for (int reach = 0; reach <= M; reach++) {
    int curPos = position[reach], needPos = position[reach + 1];

    statOrder.emplace(cost[reach], reach);

    while (curPos < needPos) {
      if (statOrder.size() == 0) {
        cout << "-1\n";
        return 0;
      }

      auto P = *statOrder.begin(); statOrder.erase(statOrder.begin());
      if (P.second < cheapestPtr) { continue; }
      cheapestPtr = P.second;

      int whereEnd = min(needPos, position[P.second] + N);

      total += (LL)(whereEnd - curPos) * P.first;
      curPos = whereEnd;

      if (whereEnd >= needPos) {
        statOrder.emplace(P.first, P.second);
      }
    }

  }

  cout << total << "\n";
}