#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MOD 1000000007

string S;
int DP[1000010];
int psumx[1000010];
int psumb[1000010];
int psumw[1000010];
int POW2[1000010];

int derl[1000010];
int derr[1000010];

void partials(int N) {
  psumx[0] = psumb[0] = psumw[0] = 0;
  for(int i = 0; i < N; i++) {
    psumx[i + 1] = psumx[i] + (S[i] == 'X' ? 1 : 0);
    psumb[i + 1] = psumb[i] + (S[i] == 'B' ? 1 : 0);
    psumw[i + 1] = psumw[i] + (S[i] == 'W' ? 1 : 0);
  }
}

void calc_der(int* der, int N, int K, char loc, char rem) {
  partials(N);
  der[0] = 1;
  int run = 1;
  int sz = 1;
  for(int i = 0; i < N; i++) {
    if(S[i] == rem) {
      sz = 1;
    } else {
      sz++;
      if(S[i] == 'X') {
        run += der[i];
        if(run >= MOD) run -= MOD;
      }
    }
    if(sz > K) {
      run -= i - K + 1 == 0 ? 1 :
          (S[i - K] == loc ? 0 : der[i - K]);
      if(run < 0) run += MOD;
      sz--;
    }
    der[i + 1] = run;
  }
}

int main() {
  int N, K; cin >> N >> K;
  cin >> S;

  for(int i = POW2[0] = 1; i <= N; i++) {
    POW2[i] = 2 * POW2[i - 1];
    if(POW2[i] >= MOD) POW2[i] -= MOD;
  }

  reverse(S.begin(), S.end());
  calc_der(derr, N, K, 'W', 'B');
  reverse(S.begin(), S.end());
  calc_der(derl, N, K, 'B', 'W');
  reverse(derr, derr + N + 1);

  int res = 0;
  int lft = 0;
  for(int i = K; i + K <= N; i++) {
    if(S[i - 1] == 'X') lft = (lft * 2) % MOD;

    if(psumw[i - K] == psumw[i] && (i - K == 0 || S[i - K - 1] != 'B')) {
      lft = (lft + (i - K == 0 ? 1 : derl[i - K - 1])) % MOD;
    }

    if(psumb[i + K] != psumb[i]) continue;
    if(i + K < N && S[i + K] == 'W') continue;

    res = (res + 1ll * lft * (i + K < N ? derr[i + K + 1] : 1)) % MOD;
  }

  cout << res << endl;
}