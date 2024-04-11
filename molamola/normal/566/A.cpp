#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int n;
int Trie[800080][26], len;
int ans;
vector <int> chk[800080];
int down[800080][2];	//1 -> 0, -1 -> 1
char ch[800080];
vector <int> v[800080][2];
int xy[200010];

void dfs(int x){
	for (int i = 0; i<(int)chk[x].size(); i++){
		if (chk[x][i] >= 1)down[x][0]++;
		else down[x][1]++;
	}
	for (int i = 0; i<26; i++){
		if (Trie[x][i]){
			int d = Trie[x][i];
			dfs(d);
			down[x][0] += down[d][0];
			down[x][1] += down[d][1];
			for (int i = 0; i<(int)v[d][0].size(); i++)v[x][0].push_back(v[d][0][i]);
			for (int i = 0; i<(int)v[d][1].size(); i++)v[x][1].push_back(v[d][1][i]);
		}
	}
	if (x != 0)ans += min(down[x][0], down[x][1]);
	while (!v[x][0].empty() && !v[x][1].empty()){
		xy[v[x][0].back()] = v[x][1].back();
		v[x][1].pop_back(), v[x][0].pop_back();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("566A.in", "r", stdin);
	freopen("566A.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n + n; i++){
		scanf("%s", ch);
		int now = 0;
		for (int j = 0; ch[j]; j++){
			if (Trie[now][ch[j] - 'a'] == 0)Trie[now][ch[j] - 'a'] = ++len;
			now = Trie[now][ch[j] - 'a'];
		}
		if (i < n)chk[now].push_back(i + 1);
		else chk[now].push_back(-(i - n + 1));
		if (i < n)v[now][0].push_back(i + 1);
		else v[now][1].push_back(i - n + 1);
	}
	dfs(0);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)printf("%d %d\n", i, xy[i]);
	return 0;
}