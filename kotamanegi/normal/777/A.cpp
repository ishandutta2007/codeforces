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
int main() {
	long long n, a;
	cin >> n >> a;
	if (a <= 2) {
		n %= 6;
		for (int i = 0;i < 3;++i) {
				int now_itr = i;
				for (int q = 0;q < n;++q) {
					if (q % 2 == 0) {
						if (now_itr == 0) {
							now_itr = 1;
						}
						else if (now_itr == 1) {
							now_itr = 0;
						}
					}
					else {
						if (now_itr == 2) now_itr = 1;
						else if (now_itr == 1) now_itr = 2;
					}
				}
				if (now_itr == a) {
					cout << i << endl;
					return 0;
				}
		}
		cout << 1 << endl;
		return 0;
	}
}