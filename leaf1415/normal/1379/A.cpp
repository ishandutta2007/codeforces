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

llint T;
llint n;
string s;
string S = "abacaba";

llint count(string s)
{
	llint ret = 0;
	for(int i = 0; i+6 < s.size(); i++){
		if(s.substr(i, 7) == S) ret++;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> s;
		
		for(int i = 0; i+6 < s.size(); i++){
			string t = s; bool flag = true;
			for(int j = 0; j < 7; j++){
				if(t[i+j] != '?' && t[i+j] != S[j]) flag = false;
				t[i+j] = S[j];
			}
			for(int j = 0; j < s.size(); j++) if(t[j] == '?') t[j] = 'z';
			if(flag && count(t) == 1){
				cout << "YES" << endl;
				cout << t << endl;
				goto end;
			}
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}