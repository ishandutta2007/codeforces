#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 1010000;
 
vector<vector<int> > pfact(MAXN);
void init(){
	for(int p = 2; p < MAXN; p++){
		if(pfact[p].size() == 0){
			for(int q = p; q < MAXN; q += p){
				pfact[q].push_back(p);
			}
		}
	}
}
 
// vector<int> gcds(vector<int> nums1, vector<int> nums2){
// 	vector<int> gcds(MAXN, 0);
// 	vector<int> nmult(MAXN, 0);
// 	for(int i = 1; i < MAXN; i++){
// 		if(!nums1[i]) continue;
// 		int z = pfact[i].size();
// 		for(int b = 0; b < (1<<z); b++){
// 			int q = 1;
// 			for(int j = 0; j < z; j++){
// 				if(b & (1<<j)){
// 					q *= pfact[i][j];
// 				}
// 			}
// 			nmult[q]++;
// 		}
// 	}
// 	for(int i = 1; i < MAXN; i++){
// 		if(!nums2[i]) continue;
// 		int z = pfact[i].size();
// 		int ans = 0;
// 		vector<int> dp(1<<z, 0);
// 		for(int b = 0; b < (1<<z); b++){
// 			int q = 1;
// 			for(int j = 0; j < z; j++){
// 				if(b & (1<<j)){
// 					q *= pfact[i][j];
// 				}
// 			}
// 			if(__builtin_popcount(b) % 2 == 0){
// 				dp[b] = nmult[q];
// 			} else {
// 				dp[b] = -nmult[q];
// 			}
// 		}
// 		for(int c = 0; c < z; c++){
// 			for(int b = 0; b < (1<<z); b++){
// 				if(b & (1<<c)) continue;
// 				dp[b] += dp[b ^ (1<<c)];
// 			}
// 		}
// 		for(int b = 0; b < (1<<z); b++){
// 			if(dp[b] == 0) continue;
// 			int q = 1;
// 			for(int j = 0; j < z; j++){
// 				if(b & (1<<j)){
// 					q *= pfact[i][j];
// 				}
// 			}
// 			gcds[q] = 1;
// 		}
// 	}
// 	return gcds;
// }

