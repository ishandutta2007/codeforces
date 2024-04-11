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
double ans[100][100] = {};
void pour(int doko,int yoko,double ryo,int n) {
	ans[doko][yoko] += ryo;
	if (ans[doko][yoko] > 1.0) {
		double hoge = ans[doko][yoko] - 1.0;
		ans[doko][yoko] = 1.0;
		if (doko < n) {
			pour(doko + 1, yoko, hoge / 2, n);
			pour(doko + 1, yoko + 1, hoge / 2, n);
		}
	}
}
int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 0;i < t;++i) {
		pour(1, 1, 1,n);
	}
	int ok = 0;
	for (int i = 0;i < 100;++i) {
		for (int q = 0;q < 100;++q) {
			if (ans[i][q] == 1)ok++;
		}
	}
	cout << ok << endl;
}