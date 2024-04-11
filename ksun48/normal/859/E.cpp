#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long LL;
vector<int> edges[200000];
int vis[200000];
int a[200000];

struct UF{
	int n;
	vector<int> par;
	vector<int> sz;
	UF(int n) : n(n) {
		for(int i = 0; i < n; i++) par.push_back(i);
		for(int i = 0; i < n; i++) sz.push_back(1);		
	}
	int find(int a){
		if(a != par[a]) par[a] = find(par[a]);
		return par[a];
	}
	void join(int a, int b){
		int s = find(a);
		int t = find(b);
		sz[t] += sz[s];
		par[s] = t;
	}
};

int main(){
	int m;
	cin >> m;
	int n = 2*m;
	for(int i = 0; i < n; i++){
		a[i] = -1;
	}
	LL ans = 1;

	UF r(n);
	for(int i = 0; i < m; i++){
		int c, d;
		cin >> c >> d;
		c--; d--;
		a[c] = d;
		if(r.find(c) == r.find(d)){
			if(c != d){
				ans = (ans * 2) % MOD;
			}
		} else {
			r.join(c,d);
		}
	}
	for(int i = 0; i < n; i++){
		if(a[i] == -1){
			LL s = r.find(i);
			ans = (ans * r.sz[s]) % MOD;
		}
	}
	cout << ans << endl;
}