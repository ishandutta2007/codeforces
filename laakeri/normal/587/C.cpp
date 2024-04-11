#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

typedef struct node* pnode;
struct node{
    pnode l,r;
    int s;
    node(){
        l=0;
        r=0;
        s=0;
    }
};

int gets(pnode t){
    if (t) return t->s;
    return 0;
}

pnode getl(pnode t){
    if (t) return t->l;
    return 0;
}

pnode getr(pnode t){
    if (t) return t->r;
    return 0;
}

const int N=1<<17;

// This has to be at least ceil(log2(n))
const int logSize=19;

struct RootedTree {

	vector<int> d;
	vector<array<int, logSize> > p;

	// Dfs for building parent array
	void dfs(vector<int>* g, int x, int pp, int dd) {
		p[x][0]=pp;
		for(int i=1;i<logSize;i++) {
			p[x][i]=p[p[x][i-1]][i-1];
		}
		d[x]=dd;
		for (int nx:g[x]) {
            if (nx!=pp){
                dfs(g, nx, x, dd+1);
            }
		}
	}

	// Construct parent array data structure of tree of size n
	// g is the adjacency list of the tree
	RootedTree(vector<int>* g, int n, int root=1) : d(n+1), p(n+1) {
		dfs(g, root, 0, 0);
	}

	// Returns the node h edges above x.
	// Returns 0 if no such node exists
	int parent(int x, int h) {
		for (int i=logSize-1;i>=0;i--) {
			if ((1<<i)&h) {
				x=p[x][i];
			}
		}
		return x;
	}

	// Returns lca of nodes a and b
	int lca(int a, int b) {
		if (d[a]<d[b]) swap(a, b);
		a=parent(a, d[a]-d[b]);
		if (a==b) return a;
		for (int i=logSize-1;i>=0;i--) {
			if (p[a][i]!=p[b][i]) {
				a=p[a][i];
				b=p[b][i];
			}
		}
		return p[a][0];
	}

	// Returns distance from a to b
	int dist(int a, int b) {
		int l=lca(a, b);
		return d[a]+d[b]-2*d[l];
	}
};

void add(pnode&t, pnode pt, int stl, int str, int x, int v){
    if (x<stl) return;
    if (x>str) return;
    t=new node();
    t->l=getl(pt);
    t->r=getr(pt);
    t->s=gets(pt);
    if (stl==str) t->s+=v;
    else{
        int mid=(stl+str)/2;
        add(t->l, getl(pt), stl, mid, x, v);
        add(t->r, getr(pt), mid+1, str, x, v);
        t->s=gets(getl(t))+gets(getr(t));
    }
}

int bs(pnode t1, pnode t2, pnode t3, pnode t4, int stl, int str, int k){
    int ts=gets(t1)+gets(t2)-gets(t3)-gets(t4);
    //cout<<stl<<" "<<str<<" "<<ts<<endl;
    if (ts<k) return -1;
    if (stl==str){
        return stl;
    }
    int mid=(stl+str)/2;
    int ls=gets(getl(t1))+gets(getl(t2))-gets(getl(t3))-gets(getl(t4));
    if (ls>=k){
        return bs(getl(t1), getl(t2), getl(t3), getl(t4), stl, mid, k);
    }
    else{
        return bs(getr(t1), getr(t2), getr(t3), getr(t4), mid+1, str, k-ls);
    }
}

vector<int> g[101010];

vector<pnode> st[101010];
vector<int> pp[101010];
int pn[101010];

void dfs3(int x, int p){
    st[x].push_back(st[p].back());
    pn[x]=p;
    for (int pe:pp[x]){
        pnode nn=0;
        add(nn, st[x].back(), 0, N-1, pe, 1);
        st[x].push_back(nn);
    }
    for (int nx:g[x]){
        if (nx!=p){
            dfs3(nx, x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0;i<m;i++){
        int a;
        cin>>a;
        pp[a].push_back(i+1);
    }
    RootedTree tree(g, n);
    st[0].push_back(0);
    dfs3(1, 0);
    for (int qq=0;qq<q;qq++){
        int v,u,a;
        cin>>v>>u>>a;
        int l=tree.lca(v, u);
        vector<int> vv;
        for (int i=1;i<=a;i++){
            int t=bs(st[v].back(), st[u].back(), st[l].back(), st[pn[l]].back(), 0, N-1, i);
            if (t>-1) vv.push_back(t);
            else break;
        }
        cout<<vv.size()<<" ";
        for (int vvv:vv){
            cout<<vvv<<" ";
        }
        cout<<'\n';
    }
}