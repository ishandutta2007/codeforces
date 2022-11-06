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

const int N = 505;
int n, m, k, cnt, vis;
bool odw[N][N];
int st[N][N];
char plansza[N][N];
priority_queue<pair<int, pair<int, int> > >Q;
bool uzyty[N][N];

bool mozna(int x, int y) {
  if(plansza[x][y] == '.' && !odw[x][y]) return true;
  return false;
}

void DFS(int x, int y) {
  odw[x][y] = 1;
  vis++;
  if(vis == cnt - k) return;
  if(mozna(x - 1, y)) {
    DFS(x - 1, y);
    if(vis == cnt - k) return;
  }
  if(mozna(x + 1, y)) {
    DFS(x + 1, y);
    if(vis == cnt - k) return;
  }
  if(mozna(x, y - 1)) {
    DFS(x, y - 1);
    if(vis == cnt - k) return;
  }
  if(mozna(x, y + 1)) {
    DFS(x, y + 1);
    if(vis == cnt - k) return;
  }
}

int main() {
  scanf("%d %d %d", &n, &m ,&k);
  for(int i = 1; i <= n; i++) {
    scanf("%s", &plansza[i][1]);
  }
  cnt = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(plansza[i][j] == '.') {
    cnt++;
      }
    }
  }
  int tak = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(plansza[i][j] == '.') {
    DFS(i, j);
    tak = 1;
    break;
      }
    }
    if(tak) break;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(plansza[i][j] == '.' && !odw[i][j]) plansza[i][j] = 'X';
    }
  }
 
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      printf("%c", plansza[i][j]);
    }
    printf("\n");
  }
  return 0;
}