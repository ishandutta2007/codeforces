#define NDEBUG
#include <climits>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}

struct Vertex {
  vector<int> adj;
  int upper, lower;
};

Vertex vx[200005];
int nleaves = 0;

void dfs(int a) {
  Vertex& st = vx[a];
  if (st.adj.empty()) {
    ++nleaves;
    st.upper = st.lower = 1;
    return;
  }

  st.upper = 0;
  st.lower = INT_MAX;
  for (int b : st.adj) {
    dfs(b);
    st.upper += vx[b].lower;
    makemin(st.lower, vx[b].upper);
  }
  // fprintf(stderr, "a = %d, upper = %d, lower = %d\n", a, st.upper, st.lower);
}

int main() {
  ios_base::sync_with_stdio(false);

  int V;
  cin >> V;
  deque<int> edges;
  repeat (V-1) {
    int a, b;
    cin >> a >> b;
    vx[a].adj.push_back(b);
  }
  dfs(1);
  cout << nleaves+1-vx[1].lower << ' ' << vx[1].upper << '\n';
}