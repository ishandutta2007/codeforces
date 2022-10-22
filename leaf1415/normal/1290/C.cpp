#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

struct UnionFind{
	int size;
	vector<int> parent, on;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
		on.resize(size+1);
		init();
	}
	void init(){
		for(int i = 0; i <= size; i++) parent[i] = i;
	}
	int root(int i){
		if(parent[i] == i) return i;
		return parent[i] = root(parent[i]);
	}
	bool same(int i, int j){
		return root(i) == root(j);
	}
	void unite(int i, int j){
		int root_i = root(i), root_j = root(j);
		if(root_i == root_j) return;
		parent[root_i] = root_j;
		on[root_j] += on[root_i];
	}
};

llint n, k;
string s;
vector<llint> vec[300005];
llint force[300005], choice[300005];
llint val[300005][2];
UnionFind uf(600005);
llint ans = 0;

void connect(llint u, llint v, llint t)
{
	if(t == 0 && uf.same(u, v)) return;
	if(t == 1 && uf.same(u, v+k)) return;
	
	llint U = uf.root(u), V = uf.root(v);
	if(U > k) U -= k;
	if(V > k) V -= k;
	ans -= val[U][choice[U]];
	ans -= val[V][choice[V]];
	
	//cout << ans << endl;
	//cout << val[U][choice[U]] << " " <<  val[V][choice[V]] << endl;
	
	if(force[U] != 0){
		llint f = force[U];
		if(t == 1) f *= -1;
		if((u <= k && uf.root(u) > k) || (u > k && uf.root(u) <= k)) f *= -1;
		if((u <= v && uf.root(v) > k) || (v > k && uf.root(v) <= k)) f *= -1;
		force[V] = f;
	}
	if(t == 0){
		uf.unite(u, v);
		uf.unite(u+k, v+k);
	}
	else{
		uf.unite(u, v+k);
		uf.unite(u+k, v);
	}
	
	llint r = uf.root(u);
	if(r > k) r -= k;
	
	val[r][1] = uf.on[r];
	val[r][0] = uf.on[r+k];
	
	//cout << val[r][0] << " " << val[r][1] << endl;
	
	llint tmp = inf;
	if(force[r] != -1 && tmp > val[r][1]){
		tmp = val[r][1];
		choice[r] = 1;
	}
	if(force[r] != 1 && tmp > val[r][0]){
		tmp = val[r][0];
		choice[r] = 0;
	}
	ans += val[r][choice[r]];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	s = "#" + s;
	for(int i = 1; i <= k; i++){
		llint m, x;
		cin >> m;
		for(int j = 0; j < m; j++){
			cin >> x;
			vec[x].push_back(i);
		}
	}
	for(int i = 1; i <= k; i++) choice[i] = 0;
	for(int i = 1; i <= k; i++) uf.on[i] = val[i][1] = 1;
	
	for(int i = 1; i <= n; i++){
		if(vec[i].size() == 1){
			llint u = vec[i][0], r = uf.root(u);
			if(r > k) r -= k;
			ans -= val[r][choice[r]];
			
			llint f = -1;
			if(s[i] == '0') f = 1;
			if((u <= k && uf.root(u) > k) || (u > k && uf.root(u) <= k)) f *= -1;
			
			force[r] = f;// cout << u << " " << r << endl;
			if(force[r] > 0) ans += val[r][1], choice[r] = 1;
			else ans += val[r][0], choice[r] = 0;
		}
		if(vec[i].size() == 2){
			if(s[i] == '0') connect(vec[i][0], vec[i][1], 1);
			else connect(vec[i][0], vec[i][1], 0);
		}
		//for(int j = 1; j <= k; j++) cout << force[j] << " "; cout << endl;
		//for(int j = 1; j <= 2*k; j++) cout << uf.root(j) << " "; cout << endl;
		//for(int j = 1; j <= k; j++)  cout << val[j][0] << " " << val[j][1] << endl;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}