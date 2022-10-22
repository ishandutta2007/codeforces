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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint t;
int a[1000005], b[1000005], c[1000005];
int cnt[1000005];
set<int> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	rep(i, 1, t) cin >> a[i], cnt[a[i]]++;
	rep(i, 1, t){
		if(t % i == 0) S.insert(i);
	}
	
	if(cnt[0] != 1){
		cout << -1 << endl;
		return 0;
	}
	rep(i, 1, 1000000){
		if(cnt[i] > 4*i){
			cout << -1 << endl;
			return 0;
		}
	}
	
	int d;
	rep(i, 1, 1000000){
		if(cnt[i] != 4*i){
			d = i;
			break;
		}
	}
	int m = 0;
	rep(i, 1, t) m = max(m, a[i]);
	
	for(auto w : S){
		int h = t / w;
		if(w < d) continue;
		int x = w - d, y = m - x;
		
		rep(i, 0, 1000000) c[i] = 0;
		rep(i, 0, w-1){
			rep(j, 0, h-1){
				c[abs(x-i)+abs(y-j)]++;
			}
		}
		bool flag = true;
		rep(i, 0, 1000000) flag &= (c[i] == cnt[i]);
		if(flag){
			cout << h << " " << w << endl;
			cout << y+1 << " " << x+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}