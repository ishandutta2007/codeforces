#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define SP fixed << setprecision(10)

using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;
typedef double DB;

const int N = 100100 , L = 20;
int par[N][L] , h[N] , st[N] , rst[N] , start , num;
set <int> s;
vector <int> adj[N];

void DFS(int v , int p){

	par[v][0] = p;
	st[v] = start;
	rst[start++] = v;
	h[v] = h[p] + 1;
	for(int i = 1;  i < L ; i++)
	   par[v][i] = par[par[v][i-1]][i-1];
		
	for(int u : adj[v])
	   if(u != p)
		  DFS(u , v);
	
	return;
}

pii LCA(int u , int v){

	if(h[u] < h[v])
	   swap(u , v);

	int t = h[u] - h[v] , dist(0);
	for(int i = 0 ; i < L ; i++)
	   if(((1 << i) & t))
		  u = par[u][i] , dist += (1 << i);
	
	if(u == v)
	   return {u , dist};
	
	for(int i = L-1 ; i >= 0 ; i--)
	   if(par[u][i] != par[v][i]){
		  	u = par[u][i];
			v = par[v][i];
			dist += (1 << (i+1));
	   }
	
	return {par[v][0] , dist+2};
}


void add(int fl , int x){
	
	if(!s.size()){
	   s.insert(x);
	   return;
	}

	int l = *s.begin() , r = *--s.end() , f(0) , rt = LCA(rst[l] , rst[r]).F;
	num -= (h[rst[l]] + h[rst[r]] - 2*h[rt]);
	
	s.insert(x);
   	auto it = s.find(x) , it2 = it;
	
	if(it != s.begin()){
		it2 = --it , it++;
		num += LCA(rst[*it] , rst[*it2]).S*fl; 
		f++;
	}
	if(++it != s.end()){
	   it2 = it , it--;
	   num += LCA(rst[*it] , rst[*it2]).S*fl;
	   f++;
	}

	if(f == 2){
	   it2 = --it, it++ , it++;
	   num -= LCA(rst[*it] , rst[*it2]).S*fl;
	}
	
	if(fl == -1)
		s.erase(x);
		
	l = *s.begin() , r = *--s.end() , rt = LCA(rst[l] , rst[r]).F;
	num += (h[rst[l]] + h[rst[r]] - 2*h[rt]);

	return;
}

int main(){

	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

	int n , k , u , v;
	cin >> n >> k;
	
	for(int i = 1 ; i < n ; i++){
	   	cin >> u >> v;
		adj[--u].PB(--v);
		adj[v].PB(u);
	}
	
	DFS(0 , 0);

	int pt1(0) , pt2(0) , ans(0);

	while(pt2 < n && pt1 < n){
		if(num/2 + 1 <= k)
			add(1 , st[pt2++]);		
		else
		   	add(-1 , st[pt1++]);
			
		if(num/2 + 1 <= k)
		   ans = max(ans , pt2 - pt1);
		 
	}

	cout << ans << endl;
	return 0;

}