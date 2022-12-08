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

const int K = 26;

struct Node{
  Node *wezly[K];
  Node() {
    REP(i,K) wezly[i] = NULL;
  }
  int imp, mis;
};

const int N = 110 * 1010;
char txt[N];

void licz(Node *x) {
  x->imp = 0;
  x->mis = 0;
  int moves = 0;
  REP(i,K) if (x->wezly[i] != NULL) {
    licz(x->wezly[i]);
    if (x->wezly[i]->imp == 0) x->imp=1;
    if (x->wezly[i]->mis == 0) x->mis=1;
    moves++;
  }
  if (moves == 0) x->mis = 1;
}

int main(){
  Node *root = new Node;
  int n, k;
  scanf("%d %d",&n,&k);
  REP(i,n) {
    scanf("%s",txt);
    Node *x = root;
    int pos = 0;
    while (txt[pos]) {
      int c = txt[pos] - 'a';
      if (x->wezly[c] == NULL) x->wezly[c] = new Node;
      x = x->wezly[c];
      pos++;
    }
  }

  licz(root);

//  printf("root.imp = %d root.mis = %d\n", root->imp, root->mis);
  if ((root->imp && root->mis) || (root->imp && root->mis == 0 && k%2)) puts("First");
  else puts("Second");

  return 0;
}