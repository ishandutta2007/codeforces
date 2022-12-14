#include <cstdio>
#include <iostream>
#define MAX 2005
using namespace std;
typedef long long int ll;

int chessBoard[MAX][MAX], n;
ll mainD_[MAX << 1], *mainD, subD[MAX << 1];

int main(){
	int i, j, ansX[3], ansY[3];
	ll ans, temp = -1;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			scanf("%d", &chessBoard[i][j]);
	mainD = mainD_ + n;
	for(i = 2; i <= n << 1; ++ i)
		for(j = 1; j <= n; ++ j)
			if((i - j) >= 1 && (i - j) <= n)
				subD[i] += chessBoard[j][i - j];
	for(i = 1 - n; i <= n - 1; ++ i)
		for(j = 1; j <= n; ++ j)
			if((j - i) >= 1 && (j - i) <= n)
				mainD[i] += chessBoard[j][j - i];
	for(i = 1; i <= n; ++ i)
		for(j = (i & 1) ? 1 : 2; j <= n; j += 2)
			if(temp < mainD[i - j] + subD[i + j] - chessBoard[i][j]){
				temp = mainD[i - j] + subD[i + j] - chessBoard[i][j];
				ansX[1] = i;
				ansY[1] = j;
			}
	ans = temp;
	temp = -1;
	for(i = 1; i <= n; ++ i)
		for(j = (i & 1) ? 2 : 1; j <= n; j += 2)
			if(temp < mainD[i - j] + subD[i + j] - chessBoard[i][j]){
				temp = mainD[i - j] + subD[i + j] - chessBoard[i][j];
				ansX[2] = i;
				ansY[2] = j;
			}
	cout << ans + temp << endl;
	printf("%d %d %d %d\n", ansX[1], ansY[1], ansX[2], ansY[2]);
	return 0;
}