#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[110000];
LL val[110000];
LL deg[110000];
LL par[110000];
LL vis[110000];
int done = 0;
int iscycle = 0;
int n, m;
int d3c = 0;

void finish(){
	printf("YES\n");
	for(int i = 0; i < n; i++){
		printf("%d ", val[i]);
	}
	printf("\n");
	return;
}
void finishno(){
	printf("NO\n");
	return;
}



void dfs(int a, int p){
	vis[a] = 1;
	if(iscycle) return;
	if(par[a] != -1){
		iscycle = 1;
		return;
	}
	par[a] = p;
	if(deg[a] >= 3){
		d3c++;
	}	
	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] != p){
			dfs(edges[a][j],a);
		}
	}
}

void dfs2(int a, int p){
	if(val[a] > 0) return;
	val[a] = 1;
	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] != p){
			dfs2(edges[a][j],a);
		}
	}
}

void dfs3(int a, int p){

	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] != p){
			dfs3(edges[a][j],a);
		}
	}
}

void dfs4(int a, int p){
	val[a] = 1;
	if(deg[a] >= 2){
		val[a] = 2;
	}
	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] != p){
			dfs4(edges[a][j],a);
		}
	}
}

vector<int> pt[3];
void dfsHELP(int a, int p, int i, int depth){
	if(depth > 10) return;
	pt[i].push_back(a);
	for(int j = 0; j < edges[a].size(); j++){
		if(edges[a][j] != p){
			dfsHELP(edges[a][j],a,i,depth+1);
		}
	}
}

int main(){
	for(int i = 0; i < 110000; i++) val[i] = 0;
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		scanf("%d%d", &n, &m);
		done = iscycle = 0;
		for(int i = 0; i < n; i++){ // reset
			edges[i].clear();
			val[i] = deg[i] = vis[i] = 0;
			par[i] = -1;
		}
		for(int i = 0; i < m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
			deg[a]++;
			deg[b]++;
			//	cout << a << " " << b << endl;
		}


		for(int i = 0; i < n; i++){
			if(deg[i] >= 4){
				done = 1;
				val[i] = 2;
				for(int j = 0; j < edges[i].size(); j++){
					val[edges[i][j]] = 1;
				}
				break;
			}
		}
		if(done){
			finish();
			continue;
		}

		for(int i = 0; i < n; i++){
			if(!vis[i]){
				d3c = 0;
				dfs(i, -1);
				if(iscycle){
					done = 1;
					dfs2(i,-1);
					//cout << i << endl;
					break;
				} else if(d3c >= 2){
					done = 1;
					dfs4(i,-1);
					break;
				}
			}
		}
		if(done){
			finish();
			continue;
		}
		if(done){
			finish();
			continue;
		}
		for(int i = 0; i < n; i++){
			if(done) continue;
			if(deg[i] == 3){
				for(int j = 0; j < 3; j++){
					pt[j].clear();
					dfsHELP(edges[i][j], i, j, 0);
				}
				if(pt[0].size() > pt[1].size()) swap(pt[0], pt[1]);
				if(pt[1].size() > pt[2].size()) swap(pt[1], pt[2]);
				if(pt[0].size() > pt[1].size()) swap(pt[0], pt[1]);
				if(pt[1].size() > pt[2].size()) swap(pt[1], pt[2]);
				//cout << pt[0].size() << " " << pt[1].size() << " " << pt[2].size() << endl;
				if(pt[0].size() >= 2){
					done = 1;
					val[i] = 3;
					val[pt[0][0]] = 2;
					val[pt[0][1]] = 1;

					val[pt[1][0]] = 2;
					val[pt[1][1]] = 1;

					val[pt[2][0]] = 2;
					val[pt[2][1]] = 1;
				} else if(pt[1].size() >= 3){
					done = 1;
					val[i] = 4;
					val[pt[0][0]] = 2;

					val[pt[1][0]] = 3;
					val[pt[1][1]] = 2;
					val[pt[1][2]] = 1;

					val[pt[2][0]] = 3;
					val[pt[2][1]] = 2;
					val[pt[2][2]] = 1;
				} else if(pt[1].size() >= 2 && pt[2].size() >= 5){
					done = 1;
					val[i] = 6;
					val[pt[0][0]] = 3;

					val[pt[1][0]] = 4;
					val[pt[1][1]] = 2;

					val[pt[2][0]] = 5;
					val[pt[2][1]] = 4;
					val[pt[2][2]] = 3;
					val[pt[2][3]] = 2;
					val[pt[2][4]] = 1;
				}
			}
		}
		if(done){
			finish();
			continue;
		}
		finishno();
	}
}