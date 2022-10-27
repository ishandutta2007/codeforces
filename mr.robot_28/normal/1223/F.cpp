#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int t, n;
int a[N];
int nxt[N];
int dp[N];
map<int, int> nxtX[N];


int main() {	
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for(int i = 0; i < n + 2; ++i){
			nxt[i] = -1;
			nxtX[i].clear();
			dp[i] = 0;
		}

		for(int i = n - 1; i >= 0; --i){
			if(nxtX[i + 1].count(a[i])){
				int pos = nxtX[i + 1][a[i]];
				assert(pos < n && a[pos] == a[i]);
				nxt[i] = pos;
				swap(nxtX[i], nxtX[pos + 1]);
				if(pos < n - 1)
					nxtX[i][a[pos + 1]] = pos + 1;
			}
			nxtX[i][a[i]] = i;
		}	

		long long res = 0;
		for(int i = n - 1; i >= 0; --i){
			if(nxt[i] == -1) continue;	
			dp[i] = 1 + dp[nxt[i] + 1];
			res += dp[i];
		}

		printf("%lld\n", res);
	}
	return 0;
}