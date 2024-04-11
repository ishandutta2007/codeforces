#include <stdio.h>

int N,K; char O[100100];
int P[100100],C;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	scanf ("%d %d %s",&N,&K,&O);
	for (int i=0;O[i];i++) if (O[i] == '0') P[C++] = i;
	int ans = 1000000;
	for (int i=K,j=0;i<C;i++){
		if (j < i-K) j = i-K;
		ans = min(ans,max(P[i]-P[j],P[j]-P[i-K]));
		while (j < i && max(P[i]-P[j],P[j]-P[i-K]) > max(P[i]-P[j+1],P[j+1]-P[i-K])){
			j++;
			ans = min(ans,max(P[i]-P[j],P[j]-P[i-K]));
		}
		j--;
	}
	printf ("%d\n",ans);

	return 0;
}