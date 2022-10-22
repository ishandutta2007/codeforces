#include <iostream>
#include <vector>
#include <set>
#define llint long long

using namespace std;

struct BIT{
	int size;
	vector<int> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	int query(int i){
		int ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, int x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n;
llint a[300005];
vector<llint> vec[300005], uvec[300005];
vector<llint> out[300005];
multiset<llint> S;
llint uni[300005];
BIT bit(300005);


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < vec[i].size(); j++){
			out[vec[i][j-1]].push_back(vec[i][j]);
			S.insert(vec[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(S.size() == 0) uni[i] = n-i+1;
		else uni[i] = *S.begin() - i;
		for(int j = 0; j < out[i].size(); j++){
			S.erase(S.lower_bound(out[i][j]));
		}
	}
	for(int i = 1; i <= n; i++) uvec[uni[i]].push_back(i);
	
	S.clear();
	S.insert(0), S.insert(n+1);
	llint ans = 0;
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < uvec[i].size(); j++) bit.add(uvec[i][j], 1);
		for(int j = 0; j < vec[i].size(); j++){
			auto p = S.upper_bound(vec[i][j]);
			llint r = *p; p--;
			llint l = *p; l++, r--;
			l = max(l, vec[i][j]-i+1), r = min(r-i+1, vec[i][j]);
			if(l > r) continue;
			ans += bit.query(r) - bit.query(l-1);
		}
		for(int j = 0; j < vec[i].size(); j++) S.insert(vec[i][j]);
	}
	cout << ans << endl;
	
	return 0;
}