#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main(){
	iostream::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	queue<string> inputs;
	inputs.push(s);
	set<string> hoget;
	hoget.insert(s);
	long long ans = 0;
	while (inputs.empty() == false) {
		string now = inputs.front();
		inputs.pop();
		k--;
		ans += n - now.length();
		if (k == 0) {
			cout << ans << endl;
			return 0;
		}
		for (int q = 0; q < now.length(); ++q) {
			string b;
			REP(j, q) {
				b.push_back(now[j]);
			}
			for (int j = q + 1; j < now.length(); ++j) {
				b.push_back(now[j]);
			}
			if (hoget.find(b) == hoget.end()) {
				hoget.insert(b);
				inputs.push(b);
			}
		}
	}
	cout << -1 << endl;
	return 0;
}