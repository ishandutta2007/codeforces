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
#include <list>
#include <set>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<pair<int, int>> turning;
int main() {
	//ios::sync_with_stdio(false);
	int n;
	scanf("%d", &n);
	REP(i, n+1) {
		int a, b;
		scanf("%d%d", &a, &b);
		turning.push_back(pair<int, int>(a, b));
	}
	int left_turn = 0;
	int right_turn = 0;
	for (int i = 1;i < n;++i) {
		string hoge;
		if (turning[i - 1].first != turning[i].first) {
			//x axis is diff
			if (turning[i - 1].first > turning[i].first) {
				//coming from left
				hoge = "left";
			}
			else {
				//coming from right
				hoge = "right";
			}
		}
		else {
			//y axis is diff
			if (turning[i - 1].second > turning[i].second) {
				//coming from north
				hoge = "up";
			}else {
				//coming from south
				hoge = "down";
			}
		}
		if (turning[i + 1].first != turning[i].first) {
			//x
			if (turning[i + 1].first > turning[i].first) {
				//right
				if (hoge == "down") {
					right_turn++;
				}
				else if (hoge == "up") {
					left_turn++;
				}
			}
			else {
				//left
				if (hoge == "down") {
					left_turn++;
				}
				else {
					right_turn++;
				}
			}
		}
		else {
			//y
			if (turning[i + 1].second > turning[i].second) {
				//up
				if (hoge == "right") {
					left_turn++;
				}
				else if (hoge == "left") {
					right_turn++;
				}
			}
			else {
				//down
				if (hoge == "right") {
					right_turn++;
				}
				else if(hoge == "left") {
					left_turn++;
				}
			}
		}
	}
	printf("%d\n", min(right_turn, left_turn));
}