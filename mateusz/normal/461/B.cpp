#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define IOS ios_base::sync_with_stdio(0);

using namespace std;

const int N = 100005, M = 1000000007;
int wynik[N], wynik2[N];
int n, x;
int odw[N], isBlack[N];
vector<int>V[N];
void DFS(int w) {
  odw[w] = 1;
  if(isBlack[w]) {
    wynik[w] = 1;
  }
  else {
    wynik2[w] = 1;
  }
  for(int i = 0; i < V[w].size(); i++) {
    int u = V[w][i];
    if(!odw[u]) {
      DFS(u);
      int tmp;
      tmp = ((LL)wynik2[w] * wynik[u] % M + (LL)wynik[w] * wynik[u] % M) % M + (LL)wynik[w] * wynik2[u] % M;
      tmp %= M;
      wynik2[w] = (LL)wynik2[w] * wynik[u] % M + (LL)wynik2[w] * wynik2[u] % M;
      wynik2[w] %= M;
      wynik[w] = tmp;
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 2; i <= n; i++) {
    scanf("%d", &x);
    V[x + 1].PB(i);
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", &isBlack[i]);
  }
  
  DFS(1);
  
  printf("%d", wynik[1]);
  return 0;
}