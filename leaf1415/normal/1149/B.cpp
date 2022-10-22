#include <iostream>
#include <string>

using namespace std;

int n, Q;
string s;
string a, b, c;
int dp[255][255][255];
int nx[100005][26];

int main(void)
{
	cin >> n >> Q;
	cin >> s;
	s = "#" + s;
	
	for(int i = 0; i < 26; i++) nx[s.size()][i] = s.size();
	for(int i = s.size()-1; i >= 0; i--){
		for(int j = 0; j < 26; j++) nx[i][j] = nx[i+1][j];
		if(i+1 < s.size()) nx[i][s[i+1]-'a'] = i+1;
	}
	
	for(int i = 0; i <= 250; i++){
		for(int j = 0; j <= 250; j++){
			for(int k = 0; k <= 250; k++){
				dp[i][j][k] = s.size();
			}
		}
	}
	dp[0][0][0] = 0;
	
	char t, ch; int id;
	for(int q = 0; q < Q; q++){
		cin >> t;
		if(t == '-'){
			cin >> id;
			if(id == 1) a.erase(a.end()-1);
			if(id == 2) b.erase(b.end()-1);
			if(id == 3) c.erase(c.end()-1);
		}
		else{
			cin >> id >> ch;
			int A = a.size(), B = b.size(), C = c.size();
			if(id == 1){
				a += ch, A++;
				for(int i = A; i <= A; i++){
					for(int j = 0; j <= B; j++){
						for(int k = 0; k <= C; k++){
							dp[i][j][k] = s.size();
							if(i > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i-1][j][k]][a[i-1]-'a']);
							if(j > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i][j-1][k]][b[j-1]-'a']);
							if(k > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i][j][k-1]][c[k-1]-'a']);
						}
					}
				}
			}
			if(id == 2){
				b += ch, B++;
				for(int i = 0; i <= A; i++){
					for(int j = B; j <= B; j++){
						for(int k = 0; k <= C; k++){
							dp[i][j][k] = s.size();
							if(i > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i-1][j][k]][a[i-1]-'a']);
							if(j > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i][j-1][k]][b[j-1]-'a']);
							if(k > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i][j][k-1]][c[k-1]-'a']);
						}
					}
				}
			}
			if(id == 3){
				c += ch, C++;
				for(int i = 0; i <= A; i++){
					for(int j = 0; j <= B; j++){
						for(int k = C; k <= C; k++){
							dp[i][j][k] = s.size();
							if(i > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i-1][j][k]][a[i-1]-'a']);
							if(j > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i][j-1][k]][b[j-1]-'a']);
							if(k > 0) dp[i][j][k] = min(dp[i][j][k], nx[dp[i][j][k-1]][c[k-1]-'a']);
						}
					}
				}
			}
		}
		if(dp[a.size()][b.size()][c.size()] < s.size()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}