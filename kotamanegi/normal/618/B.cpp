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
int hoge[101][101] = {};
void erase(int a) {
	for (int i = 0;i < 100;++i) {
		for (int j = 0;j < 100;++j) {
			if (hoge[i][j] == a) hoge[i][j] = 0;
		}
	}
}
bool search(int x, int a) {
	for (int i = 0;i < 100;++i) {
		if (hoge[x][i] != a&&hoge[x][i] != 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		for (int q = 0;q < n;++q) {
			scanf("%d", &hoge[i][q]);
		}
	}
	int answer[1000] = {};
	for (int i = 1;i <= n-1;++i) {
		for (int q = 0;q < n;++q) {
			for (int j = 0;j < n;++j) {
				if (hoge[q][j] == i) {
					if (search(q, i) == true) {
						answer[q] = i;
						erase(i);
						goto end;
					}
					else {
						answer[j] = i;
						erase(i);
						goto end;
					}
				}
			}
		}
	end:;
	}
	if (answer[0] != 0) {
		printf("%d", answer[0]);
	}
	else {
		printf("%d", n);
	}
	for (int i = 1;i < n;++i) {
		if(answer[i] != 0)
		printf(" %d", answer[i]);
		else printf(" %d", n);
	}

}
//thank you for reading my code!