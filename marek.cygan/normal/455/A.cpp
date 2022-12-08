#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

const int N = 110 * 1010;
int t[N];

LL z[N];
LL bez[N];

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n) {
    int x;
    scanf("%d",&x);
    t[x]++;
  }
  FOR(i,1,N-1) {
    z[i] = bez[i-1] + (LL)i * (LL)t[i];
    bez[i] = max(bez[i-1], z[i-1]);
  }
  LL res = 0;
  res = max(z[N-1],bez[N-1]);
  cout << res << endl;
  return 0;
}