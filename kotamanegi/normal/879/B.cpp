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
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 524288
int main() {
#define int long long
	int n, k;
	cin >> n >> k;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	int now_itr = 0;
	int now_cnt = 0;
	for (int i = 1;i < n;++i) {
		if (a[i] > a[now_itr]) {
			now_itr = i;
			now_cnt = 1;
		}
		else {
			now_cnt++;
			if (now_cnt == k) {
				cout << a[now_itr] << endl;
				return 0;
			}
		}
	}
	cout << a[now_itr] << endl;
	return 0;
}
/*
string modulo(string a,int keta) {
	if (a.length() > keta) {
		a.erase(a.begin(), a.end() - keta);
	}
	reverse(a.begin(), a.end());
	while (a.length() != 1) {
		if (a[a.length() - 1] != '0')break;
		a.pop_back();
	}
	reverse(a.begin(), a.end());
	return a;
}
string pluss(string a, string b) {
	if (a.length() < b.length()) swap(a, b);
	reverse(a.begin(), a.end());
	a.push_back('0');
	reverse(a.begin(), a.end());
	int kuriagari = 0;
	for (int i = 0;i < a.length();++i) {
		int geko = (a[a.length() - i - 1]-'0')+ kuriagari;
		if ((int)(b.length()) - i - 1 >= 0) {
			geko += (b[b.length() - i - 1]-'0');
		}
		kuriagari = geko / 10;
		a[a.length() - i - 1] = (geko%10) + '0';
	}
	if (a[0] == '0') {
		a.erase(a.begin() + 0);
	}
	return a;
}
string multiply(string a, string b) {
	string ans = "0";
	string geko = a;
	for (int i = b.length() - 1;i >= 0;--i) {
		if (b[i] != '0') {
			for (int q = 0;q < b[i] - '0';++q) {
				ans = pluss(ans, geko);
			}
		}
		geko.push_back('0');
	}
	return ans;
}
string geko[2000] = {};
int main() {
	string input;
	cin >> input;
	queue<pair<string, int>> wow;
	geko[0] = "1";
	for (int i = 1;i < 2000;++i) {
		string s = geko[i - 1];
		s.push_back('0');
		geko[i] = s;
	}
	wow.push(make_pair("0", 0));
	map<string, int> listings;
	while (wow.empty() == false) {
		pair<string, int> now = wow.front();
		wow.pop();
		for (int i = 0;i < 10;++i) {
			for (int q = 0;q < 10;++q) {
				string tmp;
				tmp.push_back(q + '0');
				tmp.push_back(i + '0');
				string waw = pluss(multiply(geko[now.second], tmp), now.first);
				waw = multiply(waw, waw);
				if (modulo(waw, now.second + 2) == modulo(input,now.second+2)) {
					if (now.second % 100 == 0) {
						cout << now.first << endl;
						cout << endl;
					}
					string gea;
					if (i != 0) {
						gea.push_back(i + '0');
						if (listings[pluss(multiply(geko[now.second], gea), now.first)] == false) {
							listings[pluss(multiply(geko[now.second], gea), now.first)] = true;
							wow.push(pair<string, int>(pluss(multiply(geko[now.second], gea), now.first), now.second + 1));
						}
					}
					else {
						tmp = "0" + now.first;
						if (listings[tmp] == false) {
							listings[tmp] = true;
							wow.push(make_pair(tmp, now.second + 1));
						}
					}
					goto ok;
				}
			}
		ok:;
		}
	}
	return 0;
}
*/