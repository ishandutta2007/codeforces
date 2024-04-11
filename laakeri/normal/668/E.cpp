#include <bits/stdc++.h>
using namespace std;

struct SCC {
	vector<int> used;
	vector<vector<int> > g2;
	
	void dfs1(vector<int>* g, int x, vector<int>& ns) {
		if (used[x]==1) return;
		used[x]=1;
		for (int nx:g[x]) {
			g2[nx].push_back(x);
			dfs1(g, nx, ns);
		}
		ns.push_back(x);
	}
	
	void dfs2(int x, vector<int>& co) {
		if (used[x]==2) return;
		used[x]=2;
		co.push_back(x);
		for (int nx:g2[x]) {
			dfs2(nx, co);
		}
	}
	
	// Returns strongly connected components of the graph in vector ret
	// n is the size of the graph, g is the adjacency list
	SCC(vector<int>* g, int n, vector<vector<int> >& ret) : used(n+1), g2(n+1) {
		vector<int> ns;
		for (int i=1;i<=n;i++) {
			dfs1(g, i, ns);
		}
		for (int i=n-1;i>=0;i--) {
			if (used[ns[i]]!=2) {
				ret.push_back(vector<int>());
				dfs2(ns[i], ret.back());
			}
		}
	}
};

vector<int> g1[2222];
bitset<2222> c1[2222];
vector<int> g2[2222];
bitset<2222> c2[2222];

vector<int> solvesat(vector<int>* g, int n, int mark=0){
	vector<vector<int> > scc;
	SCC(g, n*2+1, scc);
	vector<int> sol(n);
	reverse(scc.begin(), scc.end());
	for (auto t:scc){
		sort(t.begin(), t.end());
		for (int i:t){
			if (mark==1){
				for (int nx:g1[i]){
					c1[i]|=c1[nx];
				}
			}
			if (mark==2){
				for (int nx:g2[i]){
					c2[i]|=c2[nx];
				}
			}
		}
		if (mark==1){
			for (int i:t){
				for (int j:t){
					c1[i]|=c1[j];
					c1[j]|=c1[i];
				}
			}
		}
		if (mark==2){
			for (int i:t){
				for (int j:t){
					c2[i]|=c2[j];
					c2[j]|=c2[i];
				}
			}
		}
		for (int i=0;i<(int)t.size()-1;i++){
			if (t[i]==(t[i+1]^1)) return {-1};
		}
		for (int tt:t){
			if (tt/2-1>=0){
				if (sol[tt/2-1]==0){
					if (tt%2==1) sol[tt/2-1]=2;
					else sol[tt/2-1]=1;
				}
			}
		}
	}
	return sol;
}

int u1[2222];
int u2[2222];

void dfs1(int x){
	if (u1[x]) return;
	u1[x]=1;
	for (int nx:g1[x]){
		dfs1(nx);
		c1[x]|=c1[nx];
	}
}
void dfs2(int x){
	if (u2[x]) return;
	u2[x]=1;
	for (int nx:g2[x]){
		dfs2(nx);
		c2[x]|=c2[nx];
	}
}

int h[1111];

int cv(int i, int v){
	if (h[i]==0) return 1;
	if (h[i]==2&&v==0) return 1;
	if (h[i]==1&&v==1) return 1;
	return 0;
}

int ok(int i){
	if (i%2==1){
		return cv(i/2, 0);
	}
	else{
		return cv(i/2, 1);
	}
}

int main(){
	int n,m1,m2;
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i=0;i<m1;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		if (a<0) a=abs(a)*2+1;
		else a=a*2;
		if (b<0) b=abs(b)*2+1;
		else b=b*2;
		g1[a^1].push_back(b);
		g1[b^1].push_back(a);
	}
	for (int i=0;i<m2;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		if (a<0) a=abs(a)*2+1;
		else a=a*2;
		if (b<0) b=abs(b)*2+1;
		else b=b*2;
		g2[a^1].push_back(b);
		g2[b^1].push_back(a);
	}
	for (int i=2;i<=2*n+1;i++){
		c1[i][i]=1;
		c2[i][i]=1;
	}
	vector<int> s1=solvesat(g1, n, 1);
	vector<int> s2=solvesat(g2, n, 2);
	if (s1[0]==-1&&s2[0]==-1){
		printf("SIMILAR\n");
		return 0;
	}
	if (s1[0]==-1){
		for (int i:s2){
			printf("%d ", 2-i);
		}
		return 0;
	}
	if (s2[0]==-1){
		for (int i:s1){
			printf("%d ", 2-i);
		}
		return 0;
	}
	for (int j=0;j<2;j++){
		for (int i=2;i<=2*n+1;i++){
			dfs1(i);
			dfs2(i);
		}
		memset(u1, 0, sizeof(u1));
		memset(u2, 0, sizeof(u2));
	}
	for (int i=1;i<=n;i++){
		if (c1[i*2][i*2+1]==1&&c2[i*2][i*2+1]==0){
			g2[i*2+1].push_back(i*2);
			vector<int> s=solvesat(g2, n);
			for (int t:s){
				printf("%d ", 2-t);
			}
			return 0;
		}
		if (c2[i*2][i*2+1]==1&&c1[i*2][i*2+1]==0){
			g1[i*2+1].push_back(i*2);
			vector<int> s=solvesat(g1, n);
			for (int t:s){
				printf("%d ", 2-t);
			}
			return 0;
		}
		if (c1[i*2+1][i*2]==1&&c2[i*2+1][i*2]==0){
			g2[i*2].push_back(i*2+1);
			vector<int> s=solvesat(g2, n);
			for (int t:s){
				printf("%d ", 2-t);
			}
			return 0;
		}
		if (c2[i*2+1][i*2]==1&&c1[i*2+1][i*2]==0){
			g1[i*2].push_back(i*2+1);
			vector<int> s=solvesat(g1, n);
			for (int t:s){
				printf("%d ", 2-t);
			}
			return 0;
		}
		if (c1[i*2][i*2+1]){
			h[i]=2;
		}
		if (c1[i*2+1][i*2]){
			h[i]=1;
		}
	}
	for (int i=2;i<=2*n+1;i++){
		for (int ii=2;ii<=2*n+1;ii++){
			if (c1[i][ii]!=c2[i][ii]){
				if (c1[i][ii]==1){
					if (ok(i)&&ok(ii^1)){
						g2[i^1].push_back(i);
						g2[ii].push_back(ii^1);
						vector<int> s=solvesat(g2, n);
						for (int t:s){
							printf("%d ", 2-t);
						}
						return 0;
					}
				}
				if (c2[i][ii]==1){
					if (ok(i)&&ok(ii^1)){
						g1[i^1].push_back(i);
						g1[ii].push_back(ii^1);
						vector<int> s=solvesat(g1, n);
						for (int t:s){
							printf("%d ", 2-t);
						}
						return 0;
					}
				}
			}
		}
	}
	printf("SIMILAR\n");
}