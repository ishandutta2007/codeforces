#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
long long V;
int E;

const int MaxN = 305;

vector<int> adj[MaxN];
LL start[MaxN], stop[MaxN], needs[MaxN];

void input(){
	cin >> N >> V >> E;
	for(int i = 1; i <= N; i++)
		cin >> start[i];
	for(int i = 1; i <= N; i++)
		cin >> stop[i];

	for(int i = 0; i < E; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
//		cout << x << y << endl;
	}
}


bool vis[MaxN];
int parent[MaxN];
struct path {
	vector<int> vertices;
	int flow;
};
vector<path> paths;
vector<int> plusComponents[MaxN], minusComponents[MaxN];
int numComp;

LL dfs(int v, int p){
//	printf("dfs(%d,%d)\n", v, p);
	vis[v] = true;
	LL result = needs[v];
	parent[v] = p;

	if(needs[v] > 0)
		plusComponents[numComp].push_back(v);
	else if(needs[v] < 0)
		minusComponents[numComp].push_back(v);
		

	for(int s: adj[v]){
		if(vis[s]) continue;

		result += dfs(s, v);
	}
	return result;
}




LL get_conn_components(){
	fill(vis, vis+N+1, false);
	numComp = 0;

//	printf("A\n");
	for(int i = 1; i <= N; i++){
		if(!vis[i]){
			if(dfs(i,i) != 0)
				return false;
			numComp++;
//			printf("T\n");
		}
	}
//	printf("B\n");
	return true;
}


//bool vis[MaxN];
vector<int> newpath;
bool dfs_path(int v, int to){
	vis[v] = true;
	if(v == to){
		newpath.push_back(to);
		return true;
	}

	for(int s: adj[v]){
		if(vis[s]) continue;
		if(dfs_path(s, to)){
			newpath.push_back(v);
			return true;
		}
	}
	return false;
}

void add_path(int from, int to, int flow){
//	printf("add_path(%d,%d,%d)\n", from, to, flow);
	if(2*flow > V+1){
		add_path(from, to, flow/2);
		add_path(from, to, (flow+1)/2);
		return;
	}
	fill(vis, vis+N+1, false);
	newpath.clear();
	dfs_path(to, from);
//	for(int v: newpath) printf("%d ", v);
//	printf("\n");
	paths.push_back(path{newpath, flow});
}


vector<tuple<int,int,int>> result;

void push_path(const path& P, int pos = 0){
	vector<tuple<int,int,int>> res;
	while(pos < P.vertices.size()-1){
		int nextVert = P.vertices[pos+1];

		if(start[nextVert] + P.flow > V){
			push_path(P, pos+1);
			res.emplace_back(P.vertices[pos], nextVert, P.flow);
			break;
		}

		res.emplace_back(P.vertices[pos], nextVert, P.flow);
		pos++;
	}

	for(auto& T: res){
		start[get<0>(T)] -= P.flow;
		start[get<1>(T)] += P.flow;
		result.push_back(T);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	input();

	for(int i = 1; i <= N; i++)
		needs[i] = stop[i] - start[i];

	if(!get_conn_components()){
		printf("NO\n");
		return 0;
	}
//	printf("Y\n");

	for(int comp = 0; comp < numComp; comp++){
		int plusptr = 0, minusptr = 0;
/*		for(int p: plusComponents[comp]) printf("%d ", p);
		printf("\n");
		for(int m: minusComponents[comp]) printf("%d ", m);
		printf("\n");*/

		while(plusptr != plusComponents[comp].size()){
			assert(minusptr != (int)minusComponents[comp].size());

			int from = minusComponents[comp][minusptr],
			    to   = plusComponents[comp][plusptr];
			int flow = min(abs(needs[from]), abs(needs[to]));
//			printf("%d, %d, %d\n", from, to, flow);

			add_path(from, to, flow);
			
			needs[from] += flow;
			needs[to] -= flow;

			if(needs[from] == 0) minusptr++;
			if(needs[to]   == 0) plusptr++;
		}
	}

	for(auto& P: paths){
		push_path(P);
	}

	cout << result.size() << endl;
//	printf("%d\n", (int)result.size());
	for(auto& T: result){
		cout << get<0>(T) << " " << get<1>(T) << " " << get<2>(T) << "\n";
//		printf("%d %d %d\n", get<0>(T), get<1>(T), get<2>(T));
	}
}