#include <bits/stdc++.h>
using namespace std;

int sc[10][2], flg, A, B, T;

void Solve(int x, int y) {
  memset(sc, 0, sizeof sc);
  
  int a = A, b = B;
  for(int i = 1; i <= x; i++) {
    sc[i][0] = 25;
    sc[i][1] = 0;
    a -= 25;
  }
  for(int i = x + 1; i <= x + y; i++) {
    sc[i][1] = 25;
    sc[i][0] = 0;
    b -= 25;
  }
  if(x + y == 5) {
    if(x == 3) {
      a += 10;
      sc[3][0] = 15;
    } else {
      b += 10;
      sc[5][1] = 15;
    }
  }
  if(a < 0 || b < 0) {
    return;
  }
  int mx = 0, mi = 0;
  for(int i = 1; i <= x; i++) {
    mi -= sc[i][0] - 2;
  }
  for(int i = x + 1; i <= x + y; i++) {
    mx += sc[i][1] - 2;
  }
  if(a - b < mi || a - b > mx) {
    return;
  }
  int w = a - b, add = 0;
  if(w < 0) {
    b += w;
    for(int i = 1; i <= x && w; i++) {
      sc[i][1] = min(sc[i][0] - 2, -w);
      w += sc[i][1];
      if(sc[i][1] == sc[i][0] - 2) {
	add = i;
      }
    }
  } else {
    a -= w;
    for(int i = x + 1; i <= x + y && w; i++) {
      sc[i][0] = min(sc[i][1] - 2, w);
      w -= sc[i][0];
      if(sc[i][0] == sc[i][1] - 2) {
	add = i;
      }
    }
  }
  //cerr << a << " " << b << " " << add << endl;
  if(!add) {
    if((!x || !y) && a) {
      return;
    }
    int ned = min(x ? sc[1][0] - 2 - sc[1][1] : 25,
		  y ? sc[x + 1][1] - 2 - sc[x + 1][0] : 25);
    if(a < ned) {
      sc[1][1] += a;
      sc[x + 1][0] += a;
    } else {
      sc[1][1] += ned;
      sc[x + 1][0] += ned;
      a -= ned;
      add = sc[1][1] == sc[1][0] - 2 ? 1 : x + 1;
    }
  }
  flg = 1; //Find
  if(add) {
    sc[add][0] += a;
    sc[add][1] += a;
  }
  if(x == 3) {
    swap(sc[3][0], sc[x + y][0]);
    swap(sc[3][1], sc[x + y][1]);
  }
  printf("%d:%d\n", x, y);
  for(int i = 1; i <= x + y; i++) {
    printf("%d:%d%c", sc[i][0], sc[i][1], i == x + y ? '\n' : ' ');
  }
  return;
}

int main(void) {
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &A, &B);
    flg = 0;
    for(int i = 0; i < 3 && !flg; i++) {
      Solve(3, i);
    }
    for(int i = 2; ~i && !flg; i--) {
      Solve(i, 3);
    }
    if(!flg) {
      puts("Impossible");
    }
  }
}