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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 1000000000000
vector<int> vertex[2000];
int arrive[2000] = {};
int dp[1200][1200] = {};
vector<tuple<int, int,vector<int>>> weight_dp;
int main() {
	int n, m, maxer;
	cin >> n >> m >> maxer;
	vector<int> w, b;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		w.push_back(tmp);
	}
	REP(i, n) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		vertex[a-1].push_back(b-1);
		vertex[b-1].push_back(a-1);
	}
	for (int i = 0;i < n;++i) {
		if (arrive[i] == false) {
			arrive[i] = true;
			int omori = w[i];
			int beautiful = b[i];
			vector<int> gone;
			queue<int> gogo;
			gogo.push(i);
			while (gogo.empty() == false) {
				int wee = gogo.front();
				gone.push_back(wee);
				gogo.pop();
				for (int q = 0;q < vertex[wee].size();++q) {
					if (arrive[vertex[wee][q]] == false) {
						arrive[vertex[wee][q]] = true;
						omori += w[vertex[wee][q]];
						beautiful += b[vertex[wee][q]];
						gogo.push(vertex[wee][q]);
					}
				}
			}
			weight_dp.push_back(make_tuple(omori, beautiful,gone));
		}
	}
	//do dp
	for (int i = 0;i < weight_dp.size();++i) {
		for (int q = 1;q <= maxer;++q) {
			if (q - get<0>(weight_dp[i]) >= 0) {
				dp[i + 1][q] = max(dp[i][q - get<0>(weight_dp[i])] + get<1>(weight_dp[i]),max(dp[i + 1][q - 1],dp[i][q]));
			}
			else {
				dp[i + 1][q] = max(dp[i][q],dp[i+1][q-1]);
			}
		}
		for (int q = 1;q <= maxer;++q) {
			for (int j = 0;j < get<2>(weight_dp[i]).size();++j) {
				if (q - w[get<2>(weight_dp[i])[j]] >= 0) {
					dp[i + 1][q] = max(dp[i + 1][q], dp[i][q - w[get<2>(weight_dp[i])[j]]] + b[get<2>(weight_dp[i])[j]]);
				}
			}
		}
	}
	cout << dp[weight_dp.size()][maxer] << endl;
	return 0;
}