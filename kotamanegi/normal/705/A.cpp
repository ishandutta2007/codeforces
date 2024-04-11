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
	long long n;
	cin >> n;
	for (int i = 0;i < n;++i) {
		if (i != 0) cout << "that ";
		if (i % 2 == 0) {
			cout << "I hate ";
		}else{
			cout << "I love ";
		}
	}
	cout << "it" << endl;
	return 0;
}