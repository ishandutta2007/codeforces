#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp0[210][210];
int dp[210][210];
int main(){
	int n;
	LL l;
	cin >> n >> l;
	int zz[n];
	string s[n];
	for(int i = 0; i < n; i++) cin >> zz[i];
	for(int i = 0; i < n; i++) cin >> s[i];
	map<string,int> kk;
	map<int,string> bk;
	int d = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= s[i].size(); j++){
			if(kk.find(s[i].substr(0,j)) == kk.end()){
				kk[s[i].substr(0,j)] = d;
				bk[d] = s[i].substr(0,j);
				d++;
			}
		}
	}
	int gain[d][d];
	for(int i = 0; i < d; i++){
		for(int j = 0; j < d; j++){
			gain[i][j] = -100000000;
		}
	}
	for(int i = 0; i < d; i++){
		string pp = bk[i];
		for(char c = 'a'; c <= 'z'; c++){
			string st = pp + c;
			while(kk.find(st) == kk.end()){
				st = st.substr(1);
			}

			int j = kk[st];
			gain[i][j] = 0;
			for(int p = 0; p < n; p++){
				if(st.size() >= s[p].size()){
					if(st.substr(st.size() - s[p].size()) == s[p]){
						gain[i][j] += zz[p];
					}
				}
			}
		}
	}

	for(int k = 0; k < 210; k++){
		for(int a = 0; a < d; a++){
			dp0[a][k] = -100000000;
		}
	}
	dp0[0][0] = 0;
	for(int k = 0; k < 210; k++){
		for(int a = 0; a < d; a++){
			for(int b = 0; b < d; b++){
				if(k > 0){
					dp0[b][k] = max(dp0[b][k], dp0[a][k-1] + gain[a][b]);
				}
			}
		}
	}
	LL maxans = 0;
	for(int v = 0; v < d; v++){
		for(int k = 0; k < 210; k++){
			for(int a = 0; a < d; a++){
				dp[a][k] = -100000000;
			}
		}
		dp[v][0] = 0;
		for(int k = 0; k < 210; k++){
			for(int a = 0; a < d; a++){
				for(int b = 0; b < d; b++){
					if(k > 0){
						dp[b][k] = max(dp[b][k], dp[a][k-1] + gain[a][b]);
					}
				}
			}
		}
		int maxval[210];
		for(int k = 0; k < 210; k++){
			maxval[k] = 0;
			for(int a = 0; a < d; a++){
				maxval[k] = max(maxval[k],dp[a][k]);
			}
		}
		for(int pr = 0; pr < 420; pr++){
			LL a = -1000000000;
			for(int p = 0; p < 210; p++){
				int r = pr - p;
				if(r >= 210 || r < 0) continue;
				LL b = (LL)dp0[v][p] + (LL) maxval[r];
				a = max(a,b);
			}
			if((LL)(pr) > l) break;
			for(int q = 1; q < 210; q++){
				LL m = ((LL)l-(LL)pr)/((LL)q);
				if(dp[v][q] >= 0 || m == 0){
					maxans = max(maxans, a + (LL)m * (LL) dp[v][q]);	
				}
			}
		}
	}
	cout << maxans << endl;
}