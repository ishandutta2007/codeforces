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
	int cnt = 0;
	int ans = 0;
	cin >> n;
	int before = -1;
	for (int i = 0;i < n;++i) {
		int a;
		cin >> a;
		if (a > before) {
			before = a;
			cnt++;
		}else{
			before = a;
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	cout << max(ans, cnt) << endl;
}