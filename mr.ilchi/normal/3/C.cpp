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
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXL= 10;

bool Draw= true;
bool mark[MAXL];
int mat[MAXL][MAXL];
int n= 3;
int cnt[MAXL];

inline void check (){
	for (int i= 1;i<= n;i ++)
		for (int j= 1;j<= n;j ++)
			cnt[mat[i][j]] ++;
	
	if ((cnt[0] < cnt[1]) || ((cnt[0]-1) > cnt[1])){
		puts ("illegal");
		exit (0);
	}
	for (int i= 1;i<= n;i ++){
		if (mat[i][1]== mat[i][2] && mat[i][2]== mat[i][3])
			mark[mat[i][1]]= true;
		if (mat[1][i]== mat[2][i] && mat[2][i]== mat[3][i])
			mark[mat[1][i]]= true;
	}
	if (mat[1][1]== mat[2][2] && mat[2][2]== mat[3][3])
		mark[mat[1][1]]= true;
	if (mat[1][3]== mat[2][2] && mat[2][2]== mat[3][1])
		mark[mat[1][3]]= true;

	if (mark[0] && mark[1]){
		puts ("illegal");
		exit (0);
	}
	if ((mark[0] && cnt[0]== cnt[1]) || (mark[1] && cnt[0]!= cnt[1])){
		puts ("illegal");	
		exit (0);
	}
	if (mark[0] || mark[1]){
		(mark[0]) ? puts ("the first player won") : puts ("the second player won");
		exit (0);
	}
}
/********************************
inline void draw (int type){
	if (cnt[0]== 5){
		for (int i= 1;i<= n;i ++){
			if (mat[i][1]== mat[i][2] && mat[i][2]== mat[i][3])
				Draw= false;
			if (mat[1][i]== mat[2][i] && mat[2][i]== mat[3][i])
				Draw= false;
		}	
		if (mat[1][1]== mat[2][2] && mat[2][2]== mat[3][3])
			Draw= false;
		if (mat[1][3]== mat[2][2] && mat[2][2]== mat[3][1])
			Draw= false;
		return;
	}
	for (int i= 1;i<= n;i ++)
		for (int j= 1;j<= n;j ++)
			if (mat[i][j]== 2){
				mat[i][j]= type;
				cnt[type] ++;
				draw (1-type);
				cnt[type] --;
				mat[i][j]= 2;
			}
}
/********************************/
int main (){
	for (int i= 1;i<= n;i ++)
		for (int j= 1;j<= n;j ++){
			char ch;
			cin >> ch;
			mat[i][j]= (ch== 'X') ? 0 : 
			((ch== '0') ? 1 : 2);
		}

	check ();
	if (cnt[0]!= 5)
		(cnt[0] > cnt[1]) ? puts ("second") : puts ("first");
	else
		puts ("draw");

	return 0;
}