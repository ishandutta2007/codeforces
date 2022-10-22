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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
vector<string> divise[100000] = {};
int main(){
	long long n;
	cin >> n;
	string a = to_string(n);
	string s;
	cin >> s;
	vector<string> heyhey;
	heyhey.push_back("9999999999999999");
	for (int i = 0;i < 100000;++i) {
		divise[i] = heyhey;
	}
	divise[0] = vector<string>();
	for (int i = 0;i < s.length();++i) {
		string hoge;
		if (i != 0&&divise[i][0] == "9999999999999999") goto failed;
		bool die = false;
		for (int q = 0;q < a.length()&&i+q < s.length();++q) {
			hoge.push_back(s[i + q]);
			if (hoge[0] == '0')die = true;
			if (hoge.length() == a.length() && hoge >= a) goto failed;
			vector<string> now_deal = divise[i];
			now_deal.push_back(hoge);
			if (divise[i + q + 1].size() == now_deal.size()) {
				divise[i + q + 1] = min(divise[i + q + 1], now_deal);
			}
			else if (divise[i + q + 1].size() > now_deal.size()||divise[i+q+1][0] == "9999999999999999") {
				divise[i + q + 1] = now_deal;
			}
			if (die == true) goto failed;
		}
	failed:;
	}
	long long ans = 0;
	long long bai = 1;
	for (int i = divise[s.length()].size() - 1;i >= 0;--i) {
		long long hoge = stoi(divise[s.length()][i]);
		ans += hoge*bai;
		bai *= n;
	}
	cout << ans << endl;
	return 0;
	return 0;
}