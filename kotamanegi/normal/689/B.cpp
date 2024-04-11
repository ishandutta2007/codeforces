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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
vector<int> s[300000];
int dp[300000] = {};
int main() {
	int n;
	vector<int> a;
	scanf("%d", &n);
	REP(i, n) {
		int hoge;
		scanf("%d", &hoge);
		s[i + 1].push_back(hoge);
		if (i+1 != n) {
			s[i + 1].push_back(i + 2);
		}
		if (i != 0) {
			s[i + 1].push_back(i);
		}
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > wow;
	wow.push(make_pair(0, 1));
	dp[1] = 0;
	while (wow.empty() == false) {
		int faaa = wow.top().first;
		int ooooo = wow.top().second;
		wow.pop();
		for (int q = 0;q < s[ooooo].size();++q) {
			if (dp[s[ooooo][q]] == 0 || dp[s[ooooo][q]] > faaa + 1) {
				dp[s[ooooo][q]] = faaa + 1;
				wow.push(make_pair(faaa+1,s[ooooo][q]));
			}
		}
	}
	cout << "0";
	for (int i = 2;i <= n;++i) {
		cout << " " << dp[i] ;
	}
}