#include <iostream>
using namespace std;


const long long mod = 1e9 + 9;



struct Matr
{
	long long a[2][2];
	Matr() { memset(a, 0, sizeof a); }
	Matr operator + (Matr A)
	{
		Matr ans = Matr();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				ans.a[i][j] = (a[i][j] + A.a[i][j] ) % mod;
		return ans;
	}
	Matr operator * (Matr A)
	{
		Matr ans = Matr();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int h = 0; h < 2; h++)
				{
					ans.a[i][j] += a[i][h] * A.a[h][j];
					ans.a[i][j] %= mod;
				}
		return ans;
	}
	static Matr one()
	{
		Matr ans = Matr();
		ans.a[0][0] = ans.a[1][1] = 1;
		return ans;
	}
};


Matr fpow(Matr M, long long n)
{
	if (n == 0)
		return Matr::one();
	Matr A = fpow(M, n >> 1);
	A = A * A;
	if (n & 1)
		A = A * M;
	return A;
}

int main()
{

	long long n, m, k;
	scanf("%I64d%I64d%I64d", &n, &m, &k);

	long long wrong = n - m;

	long long maxWrong = (n + 1 + k - 1) / k - 1;

	if (wrong >= maxWrong)
	{
		printf("%I64d", m);
		return 0;
	}
	
	long long ans = wrong * (k - 1);
	n -= wrong * k;
	m = n;

	long long fullBlocks = n / k;
	long long rem = n % k;

	Matr M = Matr();
	M.a[0][0] = 2;
	M.a[0][1] = 0;

	M.a[1][0] = 2;
	M.a[1][1] = 1;

	M = fpow(M, fullBlocks);

	ans = k * M.a[1][0] + ans + rem;

	printf("%I64d", ans % mod);

	return 0;
}