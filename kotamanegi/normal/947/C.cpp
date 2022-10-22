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
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
unordered_map<int,int> cnter[40];
int main(){
	srand(time(0));
	long long masking = rand();
	int n;
	scanf("%d", &n);
	vector<int> letters;
	REP(i, n) {
		int a;
		scanf("%d", &a);
		letters.push_back(a);
	}
	int hoge = 1;
	for (int i = 0; i < 30; ++i) {
		hoge *= 2LL;
	}
	REP(i, n) {
		int a;
		scanf("%d", &a);
		int bobo = hoge;
		int geko = 0;
		int keta = 0;
		while (bobo != 0) {
			geko += (a&bobo);
			cnter[keta][(geko^masking)]++;
			bobo /= 2LL;
			keta++;
		}
	}
	REP(i, n) {
		int ans = 0;
		int boo = hoge;
		int keta = 0;
		while (boo != 0) {
			if ((boo & letters[i]) == 0) {
				//bit is 0 -> should be 0
				if (cnter[keta].find((ans^masking)) != cnter[keta].end()) {
					//go 0
					cnter[keta][(ans^masking)]--;
					if (cnter[keta][(ans^masking)] == 0) {
						cnter[keta].erase((ans^masking));
					}
				}
				else {
					//go 1
					ans += boo;
					cnter[keta][(ans^masking)]--;
					if (cnter[keta][(ans^masking)] == 0) {
						cnter[keta].erase((ans^masking));
					}
				}
			}
			else {
				if (cnter[keta].find(((ans+boo)^masking)) != cnter[keta].end()) {
					//go 1
					ans += boo;
					cnter[keta][(ans^masking)]--;
					if (cnter[keta][(ans^masking)] == 0) {
						cnter[keta].erase((ans^masking));
					}
				}
				else {
					//go 0
					cnter[keta][(ans^masking)]--;
					if (cnter[keta][(ans^masking)] == 0) {
						cnter[keta].erase((ans^masking));
					}
				}
			}
			boo /= 2LL;
			keta++;
		}
		ans ^= letters[i];
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}