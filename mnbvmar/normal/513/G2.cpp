#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 35,
	      MaxK = 205;

int tab[MaxN];
int ntab[MaxN];
int l[MaxK], r[MaxK];
int N, K;

void input(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &tab[i]);
}

double dp[MaxK][MaxN][MaxN];


int main(){
	input();
	
	// step = 0
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			dp[0][i][j] = (tab[i] > tab[j]) ? 1. : 0.;


	double coef = 1. / (N*(N+1)/2);
	// next steps
	for(int step = 1; step <= K; step++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				for(int Lchg = 0; Lchg < N; Lchg++){
					for(int Rchg = Lchg; Rchg < N; Rchg++){
						int newI = i, newJ = j;

						if(Lchg <= i && i <= Rchg){
							newI = Lchg+Rchg-i;
						}
						if(Lchg <= j && j <= Rchg){
							newJ = Lchg+Rchg-j;
						}

						dp[step][i][j] += coef*dp[step-1][newI][newJ];
					}
				}
			}
		}
	}

	double result = 0;
	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			result += dp[K][i][j];

	printf("%.12lf\n", result);
}