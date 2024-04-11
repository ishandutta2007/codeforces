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
#include <random>
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
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 262144
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	int n, s;
	cin >> n >> s;
	vector<pair<long long, long long>> wow;
	long long ans = 0;
	long long total_piza = 0;
	for (int i = 0;i < n;++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		total_piza += a;
		ans += a*b;
		wow.push_back(make_pair(c - b, a));
	}
	sort(wow.begin(), wow.end(),greater<pair<long long,long long>>());
	long long geko = total_piza / s;
	long long border = total_piza - geko * s;
	if (border == 0) border = s;
	long long now_ans = ans;
	long long now_math = s;
	for (int i = 0;i < wow.size();++i) {
	ok:;
		if (now_math < border) {
			if (now_math + wow[i].second >= border) {
				ans += (border - now_math) * wow[i].first;
				wow[i].second -= border - now_math;
				now_math = border;
				goto ok;
			}
			else {
				now_math += wow[i].second;
				ans += wow[i].first * wow[i].second;
				wow[i].second = 0;
			}
		}
		else {
			now_ans = max(ans, now_ans);
			long long geko = wow[i].second / s;
			ans += geko * wow[i].first * s;
			wow[i].second %= s;
			if (now_math + wow[i].second > s) {
				ans += (s - now_math) * wow[i].first;
				wow[i].second -= (s - now_math);
				now_math = s;
				now_ans = max(now_ans, ans);
				if (wow[i].second >= border) {
					ans += wow[i].second * wow[i].first;
					now_math = wow[i].second;
					now_ans = max(ans, now_ans);
					wow[i].second = 0;
				}
				else {
					ans += wow[i].second * wow[i].first;
					now_math = wow[i].second;
					wow[i].second = 0;
				}
			}
			else {
				now_math += wow[i].second;
				ans += wow[i].first * wow[i].second;
				now_ans = max(now_ans, ans);
				wow[i].second = 0;
			}
		}
	}
	cout << now_ans << endl;
	return 0;
}