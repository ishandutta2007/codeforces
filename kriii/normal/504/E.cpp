#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,Q;
char S[300030];
vector<int> T[300030];
const int Z = 18;
int D[300030],par[300030][Z+1];
unsigned long long pw[Z+1],h1[300030][Z+1],h2[300030][Z+1];

void dfs(int x, int l)
{
	D[x] = D[l] + 1;
	par[x][0] = l;
	h1[x][0] = S[l];
	h2[x][0] = S[x];
	for (int i=1;i<=Z;i++){
		int u = par[x][i-1];
		par[x][i] = par[u][i-1];
		h1[x][i] = (h1[x][i-1] + h1[u][i-1] * pw[i-1]) % 1000000007;
		h2[x][i] = (h2[x][i-1] * pw[i-1] + h2[u][i-1]) % 1000000007;
	}
	for (int &y : T[x]) if (y != l) dfs(y,x);
}

int up(int u, int k)
{
	for (int i=0;i<=Z;i++) if (k & (1 << i)) u = par[u][i];
	return u;
}

int lca(int x, int y)
{
	if (D[y] > D[x]) swap(x,y);
	x = up(x,D[x]-D[y]);
	if (x != y){
		for (int i=Z;i>=0;i--) if (par[x][i] != par[y][i]){
			x = par[x][i];
			y = par[y][i];
		}
		x = par[x][0];
	}
	return x;
}

int tr[2][55],lv[55]; unsigned long long hs[2][55];

int query()
{
	int x[2],y[2],z[2],l[2];
	for (int k=0;k<2;k++){
		scanf ("%d %d",&x[k],&y[k]);
		z[k] = lca(x[k],y[k]);
		l[k] = D[x[k]] + D[y[k]] - D[z[k]] * 2;
	}

	if (S[x[0]] != S[x[1]]) return 0;
	int ans = 1;

	int p[2][3] = {x[0],z[0],y[0],x[1],z[1],y[1]};
	int u[2][3] = {0,};
	for (int k=0;k<2;k++) for (int i=1;i<3;i++){
		u[k][i] = u[k][i-1] + abs(D[p[k][i-1]]-D[p[k][i]]);
	}

	int i[2];
	for (i[0]=1;i[0]<3;i[0]++) for (i[1]=1;i[1]<3;i[1]++){
		int s = max(u[0][i[0]-1],u[1][i[1]-1]);
		int e = min(u[0][i[0]],u[1][i[1]]);
		if (s >= e) continue;
		int dis = e - s;

		int sz;
		for (int k=0;k<2;k++){
			if (i[k] == 1){
				int X = up(x[k],s);
				sz = 0;
				for (int i=0;i<=Z;i++) if (dis & (1 << i)){
					tr[k][sz] = X;
					hs[k][sz] = h1[X][i];
					lv[sz] = i;
					sz++;
					X = par[X][i];
				}
			}
			else{
				int X = up(y[k],l[k]-e);
				sz = 0;
				for (int i=Z;i>=0;i--) if (dis & (1 << i)){
					tr[k][sz] = X;
					hs[k][sz] = h2[X][i];
					lv[sz] = i;
					sz++;
					X = par[X][i];
				}
				reverse(tr[k],tr[k]+sz);
				reverse(hs[k],hs[k]+sz);
				reverse(lv,lv+sz);
			}
		}

		for (int v=0;v<sz;v++){
			int lev = lv[v];
			if (hs[0][v] == hs[1][v]) ans += 1 << lev;
			else{
				int X[2];
				for (int k=0;k<2;k++) X[k] = tr[k][v];
				for (lev--;lev>=0;lev--){
					unsigned long long h[2];
					for (int k=0;k<2;k++){
						if (i[k] == 1){
							h[k] = h1[X[k]][lev];
						}
						else{
							h[k] = h2[par[X[k]][lev]][lev];
						}
					}
					if (h[0] == h[1]){
						ans += 1 << lev;
						for (int k=0;k<2;k++){
							if (i[k] == 1){
								X[k] = par[X[k]][lev];
							}
						}
					}
					else{
						for (int k=0;k<2;k++){
							if (i[k] == 2){
								X[k] = par[X[k]][lev];
							}
						}
					}
				}
				return ans;
			}
		}
	}

	return ans;
}

int main()
{
	scanf ("%d %s",&N,S+1);
	for (int i=1;i<N;i++){
		int x,y; scanf ("%d %d",&x,&y);
		T[x].push_back(y);
		T[y].push_back(x);
	}

	pw[0] = 307;
	for (int i=1;i<=Z;i++) pw[i] = pw[i-1] * pw[i-1] % 1000000007;
	dfs(1,0);

	scanf ("%d",&Q); while (Q--) printf ("%d\n",query());

	return 0;
}