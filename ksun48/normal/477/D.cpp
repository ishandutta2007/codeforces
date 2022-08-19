#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL MOD = 1000000007;
LL numseq[5001][5001];
LL sum[5001][5001];
int check[5001][5001];
int main(){
	string k;
	cin >> k;
	LL n = k.size();
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			check[i][j] = -1;
		}
	}
	for(int i = 1; i < n; i++){
		int j = 0;
		int counter = 0;
		while(j + i < n){
			if(k[j] == k[j+i]){
				counter++;
				if(counter >=i){
					check[j+1-i][i] = 1;
					//cout << j+1-i << " " << i << endl;
				}
			} else if(k[j+i] == '1' && k[j] == '0'){
				for(int r = 0; r <= min(counter, i); r++){
					check[j-r][i] = 1;
					//cout << j-r << " " << i << endl;
				}
				counter = 0;
			} else {
				counter = 0;
			}
			j++;
		}
	}

	//int same[n+1][n+1];

	//numseq[i][j] = the number of ways to get to character i, with the last one being j characters.
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			sum[i][j] = numseq[i][j] = 0;
		}
	}
	numseq[0][0] = 1;
	for(int i = 0; i <= n; i++){
		sum[0][i] = 1;
	}
	for(int i = 1; i <= n; i++){
		sum[i][0] = 0;
		for(int j = 1; j <= i; j++){
			numseq[i][j] += sum[i-j][j-1];
			numseq[i][j] %= MOD;
			if(i >= 2*j && check[i-2*j][j] == 1){
				numseq[i][j] += numseq[i-j][j];
				numseq[i][j] %= MOD;
			}
			//cout << numseq[i][j] << " ";
			if(k[i-j] == '0'){
				numseq[i][j] = 0;
			}
		}
		for(int j = 1; j <= n; j++){
			sum[i][j] = numseq[i][j] + sum[i][j-1];
			sum[i][j] %= MOD;
		}
		//cout << endl;
	}
	cout << sum[n][n] << endl;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			numseq[i][j] = 100000;
			sum[i][j] = 100000;
		}
	}
	numseq[0][0] = 0;
	for(int i = 0; i <= n; i++){
		sum[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		sum[i][0] = 100000;
		for(int j = 1; j <= i; j++){
			numseq[i][j] = 1 + sum[i-j][j-1];
			if(i >= 2*j && check[i-2*j][j] == 1){
				numseq[i][j] = 1 + sum[i-j][j];
			}
			if(k[i-j] == '0'){
				numseq[i][j] = 100000;
			}
		}
		for(int j = 1; j <= n; j++){
			sum[i][j] = min(numseq[i][j], sum[i][j-1]);
		}
	}

	LL pow2[10000];
	pow2[0] = 1;
	for(int i = 1; i < 10000; i++){
		pow2[i] = (pow2[i-1]*2) % MOD;
	}
	for(int i = 1; i <= n; i++){
		//cout << numseq[n][i] << endl;
	}
	LL num = 0;
	LL answer = MOD;
	for(int i = n-1; i >= 0; i--){
		if(k[i] == '1') num += pow2[n-1-i];
		num %= MOD;
		//cout << num << endl;
		if(n-i == 21 && answer < MOD){
			cout << answer << endl;
			exit(0);
		}
		if(n-i <= 20 && numseq[n][n-i] < 10000){
			answer = min(answer, num+numseq[n][n-i]);
		} else {
			if(numseq[n][n-i] < 10000){
				cout << (numseq[n][n-i] + num) % MOD << endl;
				exit(0);
			}
		}
	}
	cout << answer << endl;


}