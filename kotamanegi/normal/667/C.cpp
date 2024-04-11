#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include<map>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
using namespace std;
set<string> listing;
bool dp[1000000][2] = {};
int main() {
	string s;
	cin >> s;
	if (s.length() < 7) {
		cout << "0" << endl;
		return 0;
	}
	if (s.length() == 7) {
		cout << "1" << endl;
		cout << s.substr(5, 2) << endl;
		return 0;
	}
	dp[s.length() - 2][0] = true;
	dp[s.length() - 3][1] = true;
	listing.insert(s.substr(s.length()-2,2));
	listing.insert(s.substr(s.length() - 3, 3));
	for (int i = s.length() - 2;i >= 0;--i) {
		if (dp[i][1] == true) {
			//3char
			if (s.substr(i - 3,3) != s.substr(i,3)&&i-3 > 4) {
				listing.insert(s.substr(i - 3,3));
				dp[i - 3][1] = true;
			}
			if (i - 2 > 4) {
				listing.insert(s.substr(i - 2,2));
				dp[i - 2][0] = true;
			}
		}
		if (dp[i][0] == true) {
			//2char
			if (i - 3 > 4){
				listing.insert(s.substr(i-3,3));
				dp[i - 3][1] = true;
			}
			if (s.substr(i - 2,2) != s.substr(i,2) && i - 2 > 4) {
				listing.insert(s.substr(i - 2,2));
				dp[i - 2][0] = true;
			}
		}
	}
	cout << listing.size() << endl;
	for (auto itr = listing.begin(); itr != listing.end();++itr) {
		cout << *itr << endl;
	}
}