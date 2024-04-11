#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string s;
	string p;
	cin >> s >> p;
	int n = s.size();
	int m = p.size();
	int next[n];
	int end[n];
	for(int i = 0; i < n; i++){
		int counter = 0;
		int j = i;
		while(1){
			if(j >= n) break;
			if(s[j] == p[0]){
				counter++;
				break;
			}
			j++;
		}
		next[i] = j;
 		j++;
		while(1){
			if(counter >= m){
				end[i] = j-1;
				break;
			}
			if(j >= n){
				next[i] = end[i] = n;
				break;
			}
			if(s[j] == p[counter]){
				counter++;
			}
			j++;
		}
		//cout << next[i] << " " << end[i] << endl;
	}
	//int dp[i][j] = min characters you need to remove to have j occurrences AT character 0 <= i <= n
	int dp[n+1][n+1];
	int mini[n+1][n+1];
	// mini[i][j] = min(dp[i][j], dp[i+1][j], ... dp[n][j])
	for(int i = 0; i <= n; i++){
	for(int j = 0; j <= n; j++){
		mini[i][j] = dp[i][j] = 10000;
	}
	}
	for(int i = 0; i <= n; i++){
		dp[n][0] = 0;
		mini[n][0] = 0;
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j <= n; j++){
			if(next[i] < n){
				dp[i][j] = min(dp[i][j], mini[end[i]+1][j-1]+end[i]-next[i]+1-m);
			}
			mini[i][j] = min(dp[i][j], mini[i+1][j]);
		}
	}
	//for(int j = 0; j <= n; j++) cout << mini[0][j] << endl;
	//mini[0][j] = min char need to remove to have j occurences, but the max you can remove is n-m*j
	//j works if mini[0][j] <= k <= n-m*j
	for(int i = 0; i <= n; i++){
		int first = 0;
		int last = n+1;
		int works = 0;
		while(first + 1 < last){
			int j = (first+last)/2;
			if(i < mini[0][j] || i > (n-m*j) ){
				last = j;
			} else {
				first = j;
			}
		}
		cout << first << " ";
	}
	cout << endl;

}