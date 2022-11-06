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
const int N = 100005, czapa = 131072;
int drz[2 * czapa];
int n, m, reversed, poc, kon, type, p, a, b;

void insert(int poz, int w) {
  poz += czapa;
  while(poz >= 1) {
    drz[poz] += w;
    poz /= 2;
  }
}

void add(int pos) {
  if(!reversed) {
    pos += poc;
    for(int j = 1; j <= pos - poc; j++) {
      insert(pos + j - 1, drz[pos - j + czapa]);
    }
    poc = pos;
  }
  else {
    pos = kon - pos;
    for(int j = 1; j + pos <= kon; j++) {
      insert(pos - j, drz[pos + j - 1 + czapa]);
    } 
    kon = pos;
  }
}
void add_reversed(int pos) {
  if(!reversed) {
    pos = kon - pos - poc;
    reversed = 1;
  }
  else {
    pos = kon - pos - poc;
    reversed = 0;
  }
  add(pos);
}



int query(int poza, int pozb) {
  poza += czapa;
  pozb += czapa;
  int ret = drz[poza];
  if(poza != pozb) ret += drz[pozb];
  while(poza / 2 != pozb / 2) {
    if(poza % 2 == 0) ret += drz[poza + 1];
    if(pozb % 2 == 1) ret += drz[pozb - 1];
    poza /= 2;
    pozb /= 2;
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  
  for(int i = 0; i <= n; i++) {
    insert(i, 1);
  }
  poc = 0;
  kon = n;
  while(m--) {
    scanf("%d", &type);
    if(type == 1) {
      scanf("%d", &p);
      if(p > (kon - poc) / 2) {
    add_reversed(p);
      }
      else {
    add(p);
      }
    }
    else {
      scanf("%d %d", &a, &b);
      if(reversed) {
    int tmp = a;
    a = kon - b;
    b = kon - tmp;
      }
      else {
    a = poc + a;
    b = poc + b;
      }
//       cerr<<a<<" "<<b<<endl;
      printf("%d\n", query(a, b - 1));
    }
//     cerr<<poc<<" "<<kon<<" "<<reversed<<endl;
  }
  
  return 0;
}