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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
int main(){
	string s;
	cin >> s;
	cout << 0;
	s.push_back('b');
	for (int i = 1; i < s.length()-1; ++i) {
		int next_output = 0;
		if (s[i] == 'b') {
			if (s[i + 1] == 'a') {
				next_output = 1;
			}
			else {
				next_output = 0;
			}
		}
		else {
			if (s[i + 1] == 'b') {
				next_output = 1;
			}
			else {
				next_output = 0;
			}
		}
		cout << " " << next_output;
	}
	cout << endl;
	return 0;
}