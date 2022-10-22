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
	int n;
	cin >> n;
	int a=0, b = 0;
	for (int i = 0;i < n;++i) {
		int c, d;
		cin >> c >> d;
		if (c > d) {
			a++;
		}
		else if (c < d) {
			b++;
		}
	}
	if (a == b) {
		cout << "Friendship is magic!^^" << endl;
		return 0;
	}
	if (a < b) {
		cout << "Chris" << endl;
		return 0;
	}
	cout << "Mishka" << endl;
}