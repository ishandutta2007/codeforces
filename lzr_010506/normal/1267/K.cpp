#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100], b[100];
LL C[30][30];
int cnt;

int main()
{
	for(int i=0; i<30; ++i)
	{
		C[i][0] = 1;
		for(int j=1; j<=i; ++j)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL n;
		cnt = 1;
		scanf("%I64d", &n);
		
		for(int i=0; i<=80; ++i)
			b[i] = 0;
		
		for(int i=2; n; ++i)
		{
			a[++cnt] = n % i;
			b[n % i]++;
			n /= i;
		}
		
	//	cout << cnt << "..\n";
		
		LL s1 = 1, s2 = 1, s = 0;
		for(int i=cnt-1; i; --i)
		{
			s1 *= C[cnt-i-s][b[i]];
			s += b[i];
		}
		s = 0;
		for(int i=cnt-1; i; --i)
		{
			s2 *= C[cnt-i-1-s][b[i]];
			s += b[i];
		}
		printf("%I64d\n", s1 - s2 - 1);
	}
}