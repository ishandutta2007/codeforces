#include <iostream>
#include <string>
#define inf 1e9

using namespace std;

string c;
string s, t;

int nx[55][26], nx2[55][26];
int dp[1005][55][55];

void make(string s, int nx[55][26])
{
	int n = s.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			string t = s.substr(0, i) + (char)('a'+j);
			while(s.size() == t.size() || s.substr(0, t.size()) != t) t = t.substr(1);
			nx[i][j] = t.size();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c;
	cin >> s >> t;
	make(s, nx), make(t, nx2);
	
	/*for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < 26; j++) cout << nx[i][j] << " "; cout << endl;
	}*/
	
	int C = c.size(), S = s.size(), T = t.size();
	for(int i = 0; i <= C; i++){
		for(int j = 0; j < S; j++){
			for(int k = 0; k < T; k++){
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	
	c = "#" + c;
	for(int i = 0; i < C; i++){
		for(int j = 0; j < S; j++){
			for(int k = 0; k < T; k++){
				for(int l = 0; l < 26; l++){
					if(c[i+1] != '*' && c[i+1] != l + 'a') continue;
					int nj = nx[j][l], nk = nx2[k][l];
					int cost = 0;
					if(j == S-1 && s[S-1] == l + 'a') cost++;
					if(k == T-1 && t[T-1] == l + 'a') cost--;
					dp[i+1][nj][nk] = max(dp[i+1][nj][nk], dp[i][j][k] + cost);
				}
			}
		}
	}
	
	int ans = -inf;
	for(int j = 0; j < S; j++){
		for(int k = 0; k < T; k++){
			ans = max(ans, dp[C][j][k]);
		}
	}
	cout << ans << endl;
	
	return 0;
}