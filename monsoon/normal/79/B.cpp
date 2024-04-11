#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int K = 10000;
const char name[][20] = {"Carrots","Kiwis","Grapes","Waste"};
int rows,cols,k,q;
pair<int,int> cel[K];

int main() {
  scanf("%d%d%d%d",&rows,&cols,&k,&q);
  REP(i,k) {
    int r,c; scanf("%d%d",&r,&c); --r; --c;
    cel[i] = make_pair(r,c);
  }
  sort(cel,cel+k);
  REP(i,q) {
    int r,c; scanf("%d%d",&r,&c); --r; --c;
    int bad = lower_bound(cel,cel+k,make_pair(r,c)) - cel;
    int good = cols*r + c - bad;
    int type = cel[bad] == make_pair(r,c) ? 3 : good % 3;
    puts(name[type]);
  }
}