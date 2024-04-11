#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 100005;
const int MaxQ = 55;

//////////////////////// find-union ///////////////////////////
int fu_parent[MaxN], fu_rank[MaxN], fu_root[MaxN];

void fu_init(int N){
	for(int i = 0; i < N; i++){
		fu_parent[i] = i;
		fu_rank[i] = 0;
		fu_root[i] = i;
	}
}

int fu_find(int v){
	if(fu_parent[v] == v)
		return v;
	else
		return (fu_parent[v] = fu_find(fu_parent[v]));
}

void fu_union(int a, int b){  // low, hi
	a = fu_find(a);
	b = fu_find(b);
	if(a==b) return;

	fu_root[a] = fu_root[b];

	if(fu_rank[a] >= fu_rank[b]){
		fu_parent[b] = a;
		if(fu_rank[a] == fu_rank[b]) fu_rank[a]++;
	} else {
		fu_parent[a] = b;
	}
}


///////////////////////////////////////////////////////////////


vector<pair<int,int>> adj[MaxN];
int N, Q;
LL dist[MaxN];
bool vis[MaxN];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N-1; i++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		u--; v--;
		adj[u].emplace_back(v,c);
		adj[v].emplace_back(u,c);
	}
	scanf("%d", &Q);
}

void dfs_dist(int v){
	vis[v] = true;
	for(auto& P: adj[v]){
		int s = P.first, cost = P.second;

		if(vis[s]) continue;
		dist[s] = dist[v] + cost;
		dfs_dist(s);
	}
}

int find_farthest(int start){
	fill(vis, vis+N, false);
	dist[start] = 0;

	dfs_dist(start);

	return distance(dist, max_element(dist, dist+N));
}

vector<int> diam;
vector<int> diamJumps;
int pathEnd;

bool dfs_path(int v){
	vis[v] = true;
	if(v == pathEnd){
		diam.push_back(v);
		return true;
	}

	for(auto&P : adj[v]){
		int s = P.first;

		if(vis[s]) continue;
		if(dfs_path(s)){
			diam.push_back(v);
			return true;
		}
	}
	return false;
}

LL create_diameter(){
	int start = find_farthest(1);
	int end   = find_farthest(start);

	fill(vis, vis+N, false);
	pathEnd = end;
	dfs_path(start);

	LL length = 0;
	for(int i = 0; i < static_cast<int>(diam.size())-1; i++){
		int v = diam[i], next = diam[i+1];

		for(auto& P: adj[v]){
			int s = P.first;
			if(s == next){
				diamJumps.push_back(P.second);
				length += P.second;
			}
		}
	}
	return length;
}

LL diamLength;


LL whatDist[MaxN];
int a, b;
LL distA, distB;


int get_not_far(int v, LL dist){
	if(dist < 0) return -101010101;
	vis[v] = true;
	int result = 1;

	for(auto& P: adj[v]){
		int s = P.first, cost = P.second;
		
		if(vis[s] || cost > dist) continue;
		result += get_not_far(s, dist-cost);
	}
	return result;
}


vector<int> dstA, dstB;
int dp[MaxN];


int get_best_res(LL length, vector<int>& dists){
	fu_init(N+1);
	fill(dp, dp+N, 0);

	int dsize = dists.size();
	int vptr = 0, remptr = 0;
	int result = 0;

	while(vptr < dsize){
		if(whatDist[dists[remptr]] > whatDist[dists[vptr]] + length){
			int subFrom = fu_root[fu_find(dists[remptr])];
//			printf("deleting %d, sub from %d\n", dists[remptr], subFrom);
			dp[subFrom]--;
			remptr++;
		} else {
//			printf("adding %d\n", dists[vptr]);
			int v = dists[vptr];
			dp[v] = 1;
			for(auto& P: adj[v]){
				int s = P.first;
				if(whatDist[s] > whatDist[v]){   // s = child of v
					dp[v] += dp[s];
					fu_union(s, v);
				}
			}
			result = max(result, dp[v]);
			vptr++;
		}
	}

	return result;
}

int compute(LL length){
	// processing a query
	// way 1: contains both a and b
	int result = 0;
	LL D = min(distA, distB);

	if(1){
		int way1 = 0;
		// from a
		fill(vis, vis+N, false);
		vis[b] = true;
//		printf(">\n");
		way1 += get_not_far(a, length+D-distA);

		// from b
		fill(vis, vis+N, false);
		vis[a] = true;
//		printf(">\n");
		way1 += get_not_far(b, length+D-distB);

		result = max(result, way1);
	}
//	printf(">>%d\n", result);


	// way2: on either side
	// from a?
	result = max(result, get_best_res(length, dstA));
//	printf("%d\n", result);

	// from b?
	result = max(result, get_best_res(length, dstB));
//	printf("%d\n\n", result);
	return result;
}


int main(){
	input();
	diamLength = create_diameter();

	// find center
	LL total = 0;
	for(int i = 0; i < static_cast<int>(diam.size())-1; i++){
		total += diamJumps[i];
		if(total*2 > diamLength){
			a = diam[i];   distA = diamLength - total + diamJumps[i];
			b = diam[i+1]; distB = total;
			break;
		}
	}
//	printf("%d %d\n", a, b);

	// sort subtrees separated by a-b by distance from root
	fill(vis, vis+N, false);
	fill(dist, dist+N, -1);
	vis[b] = true;
	dist[a] = 0;
	dfs_dist(a);
	for(int i = 0; i < N; i++)
		if(dist[i] >= 0){
			whatDist[i] = dist[i];
			dstA.push_back(i);
		}
	auto distSorter = [&](int lhs, int rhs){
				return dist[lhs] > dist[rhs];
			};
	sort(dstA.begin(), dstA.end(), distSorter);

	fill(vis, vis+N, false);
	fill(dist, dist+N, -1);
	vis[a] = true;
	dist[b] = 0;
	dfs_dist(b);
	for(int i = 0; i < N; i++)
		if(dist[i] >= 0){
			whatDist[i] = dist[i];
			dstB.push_back(i);
		}
	sort(dstB.begin(), dstB.end(), distSorter);

	// process queries
	for(int query = 0; query < Q; query++){
		LL L;
		scanf("%I64d", &L);
		printf("%d\n", compute(L));
	}
}