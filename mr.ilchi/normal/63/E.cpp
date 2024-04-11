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
#include <cstring>
#include <algorithm>

using namespace std;

char dp[(1<<19) + 5];
int pw[50];
int code[10][10];

struct node{
	int x,y;

	node (int _x=-1, int _y=-1) : x(_x), y(_y) {}

}decode[50];
/********************************/
inline char memo(int v){
	if (dp[v]!=0)
		return dp[v];


	bool mat[8][8];
	for (int i=1;i<=6;i ++)
		memset (mat[i], false, sizeof mat[i]);

	int tmp=v;
	for (int i=0;i<=18;i++){
		mat[decode[i].x][decode[i].y]= tmp&1;
		tmp= (tmp>>1);
	}
	for (int i=1;i<=5;i ++){
		for (int j=1;j<=5;j ++){
			int tmp=v, jj=j;
			
			while (mat[i][jj]){
				tmp-= pw[code[i][jj]];
				if (memo(tmp)==2)
					return dp[v]=1;
				jj++;
			}
		}
	}
	
	for (int i=1;i<=5;i ++){
		for (int j=1;j<=5;j ++){
			int ii=i, jj=j, tmp= v;

			while (mat[ii][jj]){
				tmp-= pw[code[ii][jj]];
				if (memo(tmp)==2){
					return dp[v]=1;
				}	
				ii++;
			}

		}
	}

	for (int i=1;i<=5;i ++)
		for (int j=1;j<=5;j ++){
			int ii=i, jj=j, tmp=v;
			
			while (mat[ii][jj]){
				tmp-= pw[code[ii][jj]];
				if (memo(tmp)==2){
					return (dp[v]=1);
				}
				ii++; jj++;
			}
		}

	return (dp[v]=2);
}
/********************************/
inline void init(){
	for (int i=1;i<=5;i ++)
		memset (code[i], -1, sizeof code[i]);

	code[1][1]=18; code[1][2]= 17; code[1][3]=16;
	code[2][1]=15; code[2][2]= 14; code[2][3]=13; code[2][4]= 12;
	code[3][1]=11; code[3][2]= 10; code[3][3]= 9; code[3][4]=  8; code[3][5]= 7;
	code[4][2]= 6; code[4][3]=  5; code[4][4]= 4; code[4][5]=  3;
	code[5][3]= 2; code[5][4]=  1; code[5][5]= 0;

	dp[0]=2;
	int poi=18;
	for (int i=1;i<=5;i ++)
		for (int j=1;j<=5;j ++) if (code[i][j]!=-1)
			decode[poi--]= node(i,j);

	for (int i=0;i<=20;i++)
		pw[i]= (1<<i);
}
/********************************/
int main(){
	int n=0;
	for (int i=1;i<=19;i ++){
		char ch;
		cin >> ch;
		n= (n<<1) + (ch=='O');
	}
	
	init();
	cout << ((memo(n)==1) ? "Karlsson\n" : "Lillebror\n");
	
	return 0;
}