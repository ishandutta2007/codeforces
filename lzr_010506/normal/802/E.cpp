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
	cout << P;
	return (int)floor(x * (2 * P + 1));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		memset(a, 0, sizeof a);
		db sum = 0;
		int Mx = 0;
		for (int i = 0; i < N; i ++)
		{
			scanf("%d", a + i);
			sum += a[i];
			Mx = max(a[i], Mx);
		}
		sum /= (double)N;
		db fangcha = 0;
		for (int i = 0; i < N; i ++)
			fangcha += sqr(a[i] - sum);
		fangcha /= N;
		if(fangcha < 2 * sum) cout<<int(sum + 0.5) << endl;
		else cout<<int((double)Mx / 2.0 + 0.5)<<endl;

		//if (fangcha < 2 * sum) printf("%d", P);
		//else printf("%d", P);

	}
	return 0;
}