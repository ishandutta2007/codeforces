#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> V;

void gen(int dig) {
  for(int i = 1; i <= dig; i++) {
    for(int j = 0; j < 1 << i; j++) {
      int num = 0;
      for(int k = 0; k < i; k++) {
        num *= 10;
        num += (j & 1 << k) ? 7 : 4;
      }
      V.push_back(num);
    }
  }
  sort(V.begin(), V.end());
}

int L0, L1, H0, H1, K;

int main() {
  gen(9);
  cin >> L0 >> H0 >> L1 >> H1 >> K; H0++; H1++;

  long long result = 0;
  for(int ii = 0; ii < 2; ii++) {
    for(int i = K - 1; i < V.size(); i++) {
      if(V[i] > H0) break;
      int LR0 = max(L0, V[i]);
      int HR0 = min(H0, i + 1 < V.size() ? V[i + 1] : 1000000010);
      int LR1 = max(L1, i - K >= 0 ? V[i - K] + 1 : 0);
      int HR1 = min(H1, V[i - K + 1] + 1);
      if(HR0 < LR0 || HR1 < LR1) continue;
      result += 1ll * (HR0 - LR0) * (HR1 - LR1);
    }
    swap(L0, L1);
    swap(H0, H1);
  }
  if(K == 1) {
    for(int i = 0; i < V.size(); i++) {
      if(L0 <= V[i] && V[i] < H0 &&
         L1 <= V[i] && V[i] < H1) {
        result--;
      }
    }
  }
  printf("%.12lf\n", 1.0 * result / (H0 - L0) / (H1 - L1));
  return 0;
}