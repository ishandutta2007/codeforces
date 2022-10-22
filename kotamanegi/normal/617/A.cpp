#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
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
#define REP(a,b) for(int a = 0;a < b;++a)
int main() {
	int n;
	scanf("%d", &n);
	int num = n / 5;
	if (n % 5 != 0) num++;
	printf("%d\n", num);
}
//thank you for reading my code!