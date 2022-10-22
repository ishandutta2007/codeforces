#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#define llint long long

using namespace std;

int T;
int n;
vector<llint> d;
vector<llint> vec;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
llint lcm(llint a, llint b)
{
	return a/gcd(a, b)*b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		d.clear();
		
		llint x;
		for(int i = 0; i < n; i++){
			cin >> x;
			d.push_back(x);
		}
		d.push_back(1);
		sort(d.begin(), d.end());
		
		llint l = 1;
		for(int i = 0; i < d.size(); i++){
			l = lcm(l, d[i]);
			if(l >= 1e12+7){
				cout << -1 << endl;
				goto end;
			}
		}
		
		if(d.back() == l){
			for(int i = 2; i <= 1000000; i++){
				if(l % i == 0){
					l *= i;
					break;
				}
			}
		}
		d.push_back(l);
		
		vec.clear();
		for(int i = 1; i <= 1000000; i++){
			if(l % i == 0) vec.push_back(i), vec.push_back(l/i);
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		if(d == vec) cout << l << endl;
		else cout << -1 << endl;
		
		end:;
	}
	
	return 0;
}