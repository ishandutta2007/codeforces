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
llint cnt[26];

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 0; i < n; i++) cnt[s[i]-'a']++;
		sort(cnt, cnt+26);
		
		llint ans = 1;
		for(int i = n; i >= 2; i--){
			llint g = gcd(i, k), sum = 0;
			for(int j = 0; j < 26; j++) sum += cnt[j] / (i/g);
			if(sum >= g){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}