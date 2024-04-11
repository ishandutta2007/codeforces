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
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	int n;
	cin >> n;
	pair<int, int> hogee = make_pair(-1,-1);
	int cnt[4] = {};
	int now = -1;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		if (now == -1) {
			now = tmp;
		}
		else if (now != tmp) {
			if (hogee.first == -1) {
				hogee.first = tmp;
			}else if(hogee.first != tmp){
				if (hogee.second == -1) {
					hogee.second = tmp;
				}
				else if (hogee.second == tmp) {
					cnt[2]++;
				}
				else {
					cout << "NO" << endl;
					return 0;
				}
			}
			else {
				cnt[1]++;
			}
		}
		else {
			cnt[0]++;
		}
	}
	bool can_YES = false;
	vector<pair<int, int>> wow;
	if (now != -1) {
		wow.push_back(make_pair(now, cnt[0]+1));
	}
	if (hogee.first != -1) {
		wow.push_back(make_pair(hogee.first, cnt[1]+1));
	}
	if (hogee.second != -1) {
		wow.push_back(make_pair(hogee.second, cnt[2]+1));
	}
	sort(wow.begin(), wow.end());
	if (wow.size() == 1) {
		can_YES = true;
	}
	else {
		if (wow.size() == 2) {
			can_YES = true;
		}
		else {
			if (( wow[1].first - wow[0].first) == (wow[2].first-wow[1].first)) {
				can_YES = true;
			}
		}
	}
	if	(can_YES == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	
return	0;
}