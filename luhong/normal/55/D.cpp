#include <cstdio>
#include <iostream>

int T;
long long f[20][2520][50];
int m = 0;
int id[2520];
int r[50], mi[20];
int lcm[2521][2521];

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

long long solve(long long x)
{
	int d[20], tot = 0;
	while(x) {d[++tot] = x % 10; x /= 10;}
	int o = 1, k = 0;
	long long ans = 0;
	for(int i = tot; i >= 1; i--)
	{
		for(int j = 0; j < d[i]; j++)
		{
			int kk = (k + j * mi[i]) % 2520;
			int oo = o;
			if(j) oo = lcm[o][j];
			for(int K = 0; K < 2520; K++)
				for(int O = 1; O <= m; O++)
				{
					int OO = lcm[oo][r[O]];
					if((K + kk) % OO == 0)
					{
						ans += f[i - 1][K][O];
					}
				}
		}
		k = (k + d[i] * mi[i]) % 2520;
		if(d[i]) o = lcm[o][d[i]];
	}
	return ans;
}

int main()
{
	for(int i = 0; i <= 2520; i++)
		for(int j = 0; j <= 2520; j++) 
			if(i && j) lcm[i][j] = i * j / gcd(i, j); 
			
	for(int S = 0; S < (1 << 10); S++)
	{
		int L = 1;
		for(int i = 1; i < 10; i++)
			if((S >> i) & 1) L = lcm[L][i];
		if(!id[L]) id[L] = ++m, r[m] = L;
	}
	
	mi[1] = 1; for(int i = 2; i < 20; i++) mi[i] = mi[i - 1] * 10 % 2520;
	
	f[0][0][1] = 1;
	for(int i = 1; i <= 19; i++)
		for(int k = 0; k < 2520; k++)
			for(int o = 1; o <= m; o++)
				for(int j = 0; j <= 9; j++)
				{
					int oo = r[o];
					if(j) oo = lcm[oo][j];
					oo = id[oo];
					int kk = (k + j * mi[i]) % 2520;
					f[i][kk][oo] = f[i][kk][oo] + f[i - 1][k][o];
				}
	scanf("%d", &T);
	while(T--)
	{
		long long l, r; scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r + 1) - solve(l));
	}
}

// f[i][j][k]i1~9...1~9
//f[i][j][k]i%2520jlcmk