// pair<int,int> gcds_find(vector<int> nums1, vector<int> nums2, int x){
// 	vector<int> gcds(MAXN, 0);
// 	vector<int> nmult(MAXN, 0);
// 	for(int i = 1; i < MAXN; i++){
// 		if(!nums1[i]) continue;
// 		int z = pfact[i].size();
// 		for(int b = 0; b < (1<<z); b++){
// 			int q = 1;
// 			for(int j = 0; j < z; j++){
// 				if(b & (1<<j)){
// 					q *= pfact[i][j];
// 				}
// 			}
// 			nmult[q]++;
// 		}
// 	}
// 	// look for x
// 	for(int i = 1; i < MAXN; i++){
// 		if(!nums2[i]) continue;
// 		int z = pfact[i].size();
// 		int ans = 0;
// 		vector<int> dp(1<<z, 0);
// 		for(int b = 0; b < (1<<z); b++){
// 			int q = 1;
// 			for(int j = 0; j < z; j++){
// 				if(b & (1<<j)){
// 					q *= pfact[i][j];
// 				}
// 			}
// 			if(__builtin_popcount(b) % 2 == 0){
// 				dp[b] = nmult[q];
// 			} else {
// 				dp[b] = -nmult[q];
// 			}
// 		}
// 		for(int c = 0; c < z; c++){
// 			for(int b = 0; b < (1<<z); b++){
// 				if(b & (1<<c)) continue;
// 				dp[b] += dp[b ^ (1<<c)];
// 			}
// 		}
// 		for(int b = 0; b < (1<<z); b++){
// 			if(dp[b] == 0) continue;
// 			int q = 1;
// 			for(int j = 0; j < z; j++){
// 				if(b & (1<<j)){
// 					q *= pfact[i][j];
// 				}
// 			}
// 			if(q == x){
// 				for(int j = 0; j < MAXN; j++){
// 					if(!nums1[j]) continue;
// 					if(gcd(i, j) == x) return {j, i};
// 				}
// 			}
// 		}
// 	}
// 	assert(false);
// }

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();

	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& y : a){
		cin >> y;
	}
	{
		ll g = 0;
		for(ll y : a) g = gcd(g, y);
		for(ll& y : a) y /= g;
	}
	// gcd = 1
	vector<int> used(n, 0);
	vector<ll> care;
	{
		ll g = 0;
		for(int i = 0; i < n; i++){
			if(g == 0 || pfact[gcd(g, a[i])].size() < pfact[g].size()){
				g = gcd(g, a[i]);
				care.push_back(i);
				used[i] = 1;
			}
		}
	}
	// {
	// 	vector<int> which(MAXN, 0);
	// 	vector<int> nums(MAXN, 0);
	// 	for(int i = 0; i < n; i++){
	// 		int v = 1;
	// 		for(int x : pfact[a[i]]){
	// 			v *= x;
	// 		}
	// 		nums[v] = 1;
	// 		which[v] = i;
	// 	}
	// 	for(int i = 1; i < MAXN; i++){
	// 		if(!nums[i]) continue;
	// 		for(int j = i * 2; j < MAXN; j += i){
	// 			nums[j] = 0;
	// 		}
	// 	}
	// 	vector<vector<int> > dp;
	// 	dp.push_back(nums);
	// 	while(!dp.back()[1]){
	// 		dp.push_back(gcds(dp.back(), nums));
	// 	}
	// 	int cur = (int)dp.size();
	// 	int cv = 1;
	// 	vector<int> used;
	// 	while(cur > 1){
	// 		auto [p1, p2] = gcds_find(dp[cur-2], nums, cv);
	// 		used.push_back(p2);
	// 		cv = p1;
	// 		cur--;
	// 	}
	// 	used.push_back(cv);
	// 	for(int x : used){
	// 		assert(nums[x]);
	// 		care.push_back(which[x]);
	// 	}
	// }

	{
		ll x = 0;
		ll y = 0;
		for(int i : care){
			y = gcd(y, a[i]);
			ll z = gcd(x, y);
			y = lcm(x, y);
			x = z;
		}
		assert(x == 1);
		ll cg = y;
		for(int i = 0; i < n; i++){
			if(used[i]) continue;
			cg = gcd(cg, a[i]);
		}
		ll cur = y / cg;
		for(int i = 0; i < n; i++){
			if(used[i]) continue;
			ll f = a[i] / cg;
			if(cur == 0 || cur >= MAXN || pfact[gcd(cur, f)].size() < pfact[cur].size()){
				cur = gcd(cur, f);
				care.push_back(i);
				used[i] = 1;
			}
		}
	}

	sort(care.begin(), care.end());
	int X = care.size();
	vector<pair<int, vector<int> > > ops;
	for(int l = 1; l <= X; l++){
		int mult = (l - 2) * ((l & 1) ? -1 : 1);
		if(mult == 0) continue;
		for(int g = 0; g < (1 << X); g++){
			if(__builtin_popcount(g) != l) continue;
			vector<int> v;
			for(int i = 0; i < X; i++){
				if(g & (1 << i)){
					v.push_back(care[i]);
				}
			}
			if(mult > 0){
				for(int i = 0; i < mult; i++){
					ops.push_back({0, v});
				}
			} else {
				for(int i = 0; i < -mult; i++){
					ops.push_back({1, v});
				}
			}
		}
	}
	cout << ops.size() << '\n';
	for(auto [type, v] : ops){
		cout << type << " " << v.size();
		for(int z : v){
			cout << " " << (z+1);
		}
		cout << '\n';
	}
}