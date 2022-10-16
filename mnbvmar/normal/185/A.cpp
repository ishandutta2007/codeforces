#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL Mod = 1000000007;

LL N;
LL matrix[2][2];
LL curMul[2][2], resMat[2][2];


void input(){
	cin >> N;
}


int main(){
	input();
	matrix[0][0] = matrix[1][1] = 3;
	matrix[1][0] = matrix[0][1] = 1;

	resMat[0][0] = resMat[1][1] = 1;

	for(int i = 0; i < 63; i++){
		LL tmp[2][2] = {{0,0},{0,0}};

		if(N & (1LL<<i)){
			for(int a = 0; a < 2; a++)
				for(int b = 0; b < 2; b++)
					for(int c = 0; c < 2; c++){
						tmp[a][c] = (tmp[a][c]+resMat[a][b]*matrix[b][c]) % Mod;
					}

			for(int a = 0; a < 2; a++) for(int b = 0; b < 2; b++){
				resMat[a][b] = tmp[a][b];
				tmp[a][b] = 0;
			}
		}

		for(int a = 0; a < 2; a++)
			for(int b = 0; b < 2; b++)
				for(int c = 0; c < 2; c++)
					tmp[a][c] = (tmp[a][c] + matrix[a][b]*matrix[b][c]) % Mod;
		
		for(int a = 0; a < 2; a++) for(int b = 0; b < 2; b++) matrix[a][b] = tmp[a][b];
	}

	cout << resMat[0][0] << endl;
}