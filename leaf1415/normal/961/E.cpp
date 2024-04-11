#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005];
vector<P> vec;

llint bit[200005];
llint sum(llint i)
{
	llint ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i&(-i);
	}
	return ret;
}
void add(llint i, llint x)
{
	while(i <= n){
		bit[i] += x;
		i += i&(-i);
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) vec.push_back( make_pair(a[i], i) );
	sort(vec.begin(), vec.end());
	
	llint ans = 0, pos = 0;
	for(llint i = 1; i <= n; i++){
		if(a[i] > i){
			ans += min(max(i, a[i]), n) - i;
			ans -= sum(min(max(i, a[i]), n)) - sum(i);
		}
		while(pos < vec.size() && vec[pos].first <= i){
			add(vec[pos].second, 1);
			pos++;
		}
	}
	cout << ans << endl;
	return 0;
}