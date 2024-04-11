#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair
#define Hash pair<int, int>
typedef long long i64;
typedef unsigned long long u64;
int n;
vector<int> ans;
void dfs(vector<int> num, vector<int> p2, int now) {
	if(num[0] == 0) num.erase(num.begin());
	if(sz(num) == 0) {
		if(ans.empty() || sz(ans) > sz(p2)) {
			ans = p2;
		}
		return;
	}
	int cnt = 0;
	for(int x : num) cnt += x & 1;
	if(cnt == 0) {
		for(int &x : num) x >>= 1;
		dfs(num, p2, now * 2);
		return;
	}
	p2.push_back(now);
	vector<int> tmp = num;
	for(int &x : tmp) {
		if(x & 1) x--;
		x = x >> 1;
	}
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	if(tmp != num) dfs(tmp, p2, now * 2);
	p2.back() = - p2.back();
	tmp = num;
	for(int &x : tmp) {
		if(x & 1) x++;
		x = x >> 1;
	}
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	if(tmp != num) dfs(tmp, p2, now * 2);
	return;
}

int main() {
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	dfs(a, vector<int>(), 1);
	printf("%d\n", sz(ans));
	for(int x : ans) printf("%d ", x);
	printf("\n");
    return 0;
}