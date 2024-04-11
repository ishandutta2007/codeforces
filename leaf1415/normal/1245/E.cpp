#include <iostream>
#include <string>
#include <stdio.h>
#define llint long long

using namespace std;

int a[10][10];
double dp[10][10][2];

bool getnext(int &x, int &y)
{
	if(x == 0 && y == 0) return false;
	if(y % 2){
		if(x < 9) x++;
		else y--;
	}
	else{
		if(x > 0) x--;
		else y--;
	}
	return true;
}

bool getprev(int &x, int &y)
{
	if(x == 0 && y == 9) return false;
	if(y % 2){
		if(x > 0) x--;
		else y++;
	}
	else{
		if(x < 9) x++;
		else y++;
	}
	return true;
}

int main(void)
{
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			cin >> a[x][y];
		}
	}
	
	int x = 0, y = 0;
	do{
		//cout << x << " " << y << endl;
		getprev(x, y);
		int cnt = 0, nx = x, ny = y;
		for(int i = 1; i <= 6; i++){
			if(getnext(nx, ny)){
				cnt++;
				dp[x][y][1] += dp[nx][ny][0];
			}
		}
		dp[x][y][1] /= cnt;
		dp[x][y][1] += 6.0 / cnt;
		
		dp[x][y][0] = dp[x][y][1];
		if(a[x][y]) dp[x][y][0] = min(dp[x][y][0], dp[x][y-a[x][y]][1]);
	}while(x != 0 || y != 9);
	
	printf("%.11f\n", dp[0][9][1]);
	
	return 0;
}