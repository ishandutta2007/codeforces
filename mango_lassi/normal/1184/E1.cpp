#include <bits/stdc++.h>
const int MN = 1e5+100;
#define F first
#define S second
using namespace std;
int uf[MN];
int sz[MN];
int find(int a) {
	if(uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	if(sz[find(a)] > sz[find(b)]) swap(a, b);
	sz[find(b)] += sz[find(a)];
	//merges a into b
	uf[find(a)] = find(b);
}
int mst(auto v, int e) {
	for(int i = 0; i < MN; ++i) uf[i] = i;
	for(int i = 0; i < MN; ++i) sz[i] = 1;
	v[0].F.F = e;
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i < v.size(); ++i) {
		int a = v[i].S.F;
		int b = v[i].S.S;
		if(find(a) != find(b)) {
			if(v[i].F.S == 0) ans = 1;
			merge(a, b);
		}
	}
	return ans;
}
int main() {
	vector<pair<pair<int, int>, pair<int, int> > > v;
	int n,m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; ++i) {
		int a, b, e;
		cin>>a>>b>>e;
		v.push_back({{e, i}, {a, b}});
	}
	int lo = 0;
	int hi = 1e9;
	int ans = 0;
	while(lo <= hi) {
		int mid = (lo+hi)/2;
		if(mst(v, mid) == 1) {
			ans = mid;
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
	}
	cout<<ans<<endl;

}