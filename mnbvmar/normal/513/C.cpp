#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 5;
const int MaxVal = 10000;

int N;
int L[MaxN], R[MaxN];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d%d", &L[i], &R[i]);
	}
}

double get_prob(int val){
	int taken[MaxN];

	double result = 0;

	for(int i = 0; i < (1<<N); i++){
		for(int j = 0; j < N; j++)
			taken[j] = (i & (1<<j)) != 0;

		int numTaken = 0;
		for(int j = 0; j < N; j++)
			if(taken[j]) numTaken++;

		if(numTaken < 2) continue;

		// only same
		double prob = 1;
		for(int j = 0; j < N; j++)
			if(!taken[j])
				prob *= min(1., max(0., (double)(val-L[j]) / (R[j]-L[j]+1)));
			else if(L[j] <= val && val <= R[j])
				prob *= min(1., max(0., (double)1 / (R[j]-L[j]+1)));
			else
				prob = 0;

		result += prob;
//		printf("i=%d res=%lf\n", i, result);

		// exactly one strictly bigger
		for(int big = 0; big < N; big++){
			if(!taken[big]) continue;
			prob = 1;

			for(int j = 0; j < N; j++){
				if(j == big)
					prob *= min(1., max(0., (double)(R[j]-val) / (R[j]-L[j]+1)));
				else if(!taken[j])
					prob *= min(1., max(0., (double)(val-L[j]) / (R[j]-L[j]+1)));
				else if(L[j] <= val && val <= R[j])
					prob *= min(1., max(0., (double)1 / (R[j]-L[j]+1)));
				else
					prob = 0;
			}

//			printf("big=%d prob=%lf\n", big, prob);
			result += prob;
		}
//		printf("i=%d res=%lf\n", i, result);
	}
//	printf("%d -> %lf\n", val, result);

	return result;
}

int main(){
	input();
	double result = 0;

//#warning size
	for(int val = 1; val <= MaxVal; val++){
		result += val * get_prob(val);
	}

	printf("%.12lf\n", result);
}