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

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		cin >> s;
		sort(s.begin(), s.end());
		
		if(k == 1){
			cout << s << endl;
			continue;
		}
		if(s[0] == s[n-1]){
			llint x = (n+k-1)/k;
			for(int i = 0; i < x; i++) cout << s[0]; cout << endl;
			continue;
		}
		
		set<char> S;
		for(int i = 0; i < s.size(); i++) S.insert(s[i]);
		if((int)S.size() == 2){
			llint cnt = 0;
			for(int i = 0; i < s.size(); i++) if(s[i] == *S.begin()) cnt++;
			if(cnt == k){
				cout << s[0];
				llint x = (n+k-1)/k-1;
				for(int i = 0; i < x; i++) cout << s[n-1]; cout << endl;
				continue;
			}
		}
		
		if(s[0] == s[k-1]){
			cout << s[0] + s.substr(k) << endl;
			continue;
		}
		
		cout << s[k-1] << endl;
	}
	
	return 0;
}