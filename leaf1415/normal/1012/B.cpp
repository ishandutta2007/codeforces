#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
typedef pair<int, int> P;

int n, m, q;
int r[200005], c[200005];
vector<P> vec;

int parent[200005];

void init(){
	for(int i = 1; i <= m; i++) parent[i] = i;
}
int root(int i)
{
	if(parent[i] == i) return i;
	return parent[i] = root(parent[i]);
}
void unite(int i, int j)
{
	int root_i = root(i), root_j = root(j);
	if(root_i == root_j) return;
	parent[root_i] = root_j;
}
bool same(int i, int j)
{
	return root(i) == root(j);
}

int main(void)
{
	cin >> n >> m >> q;
	for(int i = 0; i < q; i++) cin >> r[i] >> c[i];
	for(int i = 0; i < q; i++) vec.push_back(make_pair(r[i], c[i]));
	sort(vec.begin(), vec.end());
	
	init();
	for(int i = 1; i < vec.size(); i++){
		if(vec[i-1].first == vec[i].first){
			unite(vec[i-1].second, vec[i].second);
		}
	}
	
	set<int> s;
	for(int i = 1; i <= m; i++) s.insert(root(i));
	int ans = s.size() - 1;
	
	s.clear();
	for(int i = 0; i < q; i++) s.insert(r[i]);
	ans += n - s.size();
	
	cout << ans << endl;
	return 0;
}