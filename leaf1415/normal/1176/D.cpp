#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
multiset<llint> S, ans;
llint prime[3000005];
vector<llint> pvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint b;
	for(int i = 1; i <= 2*n; i++){
		cin >> b;
		S.insert(b);
	}
	
	
	for(int i = 2; i < 3000005; i++){
		if(prime[i]) continue;
		pvec.push_back(i);
		for(int j = 2*i; j < 3000005; j+=i){
			if(prime[j] == 0) prime[j] = i;
		}
	}
	
	for(int i = 0; i < n; i++){
		auto p = S.end();
		p--;
		llint x = *p;
		if(prime[x] == 0){
			llint id = lower_bound(pvec.begin(), pvec.end(), x) - pvec.begin() + 1;
			ans.insert(id);
			S.erase(S.lower_bound(id));
		}
		else{
			llint d = x / prime[x];
			ans.insert(x);
			S.erase(S.lower_bound(d));
		}
		S.erase(p);
	}
	for(auto it = ans.begin(); it != ans.end(); it++) cout << *it << " "; cout << endl;
	
	return 0;
}