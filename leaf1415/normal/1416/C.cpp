#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> Q;

llint n;
llint a[300005];
llint b[35][2];

void calc(int p, vector<int> &vec)
{
	vector<int> nvec[2]; int cnt[2] = {0, 0};
	for(int i = 0; i < vec.size(); i++){
		int c = (a[vec[i]]>>p)&1;
		nvec[c].push_back(vec[i]);
		b[p][c] += cnt[1-c];
		cnt[c]++;
	}
	if(p > 0){
		if(nvec[0].size()) calc(p-1, nvec[0]);
		if(nvec[1].size()) calc(p-1, nvec[1]);
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	vector<int> vec;
	for(int i = 1; i <= n; i++) vec.push_back(i);
	calc(30, vec);
	
	llint ans = 0, ans_x = 0;
	for(int i = 0; i <= 30; i++){
		if(b[i][1] < b[i][0]) ans_x |= 1<<i;
		ans += min(b[i][0], b[i][1]);
	}
	cout << ans << " " << ans_x << endl;
	
	return 0;
}