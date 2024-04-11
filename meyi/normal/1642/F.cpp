#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map<string, int> msi;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;

#ifdef LOCAL
#define debug(format, args...) \
printf(format, ##args)
#define dbg(args...) __f(args)
template <typename Arg1>
void __f(const Arg1& arg1){
	cout << arg1;
}
template <typename Arg1, typename... Args>
void __f(const Arg1& arg1, const Args&... args){
	cout << arg1;
	__f(args...);
}
#else
#define debug(format, args...)
#define dbg(...)
#endif

const int maxn = 1e5 + 5, T = 1000;

typedef bitset<maxn> bit;

int n, m, x, cnt;

struct Node{
	int a[5];
	int w;
	bool operator < (const Node& b) const {
		return w < b.w;
	}
};

int main(){
	#ifndef LOCAL
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#endif
	cin >> n >> m;
	vector<Node> node(n);
	map<int, int> convert;
	vector<bit*> flags(n * m + 9);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> x;
			if (!convert.count(x)){
				convert[x] = cnt++;
			}
			node[i].a[j] = convert[x];
		}
		cin >> node[i].w;
	}
	sort(node.begin(), node.end());
	vector<vi> vec(cnt + 1);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			vec[node[i].a[j]].push_back(i);
		}
	}
	for (auto x : convert){
		int value = x.second;
		if (vec[value].size() >= T){
			flags[value] = new bit();
			for (auto y : vec[value]){
				flags[value] -> set(y);
			}
		}
	}
	int ans, mmax;
	ans = mmax = 2e9 + 10;
	for (int i = 0; i < n; i++){
		bit temp;
		for (int j = 0; j < m; j++){
			if (vec[node[i].a[j]].size() >= T){
				temp |= *(flags[node[i].a[j]]);
			}
			else{
				for (auto x : vec[node[i].a[j]]){
					temp.set(x);
				}
			}
		}
		temp.flip();
		int pos = temp._Find_first();
		if (i < pos && pos < n){
			ans = min(ans, node[i].w + node[pos].w);
		}
	}
	if (ans == mmax){
		ans = -1;
	}
	cout << ans;
    return 0;
}