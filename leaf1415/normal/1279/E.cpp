#include <iostream>
#include <vector>
#define llint long long
#define many ((llint)1.5e18)
#define mod 998244353

using namespace std;

struct UnionFind{
	int size;
	vector<int> parent;
	
	UnionFind(){}
	UnionFind(int size){
		this->size = size;
		parent.resize(size+1);
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
	}
};

llint T;
llint n, k;
llint fact[55];
llint perm[55];
llint num[55];
UnionFind uf(55);
vector<llint> ans;

llint mul(llint a, llint b)
{
	if((many+a-1)/a <= b) return many;
	else return a*b;
}

bool used[55];
void calc(llint n, llint k, llint b)
{
	for(int i = 1; i <= n; i++){
		if(mul(perm[i], num[n-i]) < k){
			k -= mul(perm[i], num[n-i]);
			continue;
		}
		ans.push_back(i+b);
		
		uf.init();
		for(int j = 1; j <= i; j++) used[j] = false;
		used[i] = true;
		
		llint comp = i-1;
		for(int j = 2; j <= i; j++){
			for(int l = 1; l <= i; l++){
				if(uf.same(j, l) || used[l]) continue;
				if(comp >= 2 && k > mul(fact[comp-2], num[n-i])){
					k -= mul(fact[comp-2], num[n-i]);
					continue;
				}
				ans.push_back(l+b);
				uf.unite(j, l);
				used[l] = true;
				comp--;
				break;
			}
		}
		calc(n-i, k, b+i);
		break;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fact[0] = 1;
	for(int i = 1; i <= 53; i++) fact[i] = mul(fact[i-1], i);
	perm[1] = perm[2] = 1;
	for(int i = 3; i <= 50; i++) perm[i] = mul(perm[i-1], i-2);
	
	num[0] = 1;
	for(int i = 1; i <= 50; i++){
		for(int j = 1; j <= i; j++){
			num[i] += mul(perm[j], num[i-j]);
			num[i] = min(num[i], many);
		}
	}
	//for(int i = 1; i <= 10; i++) cout << num[i] << " "; cout<< endl;
	
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> k;
		if(k > num[n]){
			cout << -1 << "\n";
			continue;
		}
		ans.clear();
		calc(n, k, 0);
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << "\n";
	}
	flush(cout);
	
	return 0;
}