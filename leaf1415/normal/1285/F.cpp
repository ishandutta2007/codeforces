#include <iostream>
#include <vector>
#include <stack>
#define llint long long

using namespace std;

llint n;
llint cnt[100005], mcnt[100005];
bool prime[100005];
vector<llint> vec;
vector<llint> fvec[100005], pvec[100005];
stack<llint> stk;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		cnt[x]++;
	}
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(cnt[i] >= 2) ans = i;
	}
	prime[1] = true;
	for(int i = 2; i < 405; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 100005; j+=i) prime[j] = true;
	}
	
	for(int i = 1; i < 100005; i++){
		for(int j = i; j < 100005; j+=i) fvec[j].push_back(i);
		if(prime[i]) continue;
		for(int j = i; j < 100005; j+=i) pvec[j].push_back(i);
	}
	
	for(int i = 1; i <= 100000; i++){
		vec.clear();
		for(int j = i; j <= 100000; j += i){
			if(cnt[j]) vec.push_back(j/i);
			mcnt[j/i] = 0;
		}
		while(stk.size()) stk.pop();
		for(int j = (int)vec.size()-1; j >= 0; j--){
			int m = (int)pvec[vec[j]].size(), M = 1<<m;
			llint sum = 0;
			for(int k = 0; k < M; k++){
				llint mul = 1, pop = 0;
				for(int l = 0; l < m; l++){
					if(k & (1<<l)) mul *= pvec[vec[j]][l], pop++;
				}
				if(pop % 2) sum -= mcnt[mul];
				else sum += mcnt[mul];
			}
			if(sum){
				while(sum){
					if(gcd(stk.top(), vec[j]) > 1){
						llint x = stk.top();
						for(int k = 0; k < fvec[x].size(); k++) mcnt[fvec[x][k]]--;
						stk.pop();
					}
					else{
						llint x = stk.top();
						ans = max(ans, x * vec[j] * i);
						for(int k = 0; k < fvec[x].size(); k++) mcnt[fvec[x][k]]--;
						stk.pop();
						sum--;
					}
				}
			}
			else{
				llint x = vec[j];
				for(int k = 0; k < fvec[x].size(); k++) mcnt[fvec[x][k]]++;
				stk.push(vec[j]);
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}