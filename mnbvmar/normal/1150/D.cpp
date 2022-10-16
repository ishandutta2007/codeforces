#include <bits/stdc++.h>

using namespace std;

const int AlphaSize = 26;
const int MaxN = 1e5 + 100;
const int MaxM = 256;

int next_occur[MaxN][AlphaSize];
int dp[MaxM][MaxM][MaxM];
string pattern;
string words[3];
int N, Q;

void CreateLinks() {
  for (int i = 0; i < AlphaSize; ++i) {
    next_occur[N][i] = next_occur[N + 1][i] = N;
  }
  for (int pos = N - 1; pos >= 0; --pos) {
    for (int i = 0; i < AlphaSize; ++i) {
      next_occur[pos][i] = (pattern[pos] == 'a' + i ? pos : next_occur[pos + 1][i]);
    }
  }
}

void RecomputeDp(int a, int b, int c) {
  int &val = dp[a][b][c];
  val = N;
  if (a) { val = min(val, next_occur[dp[a-1][b][c] + 1][words[0][a-1] - 'a']); }
  if (b) { val = min(val, next_occur[dp[a][b-1][c] + 1][words[1][b-1] - 'a']); }
  if (c) { val = min(val, next_occur[dp[a][b][c-1] + 1][words[2][c-1] - 'a']); }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q >> pattern;
  CreateLinks();

  dp[0][0][0] = -1;

  for (int i = 0; i < Q; ++i) {
    char type;
    int word_id;
    cin >> type >> word_id;
    --word_id;
    if (type == '+') {
      char ch;
      cin >> ch;
      words[word_id] += ch;
      int max0 = words[0].size(), max1 = words[1].size(), max2 = words[2].size();
      int min0 = word_id == 0 ? max0 : 0;
      int min1 = word_id == 1 ? max1 : 0;
      int min2 = word_id == 2 ? max2 : 0;

      for (int a = min0; a <= max0; ++a) {
        for (int b = min1; b <= max1; ++b) {
          for (int c = min2; c <= max2; ++c) {
            RecomputeDp(a, b, c);
          }
        }
      }
    } else {
      words[word_id].pop_back();
    }

    bool answer = dp[words[0].size()][words[1].size()][words[2].size()] < N;
    cout << (answer ? "YES\n" : "NO\n");
  }
}