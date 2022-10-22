#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define llint long long
 
using namespace std;
 
llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
 
llint n;
llint b[200005];
llint cnt[65];
vector<llint> vec, vec2;
 
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	/*llint d = 0;
	for(int i = 1; i <= n; i++) d = gcd(d, b[i]);
	*/
	for(int i = 1; i <= n; i++){
		llint x = 0;
		for(llint t = b[i]; t%2==0; t/=2) x++;
		cnt[x]++;
	}
	llint mn = -1e9, mn_i;
	for(int i = 0; i < 65; i++){
		if(mn < cnt[i]){
			mn = cnt[i];
			mn_i = i;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!(b[i] % (1LL<<mn_i) == 0 && b[i] % (1LL<<(mn_i+1)))) vec.push_back(b[i]);
	}
	cout << (int)vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	return 0;
}