#include <bits/stdc++.h>
using namespace std;

const long long MAXAI = 1000000000000ll;

int get_first_bit(long long n){
	return 63 - __builtin_clzll(n);
}

int get_bit_count(long long n){
	return __builtin_popcountll(n);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for(int test_number = 0; test_number < t; test_number++){
		long long n; cin >> n;
		//Computing factorials <= MAXAI
		vector<long long> fact;
		long long factorial = 6, number = 4;
		while(factorial <= MAXAI){
			fact.push_back(factorial);
			factorial *= number;
			number++;
		}
		//Computing masks of factorials
		vector<pair<long long, long long>> fact_sum(1 << fact.size());
		fact_sum[0] = {0, 0};
		for(int mask = 1; mask < (1 << fact.size()); mask++){
			auto first_bit = get_first_bit(mask);
			fact_sum[mask].first = fact_sum[mask ^ (1 << first_bit)].first + fact[first_bit];
			fact_sum[mask].second = get_bit_count(mask);
		}
		long long res = get_bit_count(n);
		for(auto i : fact_sum){
			if(i.first <= n){
				res = min(res, i.second + get_bit_count(n - i.first));
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}