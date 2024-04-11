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
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < m;++q) {
			string hoge;
			cin >> hoge;
			if(hoge == "C"||hoge=="M"||hoge=="Y"){
				cout << "#Color" << endl;
				return 0;
			}
		}
	}
	cout << "#Black&White" << endl;
}