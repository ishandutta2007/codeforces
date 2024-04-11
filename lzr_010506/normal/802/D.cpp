#include <bits/stdc++.h>
using namespace std;
#define db double
#define N 250
int a[N];

inline db sqr(db x) 
{
	return x * x;
}

inline int rand1(int P) 
{
	db sum = 0;
	db x = (db)rand() / RAND_MAX;
	db frac = 1;
	for (int k = 0; k <= 2 * P; k ++) 
	{
		if (k) frac *= k;
		sum += (pow(P, k) * exp(-P)) / frac;
		if (x <= sum) return k;
	}
	return 2 * P;
}

inline int rand2(int P) 
{
	db x = (db)rand() / RAND_MAX;
	return (int)floor(x * (2 * P + 1));
}

int main(void) 
{
	int T;
	scanf("%d", &T);
	while (T --) 
	{
		memset(a, 0, sizeof a);
		db sum = 0;
		for (int i = 0; i < N; i ++) 
		{
			scanf("%d", a + i);
			sum += a[i];
		}
		sum /= N;
		db fangcha = 0;
		for (int i = 0; i < N; i ++) 
			fangcha += sqr(a[i] - sum);
		fangcha /= N;
		if (fangcha < 2 * sum) puts("poisson");
		else puts("uniform");
	}
	return 0;
}