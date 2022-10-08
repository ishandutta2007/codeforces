#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

struct STedge;
struct STvertex{
    map<char,STedge> g; //krawedzie do synow
    STvertex *f; //suffix link
    int numer; //numer sufiksu (0 to cale slowo, -1 oznacza ze wierzcholek nie jest lisciem)
    PII zakres; //indeksy w tablicy suftab reprezentujace zakres lisci do ktorych mozna dojsc z danego wierzcholka
};
struct STedge{
    int l,r; //x[l]..x[r] to fragment tekstu reprezentujacy krawedz
    STvertex *v;
};
namespace SuffixTree {
  STvertex *root;
  const char *tEKST;
  int liscie; //liczba utworzonych lisci
  //sprowadzenie trojki (reprezentowanej jako krawedz) do postaci kanonicznej
  inline void Canonize(STedge &k, const char *x){
    if (k.l>k.r) return;
	  STedge e=k.v->g[ x[k.l] ];
	  while (e.r-e.l<=k.r-k.l){
      k.l+=e.r-e.l+1; k.v=e.v;
      if (k.l<=k.r) e=k.v->g[ x[k.l] ];
    }
  }
  inline bool Split(STvertex* &w, const STedge &k) {
    w=k.v;
    if (k.l<=k.r) {
	    char c=tEKST[k.l];
	    STedge e=k.v->g[c];
	    if (tEKST[k.r+1]==tEKST[e.l+k.r-k.l+1]) return true;
	    k.v->g[c].r = (e.l+=k.r-k.l+1) -1; k.v->g[c].v = (w=new STvertex);
      w->numer=-1; w->g[tEKST[e.l]] = e;
	    return false;
    }
    return k.v->g.find(tEKST[k.l])!=k.v->g.end();
  }
  void Update(STedge &k, int n){
    STvertex *oldr = root, *w;
    while (!Split(w,k)){
	    STedge e;
	    e.v=new STvertex; e.l=k.r+1; e.r=n-1; e.v->numer=liscie++; //tworzymy nowy lisc
	    w->g[tEKST[k.r+1]]=e;
	    if (oldr!=root) oldr->f=w;
	    oldr=w; k.v=k.v->f; Canonize(k,tEKST);
    }
    if (oldr!=root) oldr->f=k.v;
  }
  //budowanie drzewa sufiksowego dla tekstu x dlugosci n
  //liscie nie maja suffix linka, mozna go latwo dorobic w procedurze update
  //pokazujac na poprzednio stworzony lisc
  STvertex* Create(const char *x, int n){
    STvertex *top; //pinezka
    STedge e;
    top = new STvertex; root = new STvertex; tEKST = x;
    top->numer = root->numer = -1; e.v = root;
    REP(i,n){ e.r=e.l=-i; top->g[x[i]]=e; }
    root->f=top; e.l=liscie=0; e.v=root;
    REP(i,n){ e.r=i-1; Update(e,n); e.r++; Canonize(e,x);}
    return root;
  }
};
void STDelete(STvertex *w){
    FOREACH(it,w->g) STDelete(it->ND.v);
    delete w;
}
int Create_suftab(STvertex *w, int *suftab, int beg){
  int acc=0;
  if (w->numer+1) {suftab[beg]=w->numer; acc=1;}
  else FOREACH(it,w->g) acc+=Create_suftab(it->ND.v,suftab,beg+acc);
  w->zakres=MP(beg,beg+acc-1);
  return acc;
}


int suftab[100005];
char s[100005];
int n;

LL result;

void dfs(STvertex* v) {
	FOREACH (it, v->g) {
		LL cur = it->second.v->zakres.second - it->second.v->zakres.first + 1;
		int len = it->ND.r - it->ND.l + 1;
		cur = (cur * (cur + 1)) / 2;
		result += len * cur;
		dfs(it->ND.v);
	}
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	s[n++] = '#';
	STvertex* root = SuffixTree::Create(s, n);
	Create_suftab(root, suftab, 0);
	dfs(root);
	cout << result - n << endl;
}