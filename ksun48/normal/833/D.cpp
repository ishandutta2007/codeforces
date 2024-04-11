#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL powmod(LL a, int n){
	if(n == 0) return 1;
	if(n % 2) return (a*powmod(a,n-1)) % MOD;
	LL c = powmod(a, n/2);
	return (c*c) % MOD;
}

LL inv(LL a){
	return powmod(a, MOD-2);
}

vector<int> edges[110000];
vector<int> color[110000];
vector<LL> len[110000];
int used[110000];
int sz[110000];

int count(int par, int v){
	if(used[v]) return 0;
	sz[v] = 1;
	for(int i = 0; i < edges[v].size(); i++){
		if(edges[v][i] != par) sz[v] += count(v,edges[v][i]);
	}
	return sz[v];
}

int find_centroid(int v){
	count(-1,v);
	int cur = v;
	int prev = -1;
	while(1){
		int found = 0;
		for(int i = 0; i < edges[cur].size(); i++){
			if(!used[edges[cur][i]] && edges[cur][i] != prev){
				if(sz[edges[cur][i]]*2 > sz[v]){
					found = 1;
					prev = cur;
					cur = edges[cur][i];
					break;
				}
			}
		}
		if(!found) return cur;
	}
}


// Fenwick tree from KACTL
struct FT {
	vector<pair<LL,LL> > s;
	FT(int n) : s(n) {}
	void update(int pos, LL dif) { // a[pos] += dif
		for (; pos < s.size(); pos |= pos + 1){
			s[pos].first = (s[pos].first * dif) % MOD;
			s[pos].second += 1;
		}
	}
	pair<LL,LL> query(int pos) { // sum of values in [0, pos)
		pair<LL,LL> res;
		res.first = 1; res.second = 0;
		for (; pos > 0; pos &= pos - 1){
			res.first = (res.first * s[pos-1].first) % MOD;
			res.second += s[pos-1].second;
		}
		return res;
	}
};

LL total = 1;
LL answer = 1;

vector<LL> rcount, bcount, prods;

void adddist(int par, int v, LL r, LL b, LL prod){
	rcount.push_back(r);
	bcount.push_back(b);
	prods.push_back(prod);

	for(int i = 0; i < edges[v].size(); i++){
		if(used[edges[v][i]]) continue;
		if(par == edges[v][i]) continue;
		LL rnew = r;
		LL bnew = b;
		if(color[v][i] == 1){
			rnew++;
		} else {
			bnew++;
		}
		LL prodnew = prod;
		prodnew = (prodnew * len[v][i]) % MOD;
		adddist(v, edges[v][i], rnew, bnew, prodnew);
	}
}

void solve(int v){
	int a = find_centroid(v);

	//cout << "cent " << a << endl;

	int cursz = sz[v];

	int f = cursz * 4 + 10;

	int del = cursz * 2 + 5;

	FT case1(f);
	FT case2(f);
	FT case3(f);

	for(int i = 0; i < f; i++){
		case1.s[i].first  = case2.s[i].first  = case3.s[i].first = 1;
		case1.s[i].second = case2.s[i].second = case3.s[i].second = 0;
	}

	used[a] = 1;
	for(int i = 0; i < edges[a].size(); i++){
		if(!used[edges[a][i]]){
			//cout << "v " << edges[a][i] << endl;
			rcount.clear(); bcount.clear(); prods.clear();
			LL rnew = 0;
			LL bnew = 0;
			if(color[a][i] == 1){
				rnew++;
			} else {
				bnew++;
			}
			adddist(a, edges[a][i], rnew, bnew, len[a][i]);

			for(int z = 0; z < rcount.size(); z++){
				//cout << bcount[z] << " " << rcount[z] << " " << prods[z] << endl;
				int cost1 = 2*bcount[z] - rcount[z];
				int cost2 = 2*rcount[z] - bcount[z];
				int cost3 = -1;
				pair<LL,LL> ans1 = case1.query(0 - cost1 + del);
				pair<LL,LL> ans2 = case2.query(0 - cost2 + del);
				pair<LL,LL> ans3 = case3.query(0 - cost3 + del);
				answer = (answer * ans1.first) % MOD;
				answer = (answer * powmod(prods[z],ans1.second)) % MOD;
				answer = (answer * ans2.first) % MOD;
				answer = (answer * powmod(prods[z],ans2.second)) % MOD;
				total  = (total  * ans3.first) % MOD;
				total  = (total  * powmod(prods[z],ans3.second)) % MOD;
			}
			for(int z = 0; z < rcount.size(); z++){
				int cost1 = 2*bcount[z] - rcount[z];
				int cost2 = 2*rcount[z] - bcount[z];
				int cost3 = -1;
				case1.update(cost1 + del, prods[z]);
				case2.update(cost2 + del, prods[z]);
				case3.update(cost3 + del, prods[z]);
			}
		}
	}
	int cost1 = 0;
	int cost2 = 0;
	int cost3 = -1;
	pair<LL,LL> ans1 = case1.query(0 - cost1 + del);
	pair<LL,LL> ans2 = case2.query(0 - cost2 + del);
	pair<LL,LL> ans3 = case3.query(0 - cost3 + del);
	answer = (answer * ans1.first) % MOD;
	answer = (answer * 1) % MOD;
	answer = (answer * ans2.first) % MOD;
	answer = (answer * 1) % MOD;
	total  = (total  * ans3.first) % MOD;
	total  = (total  * 1) % MOD;
	for(int i = 0; i < edges[a].size(); i++){
		if(!used[edges[a][i]]){
			solve(edges[a][i]);
		}
	}	

}

int main(){

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++){
		int u, v, x, c;
		scanf("%d%d%d%d", &u, &v, &x, &c);
		if(c == 0) c = -1;
		u--; v--;
		edges[u].push_back(v);
		color[u].push_back(c);
		len[u].push_back(x);
		edges[v].push_back(u);
		color[v].push_back(c);
		len[v].push_back(x);
	}
	solve(0);
	LL newans = total;
	newans *= inv(answer);
	newans %= MOD;
	cout << newans << endl;
}