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
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
int ans[1000] = {};
int main() {
	vector<string> namelisting;
	for (int i = 'A';i <= 'Z';++i) {
		string hoge;
		hoge.push_back(i);
		namelisting.push_back(hoge);
	}
	for (int i = 0;i < 26;++i) {
		for (int q = 'a';q <= 'z';++q) {
			string hoge;
			hoge.push_back(q);
			namelisting.push_back(namelisting[i] + hoge);
		}
	}
	int n, k;
	cin >> n >> k;
	vector<string> input;
	REP(i, n - k + 1) {
		string s;
		cin >> s;
		input.push_back(s);
	}
	int cnt = 1;
	for (int i = 0;i < input.size();++i) {
		if (input[i] == "YES") {
			for (int q = 0;q < k;++q) {
				ans[i + q] = cnt;
				cnt++;
			}
			for (int q = 1;i + q < input.size();++q) {
				if (input[i + q] == "NO") {
					ans[i + q+k-1] = ans[i + q];
				}
				else {
					ans[i + q + k - 1] = cnt;
					cnt++;
				}
			}
			for (int q = 1;i - q >= 0;++q) {
				if (input[i - q] == "NO") {
					ans[i - q] = ans[i - q + k-1];
				}
				else {
					ans[i - q] = cnt;
					cnt++;
				}
			}
			for (int i = 0;i < n;++i) {
				cout << namelisting[ans[i]] << " ";
			}
			cout << endl;
			return 0;
		}
	}
	for (int i = 0;i < n;++i) {
		cout << "A" << " ";
	}
	cout << endl;
	return 0;
}