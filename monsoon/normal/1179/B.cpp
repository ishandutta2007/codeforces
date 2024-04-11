#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int rows,cols;
vector<pair<int,int> > v;

int main() {
  scanf("%d%d",&rows,&cols);

  REP(i,rows/2) {
    REP(j,cols) {
      v.push_back(make_pair(i,j));
      v.push_back(make_pair(rows-1-i,cols-1-j));
    }
  }
  if (rows%2) {
    REP(j,cols) {
      int jj = j%2 ? cols-1-j/2 : j/2;
      v.push_back(make_pair(rows/2, jj));
    }
  }

  REP(i,rows*cols) {
    printf("%d %d\n",v[i].first+1,v[i].second+1);
  }
}