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
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
char hoge[6] = { 'A','I','U','E','O','Y' };
int main() {
	string s;
	cin >> s;
	int now = 0;
	int ans = -1;
	for (int i = 0;i < s.length();++i) {
		now++;
		REP(q, 6) {
			if (hoge[q] == s[i]) {
				ans = max(ans, now);
				now = 0;
			}
		}
	}
	now++;
	cout << max(ans,now) << endl;
}