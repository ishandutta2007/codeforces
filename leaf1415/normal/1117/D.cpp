#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, m;
llint mat[105][105];

void ident(llint a[105][105])
{
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i==j) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
}

llint mul(llint a[105][105], llint b[105][105], llint c[105][105]){
	llint tmp[105][105];
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			tmp[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= m; k++){
				tmp[i][j] += a[i][k] * b[k][j] % mod;
				tmp[i][j] %= mod;
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			c[i][j] = tmp[i][j];
		}
	}
}

void modpow(llint a[105][105], llint n, llint b[105][105])
{
	if(n == 0) ident(b);
	else{
		llint tmp[105][105];
		if(n%2){
			modpow(a, n-1, tmp);
			mul(a, tmp, b);
		}
		else{
			modpow(a, n/2, tmp);
			mul(tmp, tmp, b);
		}
	}
}


int main(void)
{
	cin >> n >> m;
	
	mat[1][1] = mat[1][m] = 1;
	for(int i = 2; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i-1 == j) mat[i][j] = 1;
		}
	}
	
	modpow(mat, n, mat);
	
	cout << mat[1][1] << endl;
	
	return 0;
}