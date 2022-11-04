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
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN= 500+5;

int len[2];
int dp[MAXN], par[MAXN];
int a[2][MAXN];

inline void setDyn (){
	for (int i= 1;i<= len[0];i ++){
		int cur= a[0][i], pmax= 0;
		for (int j= 1;j<= len[1];j ++){
			int tmp= a[1][j];
			if (cur==tmp){
				dp [j]= dp[pmax]+ 1;
				par[j]= pmax;
			}
			else if (tmp<cur && dp[pmax]<dp[j])
				pmax= j;
		}
	}
}
/************************************/
inline void print (int place){
	if (place== 0)
		return;
	print (par[place]);
	cout << a[1][place] << ' ';
}
/************************************/
int main (){
	for (int i= 0;i< 2;i ++){
		cin >> len[i];
		for (int j= 1;j<= len[i];j ++)
			cin >> a[i][j];
	}

	setDyn ();

	int pmax= 0;
	for (int i= 1;i<= len[1];i ++)
		if (dp[pmax] < dp[i])
			pmax= i;
	
	cout << dp[pmax] << endl;
	print (pmax);
	cout << endl;

	return 0;
}