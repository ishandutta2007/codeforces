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
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
int main() {
	int m[5];
	int w[5];
	int h[2];
	for (int i = 0;i < 5;++i) scanf("%d", &m[i]);
	REP(i, 5) scanf("%d", &w[i]);
	REP(i, 2) scanf("%d", &h[i]);
	int score = 0;
	for (int i = 1;i <= 5;++i) {
		int scoreing = 2*i*(250-m[i-1])+(-50 * w[i-1]);
		score += max(150 * i, scoreing);
	}
	score += 100 * h[0];
	score -= 50 * h[1];
	printf("%d", score);
}