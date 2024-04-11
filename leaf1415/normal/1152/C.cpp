#include <iostream>
#include <set>
#include <utility>
#define llint long long
#define inf ((llint)4e18)

using namespace std;

llint a, b;
set<llint> S;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	cin >> a >> b;
	if(a > b) swap(a, b);
	llint d = b-a;
	
	if(d == 0){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i = 1; i <= min(d, 100005LL); i++){
		if(d%i==0) S.insert(i), S.insert(d/i);
	}
	pair<llint, llint> ans = make_pair(inf, inf);
	for(auto it = S.begin(); it != S.end(); it++){
		llint x = *it;
		llint k = (a+x-1)/x*x - a;
		llint l = (a+k)/x*(b+k);
		//cout << x << " " << k << " " << l << endl;
		ans = min(ans, make_pair(l, k));
	}
	cout << ans.second << endl;
	
	return 0;
}