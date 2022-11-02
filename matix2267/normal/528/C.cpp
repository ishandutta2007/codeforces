#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;
const int MAXM = MAXN;

pii edges[MAXM];

	int n;           // IN: liczba wierzcholkow
	vi adj[MAXN];    // IN: lista sasiedztwa (numery krawedzi)
	int edgx[MAXM];  // IN: xor nr wierzcholkow incydentnych z krawedzia
	int cc;          // OUT: dlugosc cyklu Eulera
	int cycle[MAXM]; // OUT: kolejne krawedzie na cyklu Eulera
	char used[MAXM]; // tylko gdy nieskierowane
	int ep, sp, cur[MAXN], stackedge[MAXM];

	// znajduje maks sciezke eulera z v
	void search(int v) {
		sp=0;
		while(1) {
			while(cur[v] != adj[v].size()) {
				int e = adj[v][cur[v]++];
				if(used[e]) continue; used[e]=1; // nieskierowane
				stackedge[sp++]=e;
				v ^= edgx[e];
			}
			sp--;
			if(sp<0) break;
			cycle[cc++]=stackedge[sp];
			v ^= edgx[stackedge[sp]];
		}
	}

	// znajduje pokrycie sciezkowe calego grafu
	// najlepiej na wstepie zapewnic ze deg(v)%2==0
	// wtedy dla kazdej spojnej znajdzie cykl
	void compute_cycle() {
		fru(v,n) search(v);
		// cykl gdy spojny i cc==ep
	}

	void addedge(int a,int b)
	{
		edges[ep] = pii(a,b);
		edgx[ep] = a^b;
		adj[a].push_back(ep);
		adj[b].push_back(ep); // tylko dla nieskierowanych
		ep++;
	}

	void clear()
	{
		fru(i,n) adj[i].clear();
		cc=0; ep=0; sp=0;
		fru(i,n) cur[i]=0;
		// trzeba jeszcze wyczyscic used
	}

int deg[MAXN];

void solve() {
	int m;
	scanf("%d%d",&n,&m);
	fru(i,m) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		deg[a]++; deg[b]++;
		addedge(a,b);
	}
	int prdeg=-1;
	fru(i,n) {
		if(deg[i]%2==1) {
			if(prdeg==-1) prdeg=i;
			else {
				addedge(prdeg, i);
				prdeg=-1;
			}
		}
	}
	assert(prdeg==-1);
	compute_cycle();
//	fru(i,cc) printf("%d -> %d\n", edges[cycle[i]].x+1, edges[cycle[i]].y+1);
	int prev=-1;
	vector<pii> ans;
	bool rev = false;
	while(cc--) {
		pii e = edges[cycle[cc]];
		if(prev != e.x && prev != e.y) {
			// new cycle
			if(e.x == e.y) {
				prev = e.x;
			} else {
				assert(cc>0);
				pii e2 = edges[cycle[cc-1]];
				if(e.x == e2.x || e.x == e2.y) prev = e.y;
				if(e.y == e2.x || e.y == e2.y) prev = e.x;
				assert(prev == e.x || prev == e.y);
			}
		}
		int next = prev ^ e.x ^ e.y;
		ans.pb(rev ? pii(prev, next) : pii(next, prev));
		prev = next;
		rev ^= 1;
	}
	vi sts(n);
	tr(it, ans) {
		sts[it->x] ^= 1;
		sts[it->y] ^= 2;
	}
	vi bad1, bad2;
	fru(i,n) {
		if(sts[i]&1) bad1.pb(i);
		if(sts[i]&2) bad2.pb(i);
	}
	assert(bad1.size() == bad2.size());
	while(!bad1.empty()) {
		ans.pb(pii(bad1.back(), bad2.back()));
		bad1.pop_back();
		bad2.pop_back();
	}
	printf("%lu\n", ans.size());
	tr(it, ans) printf("%d %d\n", it->x+1, it->y+1);
}

int main() {
	//	freopen("input.in", "r", stdin);
	//	freopen("output.out", "w", stdout);
	int t=1;
	//	scanf("%d",&t);
	fru(i,t) solve();
	return 0;
}