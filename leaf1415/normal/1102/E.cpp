#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
#define llint long long
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005];
map<llint, llint> Left, Right;
vector<P> vec;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		if(!Left.count(a[i])) Left[a[i]] = i;
	}
	for(int i = n; i >= 1; i--){
		if(!Right.count(a[i])) Right[a[i]] = i;
	}
	for(auto it = Left.begin(); it != Left.end(); it++){
		vec.push_back(make_pair(it->second, Right[it->first]));
	}
	sort(vec.begin(), vec.end());
	
	llint cnt = n-1, l = 0, r = 0;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].first <= r){
			r = max(r, vec[i].second);
		}
		else{
			cnt -= r-l;
			l = vec[i].first;
			r = vec[i].second;
		}
	}
	cnt -= r-l;
	
	llint ans = 1;
	for(int i = 0; i < cnt; i++) ans *= 2, ans %= mod;
	cout << ans << endl;
	
	return 0;
}