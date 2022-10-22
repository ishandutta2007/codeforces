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
	map<int, int> wow;
	REP(i, n) {
		int a;
		cin >> a;
		wow[a]++;
	}
	if (wow.size() == 2) {
		int geko = 0;
		for (auto i = wow.begin();i != wow.end();++i) {
			if (i == wow.begin()) geko = i->second;
			else {
				if (geko != i->second)goto failed;
			}
		}
		cout << "YES" << endl;
		for (auto i = wow.begin();i != wow.end();++i) {
			cout << i->first << " ";
		}
		cout << endl;
		return 0;
	}
failed:;
	cout << "NO" << endl;
	return 0;
}