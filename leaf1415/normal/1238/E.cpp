#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define llint long long

using namespace std;

llint n, m;
string s;
llint a[25][25];
llint pop[1<<20];
llint dp[1<<20];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	cin >> s;
	
	llint all = 0;
	for(int i = 1; i < s.size(); i++){
		int x = s[i]-'a', y = s[i-1]-'a';
		if(x != y) a[x][y]++, a[y][x]++, all++;
	}
	
	/*for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	
	int N = 1<<m;
	for(int i = 1; i < N; i++) pop[i] = pop[i&(i-1)]+1;
	for(int i = 1; i < N; i++) dp[i] = 1e9;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < m; j++){
			if(i & (1<<j)) continue;
			llint sum = 0, sum2 = 0;
			for(int k = 0; k < m; k++){
				if(i & (1<<k)) sum += a[j][k];
				else sum2 += a[j][k];
			}
			//cout << i << " " << j << " " << (i|(1<<j)) << " " << sum << " " <<  sum*pop[i] - sum2*pop[i] << endl;
			dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i] + sum*pop[i] - sum2*pop[i]);
		}
	}
	//for(int i = 0; i < N; i++) cout << dp[i] << " "; cout << endl;
	cout << dp[N-1] << endl;
	
	return 0;
}