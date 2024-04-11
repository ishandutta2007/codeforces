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
#include <cstdlib>

using namespace std;

const int maxN= 100+5;

char ans[maxN][maxN];
int n,m,a,b,c,cur=0;
int mat[maxN][maxN];


inline void imp(){
	puts ("IMPOSSIBLE");
	exit(0);
}
/**************************************/
inline void zoj_zoj(int n, int m){
	b-= b&1; c-= c&1;
	if (4*a + 2*b + 2*c < m*n)
		imp();
	for (int i=1;i<=n;i+= 2)
		for (int j=1;j<=m;j+= 2){
			if (a > 0){
				mat[i][j]= mat[i][j+1]= mat[i+1][j]= mat[i+1][j+1]= ++cur;
				a --;
			}
			else if (b > 0){
				mat[i][j]= mat[i][j+1]= ++cur;
				mat[i+1][j]= mat[i+1][j+1]= ++cur;
				b-= 2;
			}
			else{
				mat[i][j]= mat[i+1][j]= ++cur;
				mat[i][j+1]= mat[i+1][j+1]= ++cur;
				c-= 2;
			}			
		}
}
/**********************************/
inline void fard_zoj(){
	if (b < m/2)
		imp();
	b-= m/2;
	for (int j=1;j<=m;j+= 2)
		mat[n][j]= mat[n][j+1]= ++cur;
	zoj_zoj (n-1, m);
}
/**********************************/
inline void zoj_fard(){
	if (c < n/2)
		imp();
	c-= n/2;
	for (int i=1;i<=n;i+= 2)
		mat[i][m]= mat[i+1][m]= ++cur;
	zoj_zoj (n,m-1);
}
/**********************************/
inline void print(){
	for (int i=1;i<=n;i ++){
		for (int j=1;j<=m;j ++){
		 	if (ans[i][j])
				continue;
			if (mat[i][j]==mat[i+1][j+1]){
				for (char z='a'; true; z++){
					if (ans[i][j-1]!=z && ans[i+1][j-1]!=z && ans[i-1][j]!=z && ans[i-1][j+1]!=z){
						ans[i][j]= ans[i][j+1]= ans[i+1][j]= ans[i+1][j+1]= z;
						break;
					}
				}			
			}
			else if (mat[i][j]== mat[i][j+1]){
				for (char z='a'; true; z ++){
					if (ans[i][j-1]!=z && ans[i-1][j]!=z && ans[i-1][j+1]!=z && ans[i][j+2]!=z){
						ans[i][j]= ans[i][j+1]= z;
						break;
					}
				}
			}
			else{
				for (char z='a'; true; z++){
					if (ans[i-1][j]!=z && ans[i][j-1]!=z && ans[i+1][j-1]!=z){
						ans[i][j]= ans[i+1][j]= z;
						break;
					}
				}	
			}
		}
	}

	for (int i=1;i<=n;i ++)
		puts (&ans[i][1]);
}
/**********************************/
int main(){
	scanf ("%d%d%d%d%d", &n, &m, &b, &c, &a);
	if ((n*m) & 1)
		imp();
	if (n&1)
		fard_zoj();
	else if (m&1)
		zoj_fard();
	else
		zoj_zoj(n,m);
	print ();
	return 0;
}