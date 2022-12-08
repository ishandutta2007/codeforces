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

const int N = 110;
string t[N];
int trafiony[N];

int main(){
  int n;
  cin >> n;
  REP(i,n) cin >> t[i];
  string s;
  cin >> s;
  string letter;
  cin >> letter;
  int d = SIZE(s);
  REP(i,n) REP(j,d) if (j+SIZE(t[i]) <= d){
    int ok = 1;
    REP(foo,SIZE(t[i])) if (tolower(s[j+foo]) != tolower(t[i][foo])){
      ok = 0;
      break;
    }
    if (ok){
      REP(foo,SIZE(t[i])) trafiony[j+foo] = 1;
    }
  }
  REP(i,d) if (trafiony[i]){
    if (tolower(s[i]) == tolower(letter[0])){
      char co = tolower(letter[0]) == 'a' ? 'b' : 'a';
      if (islower(s[i])) s[i] = tolower(co);
      else s[i] = toupper(co);
    } else {
      if (islower(s[i])) s[i] = tolower(letter[0]);
      else s[i] = toupper(letter[0]);
    }
  }
  cout << s << endl;
  return 0;
}