#include <cstring>
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

const int N = 110000;
char txt[N];

VI KMP(const char* wzo) {
#define KMPH(z) while(k>0 && wzo[k+1] != z[q]) k=pre[k]; if(wzo[k+1]== z[q]) k++;
  VI pre(strlen(wzo)+1,0);
  int k=0,q;
  wzo--;
  pre[1]=0;
  for(q=2;wzo[q];q++) {
    KMPH(wzo);
    pre[q]=k;
  }
  return pre;
}


int zawiera(string a, string b){
  string s = b + "#" + a;
  VI v = KMP(s.c_str());
  int start = SIZE(b)+2;
  int end = SIZE(b)+1+SIZE(a);
  FOR(i,start,end) if (v[i] == SIZE(b)){
   // printf("%s zawiera %s\n",a.c_str(), b.c_str());
    return 1;
  }
  return 0;
}

int nakladka(string a, string b){
  string s = b + "#" + a;
  VI v = KMP(s.c_str());
  return v.back();
}

int main(){
  vector<string> v;
  REP(i,3){
    scanf("%s",txt);
    v.PB(string(txt));
  }
  int change = 1;
  while (change){
    change = 0;
    REP(i,SIZE(v)) REP(j,SIZE(v)) if (j != i && zawiera(v[i],v[j])){
      swap(v[j], v.back());
      v.pop_back();
      change = 1;
      goto hell;
    }
hell:
    ;
  }
  if (SIZE(v)==1){
    printf("%d\n",SIZE(v[0]));
    return 0;
  }
  int res = 3 * N;
  VI perm;
  REP(i,SIZE(v)) perm.PB(i);
  do{
    int kand = v[perm[0]].size();
    FOR(i,1,SIZE(v)-1) kand += v[perm[i]].size() - nakladka(v[perm[i-1]],v[perm[i]]);
    res = min(res, kand);
  } while (next_permutation(ALL(perm)));
  printf("%d\n", res);
  return 0;
}