#include <iostream>
#include <stdio.h>
#define llint long long 

using namespace std;

llint T;

string tostr(llint x)
{
	char buf[55];
	sprintf(buf, "%lld", x);
	return buf;
}

llint dp[25][4][2];

llint calc(string s)
{
	llint n = s.size();
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k < 2; k++){
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k < 2; k++){
				for(int l = 0; l <= 9; l++){
					if(i == 0 && l == 0) continue;
					if(k == 0 && s[i]-'0' < l) continue;
					if(j == 3 && l != 0) continue;
					llint nextk = k; if(s[i]-'0' > l) nextk = 1;
					if(l > 0) dp[i+1][j+1][nextk] += dp[i][j][k];
					else dp[i+1][j][nextk] += dp[i][j][k];
				}
			}
		}
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 3; j++){
			for(int k = 0; k < 2; k++){
				cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	
	llint ret = 0;
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j < 2; j++){
			ret += dp[n][i][j];
		}
	}
	return ret;
}

llint calc2(llint x)
{
	if(x <= 3){
		llint a[] = {0, 9, 90, 900};
		return a[x];
	}
	
	llint ret = 9;
	ret += 9 * (x-1) * 9;
	ret += 9 * (x-1)*(x-2)/2 * 81;
	return ret;
}

int main(void)
{
	cin >> T;
	
	llint L, R;
	for(int t = 0; t < T; t++){
		cin >> L >> R;
		L--;
		
		string ls, rs;
		ls = tostr(L), rs = tostr(R);
		
		llint l = ls.size(), r = rs.size();
		llint ans = 0;
		for(int i = l+1; i < r; i++) ans += calc2(i);
		
		int cnt = 0;
		for(int i = 0; i < ls.size(); i++){
			if(ls[i] != '0'){
				if(cnt < 3) cnt++;
				else ls[i] = '0';
			}
		}
		cnt = 0;
		for(int i = 0; i < rs.size(); i++){
			if(rs[i] != '0'){
				if(cnt < 3) cnt++;
				else rs[i] = '0';
			}
		}
		
		if(l != r){
			ans += calc(rs);
			ans += calc2(l) - calc(ls);
		}
		else{
			ans = calc(rs) - calc(ls);
		}
		cout << ans << endl;
	}
	
	return 0;
}