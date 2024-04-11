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

const int N = 1100;
string nazwy[N];
int punkty[N], bramki[N], wpuszczone[N];

int numer(string s, int n){
  REP(i,n) if (nazwy[i] == s) return i;
  return -1;
}

int kryt(int a,int b){
  if (punkty[a] != punkty[b]) return punkty[a] > punkty[b];
  int x = bramki[a] - wpuszczone[a];
  int y = bramki[b] - wpuszczone[b];
  if (x != y) return x > y;
  return bramki[a] > bramki[b];
}

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n){
    char txt[100];
    scanf("%s",txt);
    nazwy[i] = string(txt);
  }
  REP(foo,n*(n-1)/2){
    char txt[100], s1[100],s2[100];
    scanf("%s",txt);
    int pos = 0;
    while (txt[pos] != '-') pos++;
    txt[pos] = ' ';
    sscanf(txt,"%s %s",s1,s2);
    int a = numer(s1,n);
    int b = numer(s2, n);

    int x,y;
    scanf("%s",txt);
    sscanf(txt,"%d:%d",&x,&y);
    if (x < y) swap(x,y), swap(a,b);

    bramki[a] += x;
    wpuszczone[a] += y;

    bramki[b] += y;
    wpuszczone[b] += x;

    if (x > y){
      punkty[a] += 3;
    } else {
      punkty[a]++; punkty[b]++;
    }
  }
  VI v;
  REP(i,n) v.PB(i);
  sort(ALL(v), kryt);
  vector<string> res;
  REP(i,n/2) res.PB(nazwy[v[i]]);
  sort(ALL(res));
  REP(i,n/2) printf("%s\n", res[i].c_str());
  return 0;
}