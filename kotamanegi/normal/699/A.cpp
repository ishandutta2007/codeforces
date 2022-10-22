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
int main(){
	int n;
	cin >> n;
	string hoge;
	cin >> hoge;
	vector<int> wow;
	for (int i = 0;i < n;++i) {
		int a;
		cin >> a;
		wow.push_back(a);
	}
	long long ans = 999999999999999999;
	for (int i = 0;i < n-1;++i) {
		if (hoge[i] == 'R'&&hoge[i + 1] == 'L') {
			ans = min(ans, (long long)((wow[i + 1] + wow[i]) / 2 - wow[i]));
		}
	}
	if (ans == 999999999999999999) ans = -1;
	cout << ans << endl;
}