#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

UL N, M;
string S[10];
string dp[11][1 << 10];
UL D[26];

int main() {
	UL T; scanf("%u", &T);
	while (T--) {
		rep(i, 11) rep(j, 1 << 10) dp[i][j] = "";
		static const char alf[] = "abcdefghijklmnopqrstuvwxyz";
		scanf("%u%u", &N, &M);
		rep(i, N) cin >> S[i];
		dp[0][0] = string(M, '#');
		rep(i, M) {
			rep(j, 26) {
				D[j] = 0;
				rep(n, N) if (S[n][i] != alf[j]) D[j] |= (1 << n);
	    	}
			rep(p, 1 << N) {
				if (dp[i][p].empty()) continue;
				rep(c, 26) {
					if (D[c] & p) continue;
					dp[i + 1][p | D[c]] = dp[i][p];
					dp[i + 1][p | D[c]][i] = alf[c];
				}
			}
		}
		string ans = "-1";
		rep(i, 1 << N) if (dp[M][i].size()) { ans = dp[M][i]; break; }
		cout << ans << endl;
	}
    return 0;
}