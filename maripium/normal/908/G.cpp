#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 705;
const int mod = 1e9 + 7;

string s;
int dp[N][N][11][2];
void add(int &x,int y) {
	x += y; while(x >= mod) x -= mod; while(x < 0) x += mod;
}

signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> s;
	while(s.size() < 700) s = '0' + s;
	
	for(int digit = 0;digit < 10;++digit)dp[0][0][digit][0] = 1;
	for(int pos = 1;pos <= 700;++pos) {		
		for(int cnt = 0;cnt <= pos;++cnt) {		
			for(int digit = 0;digit < 10;++digit) {		
				for(int smaller = 0;smaller < 2;++smaller) {
				if(dp[pos - 1][cnt][digit][smaller] == 0) continue;
				int mx = 9;
				if(smaller == 0) mx = s[pos - 1] - '0';
				for(int nxt = 0;nxt <= mx;++nxt) {
					int ncnt = cnt + (nxt >= digit);
					int nsmaller = smaller;
					if(nxt < mx) nsmaller = 1;
					add(dp[pos][ncnt][digit][nsmaller],dp[pos - 1][cnt][digit][smaller]);
					}
				}
			}
		}
	}
	
	int ans = 0;
	for(int digit = 0;digit < 10;++digit) {
		int cur = digit;
		for(int cnt = 1;cnt <= 700;++cnt) {
			int res;
			add(res,dp[700][cnt][digit][0]);
			add(res,dp[700][cnt][digit][1]);
			add(res,-dp[700][cnt][digit + 1][0]);
			add(res,-dp[700][cnt][digit + 1][1]);
			res = (res * cur) % mod;
			add(ans,res);
			cur = (cur * 10 + digit) % mod; 
		}
	}
	
	cout << ans << endl;
}