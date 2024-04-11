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

const int N = 2100;
char txt[N];

string przerob(string s){
  string res;
  int n = SIZE(s);
  int i = 0;
  while (i < n){
    if (s[i] == '+' || s[i] == '-'){
      res += '+';
      i++;
      continue;
    }
    if (s[i] == '*' || s[i] == '/'){
      res += '*';
      i++;
      continue;
    }
    res += 'x';
    while (i < n && isdigit(s[i])) i++;
  }
  return res;
}

const int MOD = 1000003;
int t[N][N];
int mogezamykac[N][N];
int nastepnyx[N];

int main(){
  scanf("%s",txt);
  string s = przerob(string(txt));
  if (s=="x"){
    cout << 1 << endl;
    return 0;
  }
  //cout << s << endl;
  t[0][0] = 1;
  int n = SIZE(s);
  nastepnyx[n] = n+1;
  FORD(i,n-1,0) if (s[i] == 'x') nastepnyx[i] = i;
  else if (s[i] == '*') nastepnyx[i] = n+1;
  else nastepnyx[i] = nastepnyx[i+1];

  s += "+++++";

  FOR(i,0,n){
    FORD(j,N-1,0) if (mogezamykac[i][j]){
      t[i+1][j+1] = (t[i+1][j+1] + mogezamykac[i][j]) % MOD;
      if (j > 0) mogezamykac[i][j-1] = (mogezamykac[i][j-1] + mogezamykac[i][j]) % MOD;
    }
    REP(j,N) {
      if (t[i][j]){
        //zjadlem i znakow i jestem na poziomie j

        //jeden argument
        if (s[i] == '+') t[i+1][j+1] = (t[i+1][j+1] + t[i][j])%MOD;

        int gdzie = nastepnyx[i];
        if (s[i]=='x'){
          //dwa argumenty; otwieram
          t[gdzie+2][j+1] = (t[gdzie+2][j+1] + t[i][j]) % MOD;
        }

        if (s[i]=='x' && j > 0){
          //dwa argumenty; zjadam
          //t[gdzie+1][j-1] = (t[gdzie+1][j-1] + t[i][j]) % MOD;
          mogezamykac[gdzie+1][j-1] = (mogezamykac[gdzie+1][j-1] + t[i][j]) % MOD;
        }
      }
    }
  }

//  FOR(i,0,n) FOR(j,0,n) printf("t[%d][%d]=%d\n",i,j,t[i][j]);

  cout << mogezamykac[n][0] << endl;
  return 0;
}