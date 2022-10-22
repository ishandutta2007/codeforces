#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint a, m;
llint cnt[10005];

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint calc(llint d)
{
	llint r = (-a%d+d)%d;
	llint ret = m / d;
	if(m%d > r) ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> a >> m;
		llint d = gcd(a, m);
		
		vector<llint> vec;
		for(llint i = 1; i*i <= m; i++){
			if(m % i == 0){
				if(i % d == 0) vec.push_back(i);
				if(m/i % d == 0)vec.push_back(m/i);
			}
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		reverse(vec.begin(), vec.end());
		
		for(int i = 0; i < vec.size(); i++) cnt[i] = 0;
		for(int i = 0; i < vec.size(); i++){
			llint sum = calc(vec[i]);
			for(int j = 0; j < i; j++){
				if(vec[j] % vec[i]) continue;
				sum -= cnt[j];
			}
			cnt[i] = sum;
		}
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] == d){
				cout << cnt[i] << endl;
				break;
			}
		}
	}
	
	return 0;
}