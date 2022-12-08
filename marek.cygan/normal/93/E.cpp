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

const int N = 103;
const int M = 2000000;

LL t1[M];
LL t2[M];
LL t3[M];

int krot1[M], krot2[M];
int krot3[M];

int main(){
  LL n;
  int k;
  cin >> n >> k;
  int r = 1;
  t1[0] = n; krot1[0] = 1;
  REP(i,k){
    int x;
    cin >> x;
    REP(j,r) t2[j] = t1[j] / x, krot2[j] = -krot1[j];

    int a = 0, b = 0;
    int w = 0;
    while (a < r && b < r){
      if (t1[a] < t2[b]){
        t3[w] = t1[a];
        krot3[w++] = krot1[a++];
      } else if (t1[a] > t2[b]){
        t3[w] = t2[b];
        krot3[w++] = krot2[b++];
      } else {
        krot1[a] += krot2[b++];
      }
    }
    while (a < r){
      t3[w] = t1[a];
      krot3[w++] = krot1[a++];
    }
    while (b < r){
      t3[w] = t2[b];
      krot3[w++] = krot2[b++];
    }
    r = w;
    REP(j,r) t1[j] = t3[j], krot1[j] = krot3[j];
  }
  LL res = 0;
  REP(i,r) res += t1[i] * krot1[i];
  cout << res << endl;
  return 0;
}