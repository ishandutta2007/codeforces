#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int P[3]; /* Parent */
int POS[3]; /* Position */
int JUMP[3];
int THROW[3];

bool JUMPED[3];
int THROWN[3];

char DP[50*50*50*5*5*5*2*2*2];

int solve() {
  if(POS[0] < 1 || POS[1] < 1 || POS[2] < 1) return 0;

  int s = 0;
  for(int i = 0; i < 3; i++) {
    s *= 50;
    s += POS[i];
    s *= 5;
    s += THROWN[i] + 2;
    s *= 2;
    s += JUMPED[i];
  }
  if(DP[s] != -1) return DP[s];

  int res = max(POS[0], max(POS[1], POS[2]));
  for(int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    int k = (j + 1) % 3;
    if(P[i] != -1) continue; /* Being held */
    if(!JUMPED[i] && THROWN[i] < 0) {
      /* Try to jump */
      JUMPED[i] = true;
      int ppp = POS[i];
      for(POS[i] = ppp - JUMP[i]; POS[i] <= ppp + JUMP[i]; POS[i]++) {
        if(POS[i] == POS[j] || POS[i] == POS[k]) continue;
        res = max(res, solve());
      }
      POS[i] = ppp;
      JUMPED[i] = false;
    }
    if(THROWN[i] == -1) {
      /* Try to pick up */
      for(int ii = 0; ii < 2; ii++) {
        int v = ii ? j : k;
        if(P[v] != -1) continue; /* Being held */
        if(!(POS[v] + 1 == POS[i] || POS[i] + 1 == POS[v])) continue;

        int oldp = POS[v];
        POS[v] = POS[i];
        P[v] = i;
        THROWN[i] = v;
        res = max(res, solve());
        THROWN[i] = -1;
        P[v] = -1;
        POS[v] = oldp;
      }
    } else if(THROWN[i] >= 0) {
      /* Try to throw */
      int v = THROWN[i];
      int vv = 3 - i - v;
      int ppp = POS[i];
      
      int op1 = POS[v];
      int op2 = POS[vv];

      P[v] = -1;
      THROWN[i] = -2;
      for(POS[v] = ppp - THROW[i]; POS[v] <= ppp + THROW[i]; POS[v]++) {
        if(POS[v] == POS[i]) continue;

        if(P[vv] == v) POS[vv] = POS[v];
        else if(POS[v] == POS[vv]) continue;

        res = max(res, solve());
      }
      THROWN[i] = v;
      P[v] = i;

      POS[vv] = op2;
      POS[v] = op1;
    }
  }
  return DP[s] = res;
}

int main() {
  memset(DP, -1, sizeof(DP));
  memset(P, -1, sizeof(P));
  memset(THROWN, -1, sizeof(THROWN));
  memset(JUMPED, 0, sizeof(JUMPED));
  for(int i = 0; i < 3; i++) {
    cin >> POS[i] >> JUMP[i] >> THROW[i];
  }
  cout << solve() << endl;
}