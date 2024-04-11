#include <bits/stdc++.h>

using namespace std;

vector<array<int, 10>> ch;
vector<array<int, 10>> go;
vector<int> link;
vector<bool> terminal;

int newNode() {
   int v = ch.size();
   ch.emplace_back();
   go.emplace_back();
   link.emplace_back();
   terminal.emplace_back();
   return v;
}
void add(vector<int> str) {
   int v = 0;
   for (int c : str) {
      if (ch[v][c] == 0) {
         int nv = newNode();
         ch[v][c] = nv;
      }
      v = ch[v][c];
   }
   terminal[v] = true;
}

void build() {
   queue<int> bfs;
   link[0] = 0;
   bfs.emplace(0);
   while (!bfs.empty()) {
      int v = bfs.front(); bfs.pop();
      if (terminal[link[v]]) terminal[v] = true;
      for (int c = 0; c < 10; ++c) {
         go[v][c] = go[link[v]][c];
         if (ch[v][c]) {
            link[ch[v][c]] = go[v][c];
            go[v][c] = ch[v][c];
            bfs.emplace(ch[v][c]);
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   string S; cin >> S;
   int X; cin >> X;
   newNode();
   for (int mask = (1 << X)+1; mask < (1 << (X+1)); mask+=2) {
      int all = 0;
      int cur_mask = mask;
      while (cur_mask) {
         if (cur_mask&1) all |= cur_mask;
         cur_mask >>= 1;
      }
      bool kek = false;
      for (int z = 1; z < X; ++z) if (X % z == 0 && (all & (1 << z))) kek = true;
      if (kek) continue;
      vector<int> arr;
      for (int i = 0; i <= X; ++i) if (mask& (1<<i)) arr.emplace_back(i);
      for (int i = arr.size()-1; i > 0; --i) arr[i] -= arr[i-1];
      for (int z : arr) if (z >= 10) kek = true;
      if (kek) continue;
      arr.erase(arr.begin());
      add(arr);
   }
   build();
   int M = go.size();
   const int INF = 1e9;
   vector<int> dp(M, INF);
   dp[0] = 0;
   for (char c : S) {
      c -= '0';
      vector<int> ndp(M, INF);
      for (int z = 0; z < M; ++z) {
         if (dp[z] == INF) continue;
         ndp[z] = min(ndp[z], dp[z]+1);
         if (!terminal[go[z][c]]) {
            int nz = go[z][c];
            ndp[nz] = min(ndp[nz], dp[z]);
         }
      }
      dp = ndp;
   }
   cout << *min_element(dp.begin(), dp.end()) << '\n';
   return 0;
}