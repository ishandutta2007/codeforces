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
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 262144
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt[2] = {};
	for (int i = 1;i < s.length();++i) {
		if (s[i] != s[i - 1]) {
			if (s[i - 1] == 'F') {
				cnt[1]++;
			}
			else cnt[0]++;
		}
	}
	if (cnt[0] > cnt[1]) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;
}