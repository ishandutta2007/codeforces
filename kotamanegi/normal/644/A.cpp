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
#include <iomanip>
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
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (b*c < a) {
		printf("-1\n");
		return 0;//input is wrong
	}
	int democrats_member = a / 2;
	int republicans_member = a / 2;
	if (a % 2 != 0) democrats_member++;
	vector<int> yoko_lane[200] = {};
	for (int i = 0;i < 200;++i) {
		for (int q = 0;q < 200;++q) {
			if ((i + q) % 2 == 0) {
				yoko_lane[i].push_back(1);
			}
			else {
				yoko_lane[i].push_back(2);
			}
		}
	}
	int count_demo = 0;
	int count_repu = 0;
	for (int i = 0;i < b;++i) {
		for (int q = 0;q < c;++q) {
			if (yoko_lane[i][q] == 1) {
				if (count_demo != democrats_member) {
					count_demo++;
					printf("%d", count_demo * 2 - 1);
				}
				else {
					printf("0");
				}
			}
			else {
				if (count_repu != republicans_member) {
					count_repu++;
					printf("%d", count_repu * 2);
				}
				else {
					printf("0");
				}
			}
			if (q + 1 == c) {
				printf("\n");
			}
			else {
				printf(" ");
			}
		}
	}
}
//thank you for reading my code!