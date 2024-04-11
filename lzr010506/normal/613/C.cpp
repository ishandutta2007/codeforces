#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int A[N],n;
int gcd(int a, int b)
{
	if(a < b) swap(a, b);
	while(b)
	{
		int c = b;
		b = a % b;
		a = c;
	}
	return a; 
}

int B[N];

int main()
{
	scanf("%d",&n);
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d",&A[i]),ans = gcd(ans,A[i]);
		cnt += A[i] & 1;
	}
	if (cnt > 1)
	{
		printf("%d\n",0);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= A[i]; j ++) printf("%c", 'a' + i - 1);
		return 0;
	}

	cnt = 0;
	for (int i = 1; i <= n; i ++) A[i] /= ans, cnt += A[i] & 1;
	int c = 1;
	if (cnt > 1)
	{
		ans /= 2; 
		c = 2;
		for (int i = 1; i <= n; i ++) A[i] <<= 1;
	}
	int m = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= A[i]; j ++)
			m ++;
	int l = 1, r = m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= A[i] / 2; j ++)
			B[l ++] = i, B[r --] = i;
	for (int i = 1; i <= n; i ++)
		if (A[i] & 1) 
			B[l ++] = i;
	printf("%d\n",ans * c);
	for (int zz = 1; zz <= ans; zz ++)
		for (int i = 1; i <= m; i ++)
			printf("%c",'a' + B[i] - 1);
	return 0; 
}