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

llint T;
llint n;
string s;
int sum[26][200005];

int calc(int l, int r, int c)
{
	if(l == r){
		if(s[l] == c+'a') return 0;
		else return 1;
	}
	int m = (l+r)/2, len = r-l+1;
	int ret = calc(l, m, c+1) + len/2-(sum[c][r]-sum[c][m]);
	int ret2 = calc(m+1, r, c+1) + len/2-(sum[c][m]-sum[c][l-1]);
	return min(ret, ret2);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		s = "#" + s;
		for(int i = 0; i < 26; i++){
			int x = 0;
			for(int j = 1; j <= n; j++){
				if(s[j] == 'a'+i) x++;
				sum[i][j] = x;
			}
		}
		cout << calc(1, n, 0) << endl;
	}
	
	return 0;
}