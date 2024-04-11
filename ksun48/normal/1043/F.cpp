#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 310000;

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


vector<int> gcds(vector<int> nums1, vector<int> nums2){
	vector<int> gcds(MAXN, 0);
	vector<int> nmult(MAXN, 0);
	for(int i = 1; i < MAXN; i++){
		if(!nums1[i]) continue;
		int z = pfact[i].size();
		for(int b = 0; b < (1<<z); b++){
			int q = 1;
			for(int j = 0; j < z; j++){
				if(b & (1<<j)){
					q *= pfact[i][j];
				}
			}
			nmult[q]++;
		}
	}
	for(int i = 1; i < MAXN; i++){
		if(!nums2[i]) continue;
		int z = pfact[i].size();
		int ans = 0;
		vector<int> dp(1<<z, 0);
		for(int b = 0; b < (1<<z); b++){
			int q = 1;
			for(int j = 0; j < z; j++){
				if(b & (1<<j)){
					q *= pfact[i][j];
				}
			}
			if(__builtin_popcount(b) % 2 == 0){
				dp[b] = nmult[q];
			} else {
				dp[b] = -nmult[q];
			}
		}
		for(int c = 0; c < z; c++){
			for(int b = 0; b < (1<<z); b++){
				if(b & (1<<c)) continue;
				dp[b] += dp[b ^ (1<<c)];
			}
		}
		for(int b = 0; b < (1<<z); b++){
			if(dp[b] == 0) continue;
			int q = 1;
			for(int j = 0; j < z; j++){
				if(b & (1<<j)){
					q *= pfact[i][j];
				}
			}
			gcds[q] = 1;
		}
	}
	return gcds;
}

vector<int> nums(MAXN, 0);
int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	init();
	int n;
	cin >> n;
	int g = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		int v = 1;
		for(int x : pfact[a]){
			v *= x;
		}
		nums[v] = 1;
		g = __gcd(g, v);
	}
	if(g > 1){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i < MAXN; i++){
		if(!nums[i]) continue;
		for(int j = i * 2; j < MAXN; j += i){
			nums[j] = 0;
		}
	}

	int ans = 1;
	vector<int> newnums = nums;
	while(1){
		if(newnums[1] == 1){
			cout << ans << endl;
			return 0;
		}
		newnums = gcds(newnums, nums);
		ans++;
	}
}