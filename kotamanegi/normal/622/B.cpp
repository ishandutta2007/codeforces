#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <list>
#include <typeinfo>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main(){
	string a;
	cin >> a;
	int b;
	cin >> b;
	int minute = (((int)a[0]-48) * 10 + ((int)a[1]-48)),second = (((int)a[3]-48) * 10+((int)a[4]-48));
	for (int i = 0;i < b;++i) {
		second++;
		if (second == 60) {
			minute++;
			second = 0;
			if (minute == 24) minute = 0;
		}
	}
	if (minute < 10) {
		cout << "0" << minute;
	}
	else {
		cout << minute;
	}
	cout << ":";
	if (second < 10) {
		cout << "0" << second;
	}
	else {
		cout << second;
	}
}