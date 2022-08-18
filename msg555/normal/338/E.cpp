#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN (1 << 18)

int A[150010];
int B[150010];

struct val_type {
  int value;
  int mn_val;
} VAL[2 * MAXN];

void addit(int x, int A, int B, int a, int b, int v) {
  if(a <= A && B <= b) {
    VAL[x].value += v;
    VAL[x].mn_val += v;
    return;
  } else if(b <= A || B <= a) {
    return;
  }

  int M = (A + B) / 2;
  int c1 = 2 * x + 1;
  int c2 = c1 + 1;

  addit(c1, A, M, a, b, v);
  addit(c2, M, B, a, b, v);
  VAL[x].mn_val = VAL[x].value + min(VAL[c1].mn_val, VAL[c2].mn_val);
}

int main() {
  int N, len, H;
  cin >> N >> len >> H;

  for(int i = 0; i < len; i++) {
    cin >> B[i];
  }
  sort(B, B + len);

  for(int i = 0; i < len; i++) {
    addit(0, 0, MAXN, i, MAXN, -1);
  }

  int result = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] = lower_bound(B, B + len, H - A[i]) - B;

    addit(0, 0, MAXN, A[i], MAXN, 1);
    if(i >= len) {
      addit(0, 0, MAXN, A[i - len], MAXN, -1);
    }
    result += VAL[0].mn_val >= 0;
  }

  cout << result << endl;
  return 0;
}