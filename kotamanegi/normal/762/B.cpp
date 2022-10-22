#define  _CRT_SECURE_NO_WARNINGS
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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 8000000000000000000
int main(){
#define int long long
	int a, b, c;
	cin >> a >> b >> c;
	int m;
	cin >> m;
	vector<pair<int, int>> usb;
	REP(i, m) {
		int a;
		cin >> a;
		string s;
		cin >> s;
		if (s == "USB") {
			usb.push_back(make_pair(a,0));
		}else{
			usb.push_back(make_pair(a,1));
		}
	}
	sort(usb.begin(), usb.end());
	long long cnt = 0;
	long long money = 0;
	for (int i = 0;i < m;++i) {
		if (usb[i].second == 0) {
			if (a != 0) {
				a--;
				cnt++;
				money += usb[i].first;
			}
			else if (c != 0) {
				c--;
				cnt++;
				money += usb[i].first;
			}
		}else{
			if (b != 0) {
				b--;
				cnt++;
				money += usb[i].first;
			}else if(c != 0){
				c--;
				cnt++;
				money += usb[i].first;
			}
		}
	}
	cout << cnt << " " << money << endl;
	return 0;
}