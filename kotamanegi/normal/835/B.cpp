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
#include<fstream>
#include <unordered_map>  
using namespace std;
#define eps 0.00000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define f(n) for(int i=0;i<n;++i)
#define REP(i,n) for(long long i = 0;i < n;++i) 
int main() {
#define int long long
	int k;
	cin >> k;
	string s;
	cin >> s;
	map<int, int> nya;
	for (int i = 0;i < s.length();++i) {
		nya[s[i] - '0']++;
	}
	int ans = 0;
	for (int i = 0;i < 10;++i) {
		k -= nya[i] * i;
	}
	for (int i = 0;i < 10;++i) {
		while (k > 0 && nya[i] != 0) {
			nya[i]--;
			ans++;
			k -= (9 - i);
		}
		if (k <= 0) break;
	}
	cout << ans << endl;
	return 0;
}