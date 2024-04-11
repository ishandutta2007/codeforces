#define _CRT_SECURE_NO_WARNINGS
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
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
map<int,char> base64;
map<char, int> counters;
int main(){
	string s;
	cin >> s;
	int counter = 0;
	for (int i = '0';i <= '9';++i) {
		base64[counter] = i;
		counter++;
	}
	for (int i = 'A';i <= 'Z';++i) {
		base64[counter] = i;
		counter++;
	}
	for (int i = 'a';i <= 'z';++i) {
		base64[counter] = i;
		counter++;
	}
	base64[62] = '-';
	base64[63] = '_';
	for (int i = 0;i < 64;++i) {
		for (int q = 0;q < 64;++q) {
			counters[base64[i&q]]++;
		}
	}
	long long ans = 1;
	for (int i = 0;i < s.length();++i) {
		ans *= counters[s[i]];
		ans %= MAX_MOD;
	}
	cout << ans%MAX_MOD << endl;
}