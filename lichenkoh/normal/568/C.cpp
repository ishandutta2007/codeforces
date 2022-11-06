#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll MAXN=202;
bitset<2*MAXN> graph[2*MAXN];
int used[2*MAXN], comp[2*MAXN], order[2*MAXN], res[2*MAXN], cnt = 0;
int twosat_num_vars;
void dfs1(int u) { used[u] = true;
	int n = 2*twosat_num_vars;
  for (int v = 0; v < n; v++) {
    if (graph[u][v]&&!used[v]) dfs1(v); }
  order[cnt++] = u; }
void dfs2(int u, int color) {
	int n = 2*twosat_num_vars;
	comp[u] = color;
  for (int v = 0; v < n; v++) {
    if (graph[v][u] && comp[v] == -1) dfs2(v, color); } }
bool twosat() { int n = 2*twosat_num_vars;
  for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
  for (int i = 0, color = 0; i < n; i++) {
    int u = order[n-i-1];
    if (comp[u] == -1) dfs2(u, color++); }
  for (int i = 0; i < n; i++) if (comp[i] == comp[i^1]) return false;
  for (int i = 0; i < n; i+=2) res[i/2] = (comp[i] > comp[i^1]);
  return true; }
//if type = 0, we add the edge x -> y, if type = 1, we add the edge ~x -> y
//if type = 2, we add the edge x -> ~y, if type = 3, we add the edge ~x -> ~y
//NOTE: each implication and its dual implication is also added, so NO need to
//add twice for each implication.
void add(int x, int y) {graph[x][y]=true;}
void rm(int x, int y) {graph[x][y]=false;}
void add_edge(int x, int y, int type) { int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
	//printf("ae: %d %d %d\n",x,y,type);
  switch (type) {
    case 0: add(a,b); add(nb, na); break;
    case 1: add(na, b); add(nb, a); break;
    case 2: add(a, nb); add(b, na); break;
    case 3: add(na, nb); add(b,a); break; } }

void rm_edge(int x, int y, int type) { int a=2*x, na=2*x+1, b=2*y, nb=2*y+1;
	//printf("ae: %d %d %d\n",x,y,type);
  switch (type) {
    case 0: rm(a,b); rm(nb, na); break;
    case 1: rm(na, b); rm(nb, a); break;
    case 2: rm(a, nb); rm(b, na); break;
    case 3: rm(na, nb); rm(b,a); break; } }

const ll mn=MAXN;
int assign[mn];
char _c2type[mn];
char _word[mn];
int word[mn];
int c2type[mn];
int n,m,alphasz;
const ll mr=4*mn*mn;
int pos1[mr],t1[mr],pos2[mr],t2[mr];
bool putfirst() {
  for (int i=0;i<m;i++) {
  	add_edge(pos1[i],pos2[i],(t2[i]<<1)|t1[i]);
  }
}
bool solve(ll vars) {
	twosat_num_vars = vars;
  memset(order, 0, sizeof order);
  memset(comp, -1, sizeof comp);
  memset(used, 0, sizeof used);
  cnt=0;
  /* Custom code starts here */
  for (int x=0;x<vars;x++) {
  	//printf("x:%d assign:%d\n",x,assign[x]);
  	if (assign[x]!=-1) {
  		if (assign[x]) add_edge(x,x,2);
  		else add_edge(x,x,1);
  	}
  }
  /* Ends here */
  bool ans=twosat();
  for (int x=0;x<vars;x++) {
  	//printf("x:%d assign:%d\n",x,assign[x]);
  	if (assign[x]!=-1) {
  		if (assign[x]) rm_edge(x,x,2);
  		else rm_edge(x,x,1);
  	}
  }
  return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%s\n",_c2type);
	alphasz=strlen(_c2type);
	for (int c=0;c<alphasz;c++) c2type[c]=(_c2type[c]=='V')?1:0;
	scanf("%d %d\n",&n,&m);
	for (int i=0;i<m;i++) {
		char ct1,ct2;
		scanf("%d %c %d %c\n",&pos1[i],&ct1,&pos2[i],&ct2);
		--pos1[i]; --pos2[i];
		t1[i]=(ct1=='V');
		t2[i]=(ct2=='V');
		//printf("%d %c %d %c\n",pos1[i],ct1,pos2[i],ct2);
	}
	scanf("%s\n",_word);
	for (int x=0;x<n;x++) {
		word[x]=_word[x]-'a';
		assign[x]=c2type[word[x]];
	}
	putfirst();
	if (solve(n)) {
		printf("%s\n",_word);
		return 0;
	}
	bool can=false;
	int hit=-1;
	for (int x=n-1;x>=0;x--) {
		bool t2can[2];
		for (int t=0;t<2;t++) {
			assign[x]=t;
			t2can[t]=solve(n);
		}
		for (int c=word[x]+1;c<alphasz;c++) {
			if (t2can[c2type[c]]) {
				can=true;
				hit=x;
				assign[x]=c2type[c];
				word[x]=c;
				break;
			}
		}
		if (can) break;
		//printf("x:%d to -1\n",x);
		assign[x]=-1;
	}
	if (!can) {
		printf("-1\n");
		return 0;
	}
	for (int x=hit+1;x<n;x++) {
		bool t2can[2];
		for (int t=0;t<2;t++) {
			assign[x]=t;
			t2can[t]=solve(n);
		}
		bool ok=false;
		for (int c=0;c<alphasz;c++) {
			if (t2can[c2type[c]]) {
				ok=true;
				assign[x]=c2type[c];
				word[x]=c;
				//printf("x:%d gets c:%d t:%d\n",x,c,c2type[c]);
				break;
			}
		}
		if (!ok) {
			printf("-1\n"); return 0;
		}
		//assert(ok);
	}
	for (int x=0;x<n;x++) {
		_word[x]=word[x]+'a';
	}
	printf("%s\n",_word);
}