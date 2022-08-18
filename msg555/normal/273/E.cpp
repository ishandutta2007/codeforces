#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

//unsigned char G[1000000010];

int DP[1010][4];

int A[] = {
1, 0,
3, 1,
4, 2,
5, 1,
7, 2,
9, 0,
13, 1,
15, 2,
19, 0,
27, 1,
39, 2,
40, 0,
57, 2,
58, 1,
81, 2,
85, 0,
120, 2,
121, 1,
174, 2,
179, 0,
255, 2,
260, 1,
363, 2,
382, 0,
537, 2,
544, 1,
780, 2,
805, 0,
1146, 2,
1169, 1,
1632, 2,
1718, 0,
2415, 2,
2447, 1,
3507, 2,
3622, 0,
5154, 2,
5260, 1,
7341, 2,
7730, 0,
10866, 2,
11011, 1,
15780, 2,
16298, 0,
23190, 2,
23669, 1,
33033, 2,
34784, 0,
48894, 2,
49549, 1,
71007, 2,
73340, 0,
104352, 2,
106510, 1,
148647, 2,
156527, 0,
220020, 2,
222970, 1,
319530, 2,
330029, 0,
469581, 2,
479294, 1,
668910, 2,
704371, 0,
990087, 2,
1003364, 1,
1437882, 2,
1485130, 0,
2113113, 2,
2156822, 1,
3010092, 2,
3169669, 0,
4455390, 2,
4515137, 1,
6470466, 2,
6683084, 0,
9509007, 2,
9705698, 1,
13545411, 2,
14263510, 0,
20049252, 2,
20318116, 1,
29117094, 2,
30073877, 0,
42790530, 2,
43675640, 1,
60954348, 2,
64185794, 0,
90221631, 2,
91431521, 1,
131026920, 2,
135332446, 0,
192557382, 2,
196540379, 1,
274294563, 2,
288836072, 0,
405997338, 2,
411441844, 1,
589621137, 2,
608996006, 0,
866508216, 2,
884431705, 1,
1000000001, -1,
};

#define MOD 1000000007

int addm(int x, int y) {
  x += y;
  if(x >= MOD) x -= MOD;
  return x;
}

int main() {
/*
  G[0] = G[1] = G[2] = 0;
  for(int i = 3; i < sizeof(G); i++) {
    vector<int> V;
    V.push_back(G[i / 3]);
    V.push_back(G[i - i / 3]);
    sort(V.begin(), V.end());
    for(G[i] = 0; binary_search(V.begin(), V.end(), G[i]); G[i]++);
    if(G[i] != G[i - 1]) cout << i << ", " << (int)G[i] << "," << endl;
  }
return 0;
*/

  int N, P; cin >> N >> P;
  P--;

  int num[4] = {0};
  for(int i = 0; A[i] <= P; i += 2) {
    int mx = min(P, A[i + 2] - 1);
    num[A[i + 1]] = addm(num[A[i + 1]],
          (1ll * (P - A[i] + 1) * (P - A[i] + 2) / 2 -
           1ll * (P - mx) * (P - mx + 1) / 2) % MOD);
  }

  DP[0][0] = 1;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        DP[i][j ^ k] = addm(DP[i][j ^ k], (1ll * DP[i - 1][j] * num[k]) % MOD);
      }
    }
  }

  cout << addm(DP[N][1], addm(DP[N][2], DP[N][3])) << endl;
  return 0;
}