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
int main() {
	long long n;
	cin >> n;
	long long answer = n;
	answer -= n / 2;//2
	answer -= n / 3;//3
	answer -= n / 5;//5
	answer -= n / 7;//7
	answer += n / 6;//2*3
	answer += n / 10;//2*5
	answer += n / 14;//2*7
	answer += n / 15;//3*5
	answer += n / 21;//3*7
	answer += n / 35;//5*7
	answer -= n / 30;//2*3*5
	answer -= n / 42;//2*3*7
	answer -= n / 70;//2*5*7
	answer -= n / 105;//3*5*7
	answer += n / 210;//2*3*5*7
	cout << answer << endl;
}