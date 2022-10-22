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
long long segment_sum[300000] = {};
int main() {
	iostream::sync_with_stdio(false);
	long long n, k;
	cin >> n >> k;
	for (int i = 0;i < n;++i) {
		int tmp;
		cin >> tmp;
		segment_sum[i + 1] = segment_sum[i] + tmp;
	}
	vector<pair<long long, long long>> search_value;
	long long temporary_basis;
	for (int i = 0;i <= n;++i) {
		search_value.push_back(make_pair(segment_sum[i], i));
	}
	sort(search_value.begin(), search_value.end());
	long long ans = 0;
	long long hoge_power = 10;
	for (int i = 0;i < 15;++i) {
		hoge_power *= 10;
	}
	for (int i = n;i >= 0;--i) {
		temporary_basis = segment_sum[i];
		//log2 10^15 = 55
			long long care = 1;
			for (int q = 0;llabs(care) < hoge_power;++q) {
				long long looking = temporary_basis - care;
				//from upper
				long long top = search_value.size() - 1;
				long long bot = 0;
				while (top - bot > 1) {
					long long mid = top + bot;
					mid /= 2;
					if (search_value[mid].first == looking) {
						if (search_value[mid].second <= i) {
							bot = mid;
						}
						else {
							top = mid;
						}
					}
					else if (search_value[mid].first < looking) {
						bot = mid;
					}
					else {
						top = mid;
					}
				}
				long long upper_value = 0;
				if (search_value[top].first == looking&&search_value[top].second <= i) {
					upper_value = top;
				}
				else if (search_value[bot].first == looking &&search_value[bot].second <= i) {
					upper_value = bot;
				}
				else goto failed;
				top = search_value.size() - 1;
				bot = 0;
				long long botter_value = 0;
				while (top - bot > 1) {
					long long mid = top + bot;
					mid /= 2;
					if (search_value[mid].first >= looking) {
						top = mid;
					}
					else {
						bot = mid;
					}
				}
				if (search_value[bot].first == looking&&search_value[bot].second <= i) {
					botter_value = bot;
				}
				else if (search_value[top].first == looking &&search_value[top].second <= i) {
					botter_value = top;
				}
				else goto failed;
				ans += max(upper_value - botter_value + 1, (long long)0);
			failed:;
				care *= k;
				if (k == 1) break;
				if (k == -1 && q == 1) break;
			}
	}
	cout << ans << endl;
	return 0;
}