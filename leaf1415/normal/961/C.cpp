#include <iostream>

using namespace std;

int n;
int board[4][105][105];
int cost[4][2];

int main(void)
{
	cin >> n;
	for(int k = 0; k < 4; k++){
		char c;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> c;
				board[k][i][j] = c - '0';
			}
		}
	}
	
	for(int k = 0; k < 4; k++){
		for(int c = 0; c < 2; c++){
			int sum = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if((c+i+j)%2 != board[k][i][j]) sum++;
				}
			}
			cost[k][c] = sum;
		}
	}
	
	int ans = 100000000;
	ans = min(ans, cost[0][0] + cost[1][0] + cost[2][1] + cost[3][1]);
	ans = min(ans, cost[0][0] + cost[1][1] + cost[2][0] + cost[3][1]);
	ans = min(ans, cost[0][0] + cost[1][1] + cost[2][1] + cost[3][0]);
	ans = min(ans, cost[0][1] + cost[1][0] + cost[2][0] + cost[3][1]);
	ans = min(ans, cost[0][1] + cost[1][0] + cost[2][1] + cost[3][0]);
	ans = min(ans, cost[0][1] + cost[1][1] + cost[2][0] + cost[3][0]);
	cout << ans << endl;
	
	return 0;
}