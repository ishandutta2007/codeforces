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
llint n, k;
string s;
llint a[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		
		for(int i = 0; i < k; i++) a[i] = -1;
		bool flag = true;
		for(int i = 0; i < s.size(); i++){
			if(a[i%k] == -1){
				if(s[i] != '?') a[i%k] = s[i]%2;
			}
			else{
				if(s[i] != '?' && s[i]%2 != a[i%k]){
					flag = false;
					break;
				}
			}
		}
		if(!flag){
			cout << "NO" << endl;
			continue;
		}
		
		llint cnt0 = 0, cnt1 = 0;
		for(int i = 0; i < k; i++){
			if(a[i] == 0) cnt0++;
			if(a[i] == 1) cnt1++;
		}
		llint rem = k - (cnt0+cnt1);
		
		if(cnt0 <= k/2 && k/2 <= cnt0+rem) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	return 0;
}