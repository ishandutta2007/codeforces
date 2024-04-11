#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[404040];
int aps[404040];
int cut[404040];
int n;
void dfs0(int x, int p){
	aps[x]=1;
	for (int nx:g[x]){
		if (nx!=p){
			dfs0(nx, x);
			aps[x]+=aps[nx];
			cut[x]=max(cut[x], cut[nx]);
		}
	}
	if (aps[x]<=n/2) cut[x]=aps[x];
}

int v[404040];

void dfs(int x, int p, int pc){
	v[x]=1;
	if (n-aps[x]>n/2){
		if (n-aps[x]-pc>n/2){
			v[x]=0;
		}
	}
	for (int nx:g[x]){
		if (nx!=p){
			if (aps[nx]>n/2){
				if (aps[nx]-cut[nx]>n/2){
					v[x]=0;
				}
			}
		}
	}
	int muc1=pc;
	int muc1i=0;
	int muc2=pc;
	for (int nx:g[x]){
		if (nx!=p){
			if (cut[nx]>muc1){
				muc2=muc1;
				muc1=cut[nx];
				muc1i=nx;
			}
			else if(cut[nx]>muc2){
				muc2=cut[nx];
			}
		}
	}
	for (int nx:g[x]){
		if (nx!=p){
			if (n-aps[nx]<=n/2){
				dfs(nx, x, n-aps[nx]);
			}
			else{
				if (muc1i==nx){
					dfs(nx, x, muc2);
				}
				else{
					dfs(nx, x, muc1);
				}
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	for (int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs0(1, 0);
	dfs(1, 0, 0);
	for (int i=1;i<=n;i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}