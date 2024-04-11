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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

string s;
vector<pair<llint, string> > avec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	
	string ans; char c = 0, d = 0; int cnt = 0;
	for(int i = (int)s.size()-1; i >= 0; i--){
		ans += s[i];
		if(i == (int)s.size()-1) cnt++;
		else{
			if(s[i] == s[i+1]){
				cnt++;
				if(cnt % 2 == 0){
					if(s[i] > c) ans.pop_back(), ans.pop_back();
					if(s[i] == c && s[i] > d) ans.pop_back(), ans.pop_back();
				}
			}
			else{
				if(cnt % 2 || s[i+1] < c){
					if(s[i+1] != c) d = c;
					c = s[i+1];
				}
				cnt = 1;
			}
		}
		
		string tmp;
		if(ans.size() <= 10){
			for(int i = 0; i < ans.size(); i++) tmp += ans[(int)ans.size()-1-i];
		}
		else{
			for(int i = 0; i < 5; i++) tmp += ans[(int)ans.size()-1-i];
			tmp += "...";
			for(int i = (int)ans.size()-2; i < ans.size(); i++) tmp += ans[(int)ans.size()-1-i];
		}
		avec.push_back(make_pair((int)ans.size(), tmp));
	}
	
	reverse(avec.begin(), avec.end());
	for(int i = 0; i < avec.size(); i++){
		cout << avec[i].first << " " << avec[i].second << endl;
	}
	
	return 0;
}