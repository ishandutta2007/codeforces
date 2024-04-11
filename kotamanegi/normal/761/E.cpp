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
#define LONG_INF 800000000000000000
vector<tuple<int,long long, long long>> ans;
vector<int> vertexs[40];
int gone[40] = {};
int main() {
#define int long long
	long long n;
	cin >> n;
	REP(i, n-1) {
		int a,b;
		cin >> a >> b;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	queue<tuple<long long, long long,int,int,long long>> now;
	gone[1] = true;
	now.push(make_tuple(0, 0, 1,0,(1 << n)));
	ans.push_back(make_tuple(1, 0, 0));
	while (now.empty() == false) {
		tuple<long long, long long, int, int,long long> good = now.front();
		now.pop();
		for (int i = 0;i < vertexs[get<2>(good)].size();++i) {
			if (gone[vertexs[get<2>(good)][i]] == false) {
				gone[vertexs[get<2>(good)][i]] = true;
				if ((get<3>(good)&1) == 0) {
					ans.push_back(make_tuple(vertexs[get<2>(good)][i],get<0>(good) - get<4>(good),get<1>(good)));
					now.push(make_tuple(get<0>(good) - get<4>(good), get<1>(good), vertexs[get<2>(good)][i],2, get<4>(good) / 2));
					get<3>(good) += 1;
					goto ok;
				}
				else if ((get<3>(good)&2) == 0) {
					ans.push_back(make_tuple(vertexs[get<2>(good)][i], get<0>(good) + get<4>(good), get<1>(good)));
					now.push(make_tuple(get<0>(good) + get<4>(good), get<1>(good), vertexs[get<2>(good)][i],1, get<4>(good) / 2));
					get<3>(good) += 2;
					goto ok;
				}
				else if ((get<3>(good) & 4) == 0) {
					ans.push_back(make_tuple(vertexs[get<2>(good)][i], get<0>(good), get<1>(good) - get<4>(good)));
					now.push(make_tuple(get<0>(good), get<1>(good)-get<4>(good), vertexs[get<2>(good)][i],8, get<4>(good) / 2));
					get<3>(good) += 4;
					goto ok;
				}
				else if ((get<3>(good) & 8) == 0) {
					ans.push_back(make_tuple(vertexs[get<2>(good)][i], get<0>(good), get<1>(good) + get<4>(good)));
					now.push(make_tuple(get<0>(good), get<1>(good) + get<4>(good), vertexs[get<2>(good)][i], 4, get<4>(good) / 2));
					get<3>(good) += 8;
					goto ok;
				}
				cout << "NO" << endl;
				return 0;
			ok:;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << "YES" << endl;
	for (int i = 0;i < ans.size();++i) {
		cout << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
	}
	return 0;
}