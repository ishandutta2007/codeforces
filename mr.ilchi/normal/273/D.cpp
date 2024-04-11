/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

#define addto(X,Y) ((X)=((X)+(Y))%mod)
#define subto(X,Y) ((X)=((X)-(Y)+mod)%mod)

using namespace std;

const int MAXN= 150+5;
const int mod = 1000000007;

int n,m;
int dp[MAXN][MAXN][2][2],test[MAXN][MAXN][2][2];
int sumL[MAXN][MAXN],sumR[MAXN][MAXN],sumLR[MAXN][MAXN];

int main(){
	cin >> n >> m;	
	int ans = 0;
	for (int row=0; row<n; row++){
		memset(test,0,sizeof test);
		for (int i=0; i<=m; i++)
			for (int j=0; j<i; j++)
				test[i][j][0][0] = test[i][j][0][1] = test[i][j][1][0] = test[i][j][1][1] = 1;
		if (row == 0){
			for (int i=0; i<m; i++)
				for (int j=i; j<m; j++)
					test[i][j][0][0] = test[i][j][0][1] = test[i][j][1][0] = test[i][j][1][1] = 1;
		}else{
			//[0][0]
			for (int len=1; len<=m; len++){
				for (int i=0,j=len-1; j<m; i++,j++){
					if (i!=j){ 
						addto(test[i][j][0][0], test[i][j-1][0][0]); 
						addto(test[i][j][0][0], test[i+1][j][0][0]);
						subto(test[i][j][0][0], test[i+1][j-1][0][0]);
					}else
						addto(test[i][j][0][0], 1);
					addto(test[i][j][0][0], dp[i][j][0][0]);
				}
			}
			//[1][0]
			for (int len=1; len<=m; len++){
				for (int i=0,j=len-1; j<m; i++, j++){
					if (i == 0){
						addto(test[i][j][1][0], test[i][j][0][0]);
					}else{
						addto(test[i][j][1][0], test[i][j-1][1][0]);
						addto(test[i][j][1][0], test[i+1][j][0][0]);
						subto(test[i][j][1][0], test[i+1][j-1][0][0]);
						addto(test[i][j][1][0], sumR[i][j]);
					}
				}
			}
			//[0][1]
			for (int len=1; len<=m; len++){
				for (int i=0,j=len-1; j<m; i++, j++){
					if (j==m-1){
						addto(test[i][j][0][1], test[i][j][0][0]);
					}else{
						if (i!=j){
							addto(test[i][j][0][1], test[i+1][j][0][1]);
							addto(test[i][j][0][1], test[i][j-1][0][0]);
							subto(test[i][j][0][1], test[i+1][j-1][0][0]);
						}else
							addto(test[i][j][0][1], 1);
						addto(test[i][j][0][1], sumL[i][j]);
					}
				}
			}
			//[1][1]
			for (int len=1; len<=m; len++){
				for (int i=0,j=len-1; j<m; i++, j++){
					if (i!=j){
						addto(test[i][j][1][1], test[i+1][j][0][1]);
						addto(test[i][j][1][1], test[i][j-1][1][0]);
						subto(test[i][j][1][1], test[i+1][j-1][0][0]);
					}else				
						addto(test[i][j][1][1], 1);
					addto(test[i][j][1][1], sumLR[i][j]);
				}
			}
		}
		memcpy(dp, test, sizeof dp);
		memset(sumL, 0, sizeof sumL);
		memset(sumR, 0, sizeof sumR);
		memset(sumLR,0, sizeof sumLR);
		for (int i=0; i<m; i++){
			for (int j=m-1; j>=i; j--){
				addto(sumL[i][j], sumL[i][j+1]);
				addto(sumL[i][j], dp[i][j][0][1]);
			}
		}
		for (int j=0; j<m; j++){
			for (int i=0; i<=j; i++){
				if (i!=0)
					addto(sumR[i][j], sumR[i-1][j]);
				addto(sumR[i][j], dp[i][j][1][0]);
			}
		}
		for (int i=0; i<m; i++)
			for (int j=m-1; j>=i; j--){
				if (i!=0) addto(sumLR[i][j], sumLR[i-1][j]);
				if (j!=m-1) addto(sumLR[i][j], sumLR[i][j+1]);
				if (i!=0 && j!=m-1) subto(sumLR[i][j], sumLR[i-1][j+1]);
				addto(sumLR[i][j], dp[i][j][1][1]);
			}
		for (int i=0; i<m; i++)
			for (int j=i; j<m; j++)
				addto(ans, dp[i][j][1][1]);
	}
	cout << ans << endl;
	return 0;
}