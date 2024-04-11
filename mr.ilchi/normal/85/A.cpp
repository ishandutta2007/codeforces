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
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
typedef long double ldb;
typedef long long ll;

char mat[10][200];
int n;

int main(){

	cin >> n;

	if (n==1){

		cout << "a\na\nb\nb" << endl;
		return 0;
	}

		
		for (int j=2;j<n;j+=2){
			
			if (j%4==2){
				mat[1][j]= mat[1][j+1]= 'a';
				mat[2][j]= mat[2][j+1]= 'b';
			}

			else{
				mat[1][j]= mat[1][j+1]= 'b';
				mat[2][j]= mat[2][j+1]= 'a';
			}
		}

		for (int j=1;j<n;j+=2){
			
			if (j%4==1){
				mat[3][j]= mat[3][j+1]= 'c';
				mat[4][j]= mat[4][j+1]= 'd';
			}

			else{
				mat[3][j]= mat[3][j+1]= 'd';
				mat[4][j]= mat[4][j+1]= 'c';
			}
		}

		if (n%2==0){
			mat[1][1]= mat[2][1]= 'x';
			mat[1][n]= mat[2][n]= 'y';
		}

		else{
			mat[1][1]= mat[2][1]= 'x';
			mat[3][n]= mat[4][n]= 'y';
		}

	
	for (int i=1;i<=4;i++){
		for (int j=1;j<=n;j++)
			cout << mat[i][j];
		cout << endl;
	}

	return 0;
}