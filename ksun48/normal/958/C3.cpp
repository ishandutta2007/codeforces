#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, k, p;
    cin >> n >> k >> p;
    if(n <= 15000){
		int last[k][p];
		int inf = 10000000;
		for(int i = 0; i<k; i++){
		    for(int j = 0; j<p; j++){
		        last[i][j] = inf;
		        last[i][j] = inf;
		    }
		}
		int zz;
		cin >> zz;
		last[0][zz%p] = 0;
		for(int z = 1; z<n; z++){
		    int x;
		    cin >> x;
		    int now[k][p];
		    for(int i = 0; i<k; i++){
		        for(int j = 0; j<p; j++){
		            now[i][j] = inf;
		        }
		    }
		    for(int i = 0; i<k; i++){
		        for(int j = 0; j<p; j++){
		            if(i+1<k){
		                now[i+1][x%p] = min(now[i+1][x%p],last[i][j]+j);
		            }
		            now[i][(j+x)%p] = min(now[i][(j+x)%p],last[i][j]);
		        }
		    }
		    for(int i = 0; i<k; i++){
		        for(int j = 0; j<p; j++){
		            last[i][j] = now[i][j];
		        }
		    }
		    
		}
		int ans = inf;
	    for(int j = 0; j<p; j++){
	        ans = min(ans,last[k-1][j]+j);
	    }
		cout << ans << endl;
		return 0;
	}
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> b(1,0);
	for(int i = 0; i < n; i++){
		b.push_back((b[i] + a[i]) % p);
	}
	int ans = b[n] % p;
	vector<int> dp(ans+1, 0);
	for(int i = 1; i <= n; i++){
		if(b[i] > ans) continue;
		dp[b[i]]++;
		for(int a = 1; a <= ans; a++){
			dp[a] = max(dp[a], dp[a-1]);
		}
	}
	if(dp[ans] >= k){
		cout << ans << endl;
	} else {
		cout << ans + p << endl;
	}
}