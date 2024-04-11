#include <cstdio>

using namespace std;

const int BLOCK_SIZE = 31, MAXN = 3000;
int inmasks[MAXN][(MAXN/BLOCK_SIZE)+1], outmasks[MAXN][(MAXN/BLOCK_SIZE)+1];
int cache[1<<16];

void addEdge(int a, int b) {
  int a1 = a/BLOCK_SIZE, a2 = a%BLOCK_SIZE;
  inmasks[b][a1] |= 1l << a2;
  int b1 = b/BLOCK_SIZE, b2 = b%BLOCK_SIZE;
  outmasks[a][b1] |= 1l << b2;
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  int SZ = (N/BLOCK_SIZE)+1;
  cache[0] = 0;
  for (int i = 1; i < 1<<16; i++)
    cache[i] = cache[i-(i&-i)]+1;

  for (int i = 0, a, b; i < M; i++) {
    scanf("%d%d", &a, &b);
    a--; b--;
    addEdge(a, b);
  }
  long long res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int common = 0;
      for(int k = 0; k < SZ; k++) {
        unsigned long long m = inmasks[i][k]&outmasks[j][k];
        while (m > 0) {
          common += cache[(int)(m&((1<<16)-1))];
          m>>=16;
        }
      }
      res += common * (common-1) / 2;
    }
  }
  printf("%d\n", res);
  return 0;
}