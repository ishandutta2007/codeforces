#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int, int> dp;
int solve(int t){
	if(dp.find(t) != dp.end()) return dp[t];
	if(t <= 1){
		dp[t] = 0;
		return dp[t];
	}
	map<int,int> v;
	for(int a = 1; a <= 30; a++){
		int s = t & ((1<<a) - 1);
		s = s | (t >> a);
		if(s & 1) s ^= 1;
		if(s == t) continue;
		v[solve(s)] = 1;
	}
	for(int i = 0; ; i++){
		if(v[i] == 0){
			dp[t] = i;
			return dp[t];
		}
	}
}
int main(){
	int n;
	cin >> n;
	int a[n];
	map<int,int> pr;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		int b = a[i];
		for(int p = 2; p*p <= a[i]; p++){
			if(b % p == 0){
				pr[p] = 1;
				while(b % p == 0) b /= p;
			}
		}
		if(b > 1){
			pr[b]++;
		}
	}
	LL ans = 0;
	for(auto it = pr.begin(); it != pr.end(); it++){
		int p = it->first;
		int q = 0;
		for(int i = 0; i < n; i++){
			int k = 0;
			if(a[i] % p == 0){
				int t = 0;
				while(a[i] % p == 0){
					a[i] /= p;
					t++;
				}
				q |= (1<<t);
			}
		}
		ans ^= solve(q);
	}
	if(ans == 0){
		cout << "Arpa" << endl;
	} else {
		cout << "Mojtaba" << endl;
	}
}