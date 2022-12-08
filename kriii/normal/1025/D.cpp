#include <stdio.h>

int N,A[707]; bool g[707][707];

int gcd(int a, int b)
{
	return b ? gcd(b,a%b) : a;
}

bool chk[2][707][707],res[2][707][707];

bool can(int k, int s, int e)
{
	if (s > e) return true;
	if (chk[k][s][e]) return res[k][s][e];
	chk[k][s][e] = 1;
	bool &r = res[k][s][e];
	int p = (k == 0 ? s-1 : e+1);
	for (int i=s;i<=e;i++) if (g[p][i]){
		if (can(1,s,i-1) && can(0,i+1,e)){
			r = 1;
			break;
		}
	}
	return r;
}

int main()
{
	scanf ("%d",&N);
	for (int i=1;i<=N;i++) scanf ("%d",&A[i]);
	for (int i=0;i<=N+1;i++) for (int j=0;j<=N+1;j++) g[i][j] = gcd(A[i],A[j]) != 1;

	puts(can(0,1,N)?"Yes":"No");

	return 0;
}