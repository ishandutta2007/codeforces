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

int n, k;
llint S[2005], T[10];
string s[2005];
string t[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
llint d[2005];
bool dp[2005][2005];

llint encode(string s)
{
	llint ret = 0;
	for(int i = 0; i < 7; i++){
		llint c = s[i]-'0';
		ret <<= 1;
		ret += c;
	}
	return ret;
}

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		S[i] = encode(s[i]);
		for(int j = 0; j < 7; j++){
			if(s[i][j] == '1') d[i]++;
		}
	}
	for(int i = 0; i < 10; i++) T[i] = encode(t[i]);
	
	
	dp[n+1][0] = true;
	for(int i = n+1; i >= 2; i--){
		for(int j = 0; j <= k; j++){
			if(!dp[i][j]) continue;
			for(int l = 0; l < 10; l++){
				if((S[i-1] & T[l]) != S[i-1]) continue;
				if(j+(c[l]-d[i-1]) <= k) dp[i-1][j+(c[l]-d[i-1])] = true;
			}
		}
	}
	
	string ans;
	for(int i = 1; i <= n; i++){
		//cout << k << endl;
		bool flag = false;
		for(int l = 9; l >= 0; l--){
			if((S[i] & T[l]) != S[i]) continue;
			if(k-(c[l]-d[i]) >= 0 && dp[i+1][k-(c[l]-d[i])]){
				ans += l+'0';
				flag = true;
				k -= (c[l]-d[i]);
				break;
			}
		}
		if(flag) continue;
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	
	return 0;
}