#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
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
#include <map>
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
using namespace std;
map<int,int> being_used;
int sosuu[40000000] = {};
vector<int> sosuu_list;
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= 4000000; ++i) {
		if (sosuu[i] == 0) {
			sosuu_list.push_back(i);
			for (int q = 1; i*q <= 4000000; ++q) {
				sosuu[i*q] = 1;
			}
		}
	}
	srand(time(NULL));
	int hoget = rand();
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
		assert(tmp >= 2);
	}
	cout << a[0];
	long long geko = a[0];
	for (int i = 0; i < sosuu_list.size()&&sosuu_list[i] <= sqrt(geko); ++i) {
		if (geko % sosuu_list[i] == 0) {
			being_used[(hoget^sosuu_list[i])] = 1;
			while (geko % sosuu_list[i] == 0) {
				geko /= sosuu_list[i];
			}
		}
	}
	being_used[(hoget^geko)] = 1;
	for (int i = 1; i < a.size(); ++i) {
		int geko = a[i];
		for (int q = 0; q < sosuu_list.size() && sosuu_list[q] <= sqrt(geko); ++q) {
			if (geko % sosuu_list[q] == 0) {
				while (geko % sosuu_list[q] == 0) {
					geko /= sosuu_list[q];
				}
				if (being_used[(hoget^sosuu_list[q])] == 1) {
					for (int t = a[i] + 1; t >= 0; ++t) {
						int geko = t;
						int failed = 0;
						for (int q = 0; q < sosuu_list.size() && sosuu_list[q] <= sqrt(geko); ++q) {
							if (geko % sosuu_list[q] == 0) {
								while (geko % sosuu_list[q] == 0) {
									geko /= sosuu_list[q];
								}
								if (being_used[(hoget^sosuu_list[q])] == 1) {
									failed = 1;
									break;
								}
							}
						}
						if (geko >= 2 && being_used[(hoget^geko)] == 1) failed = 1;
						if (failed == 0) {
							geko = t;
							for (int q = 0; q < sosuu_list.size() && sosuu_list[q] <= sqrt(geko); ++q) {
								if (geko % sosuu_list[q] == 0) {
									while (geko % sosuu_list[q] == 0) {
										geko /= sosuu_list[q];
									}
									being_used[(hoget^sosuu_list[q])] = 1;
								}
							}
							being_used[(hoget^geko)] = 1;
							cout << " " << t;
							break;
						}
					}
					int remaining = a.size() - i - 1;
					int now_itr = 0;
					while (remaining != 0) {
						if (being_used[(hoget^sosuu_list[now_itr])] == 0) {
							remaining--;
							being_used[(hoget^sosuu_list[now_itr])] = 1;
							cout << " " << sosuu_list[now_itr];
						}
						now_itr++;
					}
					cout << endl;
					return 0;
				}
			}
		}
		if (geko >= 2 && being_used[(hoget^geko)] == 1) {
			for (int t = a[i] + 1; t >= 0; ++t) {
				int geko = t;
				int failed = 0;
				for (int q = 0; q < sosuu_list.size() && sosuu_list[q] <= sqrt(geko); ++q) {
					if (geko % sosuu_list[q] == 0) {
						while (geko % sosuu_list[q] == 0) {
							geko /= sosuu_list[q];
						}
						if (being_used[(hoget^sosuu_list[q])] == 1) {
							failed = 1;
							break;
						}
					}
				}
				if (geko >= 2 && being_used[(hoget^geko)] == 1) failed = 1;
				if (failed == 0) {
					geko = t;
					for (int q = 0; q < sosuu_list.size() && sosuu_list[q] <= sqrt(geko); ++q) {
						if (geko % sosuu_list[q] == 0) {
							while (geko % sosuu_list[q] == 0) {
								geko /= sosuu_list[q];
							}
							being_used[(hoget^sosuu_list[q])] = 1;
						}
					}
					being_used[(hoget^geko)] = 1;
					cout << " " << t;
					break;
				}
			}
			int remaining = a.size() - i - 1;
			int now_itr = 0;
			while (remaining != 0) {
				if (being_used[(hoget^sosuu_list[now_itr])] == 0) {
					remaining--;
					being_used[(hoget^sosuu_list[now_itr])] = 1;
					cout << " " << sosuu_list[now_itr];
				}
				now_itr++;
			}
			cout << endl;
			return 0;
		}
		cout << " " << a[i];
		geko = a[i];
		for (int q = 0; q < sosuu_list.size() && sosuu_list[q] <= sqrt(geko); ++q) {
			if (geko % sosuu_list[q] == 0) {
				being_used[(hoget^sosuu_list[q])] = 1;
				while (geko % sosuu_list[q] == 0) {
					geko /= sosuu_list[q];
				}
			}
		}
		being_used[(hoget^geko)] = 1;
	}
	cout << endl;
	return 0;
}