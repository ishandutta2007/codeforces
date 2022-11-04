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
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXN= 1000+5;
const int INF = 1000*1000;

int dp[MAXN][MAXN];
string s, M;

struct node{
	int x, y;
	
	node (int _x= -1, int _y= -1) : x(_x), y(_y) {}

}par[MAXN][MAXN];
/**********************************************/
inline void print (int i, int j){
	if (i== j && i== 0)
		return;
	
	int ii= par[i][j].x, jj= par[i][j].y;
	if (ii== (i-1) && jj== (j-1)){
		if (s[i-1]!= M[j-1])
			printf ("REPLACE %d %c\n", i, M[j-1]);
	}
	else if (ii== i)
		printf ("INSERT %d %c\n", ii+1, M[j-1]);
	else
		printf ("DELETE %d \n", i);

	print (ii, jj);
}
/*************************************/
int main (){
	cin >> s >> M;
	for (int i= 1;i<= (int)M.size ();i ++){
		dp [0][i]= i;
		par[0][i]= node (0, i-1);
	}
	for (int i= 1;i<= (int)s.size ();i ++){
		dp [i][0]= i;
		par[i][0]= node (i-1, 0);
		for (int j= 1;j<= (int)M.size ();j ++){
			dp[i][j]= INF;
			if (s[i-1]== M[j-1]){
				dp [i][j]= dp[i-1][j-1];
				par[i][j]= node (i-1, j-1);
			}
			
			if (dp[i-1][j]+1 < dp[i][j]){
				dp [i][j]= dp[i-1][j]+1;
				par[i][j]= node (i-1, j);
			}
			if (dp[i-1][j-1]+1 < dp[i][j]){
				dp [i][j]= dp[i-1][j-1]+1;
				par[i][j]= node (i-1, j-1); 
			}
			if (dp [i][j-1]+1 < dp[i][j]){
				dp [i][j]= dp[i][j-1]+1;
				par[i][j]= node (i, j-1); 
			}
		}
	}
	
	cout << dp[s.size()][M.size()] << endl;
	print ((int)s.size(), (int)M.size());

	return 0;
}