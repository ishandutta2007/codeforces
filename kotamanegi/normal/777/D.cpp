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
int main() {
	int n;
	cin >> n;
	vector<string> s;
	REP(i, n) {
		string q;
		cin >> q;
		s.push_back(q);
	}
	for (int i = n - 2;i >= 0;--i) {
		string a;
		bool winning = false;
		for (int q = 0;q < s[i].length();++q) {
			if (winning == false&&(q >= s[i+1].length()||s[i][q] > s[i+1][q])) break;
			a.push_back(s[i][q]);
			if (q < s[i+1].length()&&s[i][q] < s[i + 1][q]) winning = true;
		}
		s[i] = a;
	}
	for (int i = 0;i < n;++i) {
		cout << s[i] << endl;
	}
	return 0;
}