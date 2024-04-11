#include <bits/stdc++.h>
using namespace std;

int dp[270][270][270];

string s;

const int INF = 100100;

int nxt[110000][26];

int len[3];

string rel[3];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	cin >> s;
	for(int i = 0; i < 260; i++) for(int j = 0; j < 260; j++) for(int k = 0; k < 260; k++){
		dp[i][j][k] = INF;
	}
	dp[0][0][0] = 0;
	for(int c = 0; c < 26; c++){
		nxt[INF][c] = INF;
	}
	for(int v = INF-1; v >= 0; v--){
		for(int c = 0; c < 26; c++){
			nxt[v][c] = nxt[v+1][c];
			if(v < s.size() && s[v] - 'a' == c){
				nxt[v][c] = v;
			}
		}
	}
	for(int _ = 0; _ < q; _++){
		char op;
		cin >> op;
		int idx;
		cin >> idx; idx--;
		if(op == '+'){
			char c;
			cin >> c;
			// add 
			len[idx]++;
			int sz = len[idx];
			rel[idx] += c;
			for(int i = 0; i < 260; i++){
				for(int j = 0; j < 260; j++){
					int x = sz, y = i, z = j;
					if(idx == 1) swap(x,y);
					if(idx == 2) swap(x,z);
					assert(dp[x][y][z] == INF);
					int v = INF;
					if(x > len[0] || y > len[1] || z > len[2]) continue;
					if(x){
						v = min(v, nxt[dp[x-1][y][z]][rel[0][x-1]-'a'] + 1);
					}
					if(y){
						v = min(v, nxt[dp[x][y-1][z]][rel[1][y-1]-'a'] + 1);
					}
					if(z){
						v = min(v, nxt[dp[x][y][z-1]][rel[2][z-1]-'a'] + 1);
					}
					dp[x][y][z] = v;
				}
			}
		} else if(op == '-'){
			int sz = len[idx];
			for(int i = 0; i < 260; i++){
				for(int j = 0; j < 260; j++){
					if(idx == 0) dp[sz][i][j] = INF;
					if(idx == 1) dp[i][sz][j] = INF;
					if(idx == 2) dp[i][j][sz] = INF;
				}
			}
			len[idx]--;
			rel[idx].pop_back();
		}
		if(dp[len[0]][len[1]][len[2]] < INF){
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}