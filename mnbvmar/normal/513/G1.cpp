#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


const int MaxN = 6,
	      MaxK = 4;

int tab[MaxN];
int ntab[MaxN];
int l[MaxK], r[MaxK];
int N, K;

void input(){
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &tab[i]);
}

int sumInv;

void check(){
	copy(tab, tab+N, ntab);

	for(int i = 0; i < K; i++){
		reverse(ntab+l[i], ntab+r[i]+1);
	}

//	printf("%d %d -> ", l[0], r[0]);
//	for(int i = 0; i < N; i++) printf("%d ", ntab[i]);
//	printf("\n");

	for(int i = 0; i < N; i++)
		for(int j = i+1; j < N; j++)
			if(ntab[i] > ntab[j]) sumInv++;
}

void brute(int i){
	if(i == K){ check(); return; }

	for(int a = 0; a < N; a++)
		for(int b = a; b < N; b++){
			l[i] = a;
			r[i] = b;
			brute(i+1);
		}
}

int main(){
	input();
	sumInv = 0;
	brute(0);

	double result = sumInv;
	for(int i = 0; i < K; i++)
		result /= N*(N+1)/2;

	printf("%.12lf\n", result);
}